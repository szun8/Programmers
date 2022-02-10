#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool findSkill(string skill, string curSkill){
    vector<int> order;      // curSkill에 있는 skill의 인덱스를 저장
    for (int i = 0; i < skill.size(); i++){
        int index = find(curSkill.begin(),curSkill.end(),skill[i])-curSkill.begin();
        if(index<curSkill.size()) order.push_back(index);   // 만약 없으면 통과
    }
    sort(order.begin(),order.end());    // 인덱스순으로 정렬후 skill나열
    string what = "";
    for (int i = 0; i < order.size(); i++){
        what+=curSkill[order[i]];
    }
    
    for (int i = 0; i < what.size(); i++) {     // 선행스킬순을 어긴다면, false
        if(what[i]!=skill[i]) return false;
    }
    return true;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (int i = 0; i < skill_trees.size(); i++) {
        if(findSkill(skill,skill_trees[i])) ++answer;
    }
    return answer;
}