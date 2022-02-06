#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0, size = target.size()+1, diffTarget; // 목표단어와 시작단어의 글자수 차이

    // 목표단어가 주어진 단어들에 없다면 결론적으로 목표단어에 도달할 수 없음.
    if(find(words.begin(),words.end(),target)==words.end()) return 0;

    vector<string> spell[size];    // 시작 단어와 Words내의 단어가 서로 몇글자 다른지 저장
    for (int i = 0; i < words.size(); i++) {
        int diffCnt = 0;
        for (int j = 0; j < words[i].size(); j++) {
            if(words[i][j]!=begin[j]) ++diffCnt;
        }
        if(words[i]==target) diffTarget = diffCnt;  // 목표단어는 배열에 저장하지 않고 그 차이수만 저장
        else spell[diffCnt].push_back(words[i]);
    }

    // 시작 단어와 목표 단어의 차이가 하나이며,
    // words안에 목표단어가 있다면 바로 변환가능이므로 answer = 1
    if(diffTarget==1) return 1;
    
    // words내에서 diffTarget와 하나 이전에 운좋게 맞는 spell의 단어가 있는지 확인 -> 있을시 한단계를 절약가능
    // 꼭 diffTarget에 맞춰 글자조합이 맞춰지는게 아닐 수 있음
    // ex. (hit) - h[o]t - [c]ot - (co[g])
    for (int i = 0; i < spell[diffTarget-1].size(); i++) {
        int diffCnt = 0;
        for (int j = 0; j < spell[diffTarget-1][i].size(); j++) {
            if(spell[diffTarget-1][i][j]!=target[j]) ++diffCnt;
        }
        if(diffCnt==1) return answer = diffTarget;
    }

    // 운이 위보다 안좋게 마지막까지 가서야 되는 조합이 있을 수 있음
    // ex. (hit) - h[o]t - [d]ot - do[g] - ([c]og)
    for (int i = 0; i < spell[diffTarget].size(); i++) {
        int diffCnt = 0;
        for (int j = 0; j < spell[diffTarget][i].size(); j++) {
            if(spell[diffTarget][i][j]!=target[j]) ++diffCnt;
        }
        if(diffCnt==1) return answer = diffTarget+1;
    }
    return answer;  // 모든 경우에도 조합이 되지 않는다면, 경우의수 존재 X = return 0;
}