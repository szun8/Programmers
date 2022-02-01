#include <stack>
#include <string>
#include <deque>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = 0;
    if(s.size()%2==1) return 0; // 문자의 길이가 홀수라면 무조건 올바른 괄호 성립 불가
    deque<char> bracket;
    
    for (int i = 0; i < s.size(); i++) bracket.push_back(s[i]);
    int how = s.size();
    while (how--) {
        bool isCorrect = true;
        stack<char> correct;
        for (int j = 0; j < s.size(); j++) {
            if(bracket[j]=='{') correct.push('{');
            else if(bracket[j]=='[') correct.push('[');
            else if(bracket[j]=='(') correct.push('(');
            else if(!correct.empty() && bracket[j]=='}' && correct.top()=='{') correct.pop();
            else if(!correct.empty() &&bracket[j]==']' && correct.top()=='[') correct.pop();
            else if(!correct.empty() &&bracket[j]==')' && correct.top()=='(') correct.pop();
            else {
                isCorrect = false;
                break;
            }
        }
        if(isCorrect==true) ++answer;
        bracket.push_back(bracket.front());
        bracket.pop_front();
    }
    return answer;
}

int main(){
    solution("}{[](){}");
    return 0;
}