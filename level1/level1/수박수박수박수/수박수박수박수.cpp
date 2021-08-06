#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    if (n <= 0) return answer;
    answer.insert(0, "수");
    // append()

    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
            answer += "수";
        }
        else {
            answer+="박";
        }
    }
    return answer;
}

int main() {
    solution(4);
    return 0;
}