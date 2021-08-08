#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int halfSize = s.size() / 2;
    if (s.size() % 2 == 1) {    // if Odd,
        answer.push_back(s[halfSize]);
    }
    else {      // if Even,
        answer.push_back(s[halfSize-1]);
        answer.push_back(s[halfSize]);
    }   
    return answer;
}

int main() {
    solution("abcde");
    solution("qwer");
    return 0;
}