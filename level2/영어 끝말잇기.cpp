#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> battleWords;
    battleWords.push_back(words[0]);    // 첫번쨰 단어는 비교상관없이 push
    for (int i = 1; i < words.size(); i++) {
        if(words[i-1].back() != words[i].front()){  // 현 문자의 끝spell과 다음 단어의 첫spell이 다른 경우.
            int who = (i+1)%n;  
            who==0 ? answer.push_back(n) : answer.push_back(who);
            if((i+1)%n == 0){
                int cnt = (i+1)/n;
                answer.push_back(cnt);
            }
            else {
                int cnt = (i+1)/n + 1;
                answer.push_back(cnt);
            }
            break;
        }
        else if(find(battleWords.begin(),battleWords.end(),words[i])!=battleWords.end()){
            // 만약 중복단어가 있다면,
            int who = (i+1)%n;  
            who==0 ? answer.push_back(n) : answer.push_back(who);
            if(((i+1)%n) == 0){
                int cnt = (i+1)/n;
                answer.push_back(cnt);
            }
            else {
                int cnt = (i+1)/n + 1;
                answer.push_back(cnt);
            }
            break;
        }
        else if(words[i].size()==1){    // 단어의 길이가 1인 경우는 단어가 아님.
            int who = (i+1)%n;  
            who==0 ? answer.push_back(n) : answer.push_back(who);
            if(((i+1)%n) == 0){
                int cnt = (i+1)/n;
                answer.push_back(cnt);
            }
            else {
                int cnt = (i+1)/n + 1;
                answer.push_back(cnt);
            }
            break;
        }
        else battleWords.push_back(words[i]);   // 그 경우가 아니라면, 단어 삽입
    }
    
    if(answer.empty()) {    // 아무도 틀린 경우가 없을 경우.
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}