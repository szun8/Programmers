#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer ="김서방은 ";
    for (int i = 0; i < seoul.size(); i++) {
        if (seoul.at(i) == "Kim") {
            string num = to_string(i);
            // 문자열에 숫자를 더해주는 것 X 
            answer += num;
            answer += "에 있다";
        }
    }
    return answer;
}

int main() {
    vector<string> seoul{"Jane","Kim"};
    solution(seoul);
    return 0;
}