#include <string>
#include <vector>

using namespace std;
// '0' = ASCII(48) ~ '9' = ASCII(57)

bool solution(string s) {
    bool answer = true;
    // 항상 문제 조건 잘보기!!!

    // 1) 길이조건
    if (s.size() == 4 || s.size() == 6);
    else
        return false;

    // 2) 숫자조건
    for (int i = 0; i < s.size(); i++) {
        // isdight(s[i])
        // 라는 것으로 조건 생성가능

        if (s[i] > 58 || s[i] < 47) {
            return false;
        }
    }
    return answer;
}

int main() {
    string s = "a234";
    solution(s);
    return 0;
}