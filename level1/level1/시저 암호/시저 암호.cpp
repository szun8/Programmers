#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == 32) {
            answer += s.at(i);
        }
        // 대문자
        if (s.at(i) > 64 && s.at(i) < 91) {
            if ((s.at(i) + n) < 91 && (s.at(i) + n) > 64) {
                s.at(i) += n;
                answer += s.at(i);
            }
            else {
                s.at(i) += (n - 26);
                answer += s.at(i);
            }
        }

        // 소문자
        if (s.at(i) > 96 && s.at(i) < 123) {
            if ((s.at(i) + n) < 123 && (s.at(i) + n) > 96) {
                s.at(i) += n;
                answer += s.at(i);
            }
            else {
                s.at(i) += (n - 26);
                answer += s.at(i);
            }
        }
    }
    return answer;
}

int main() {
    solution("AaZz", 25); // ZzYy
    return 0;
}