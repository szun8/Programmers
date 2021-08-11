#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int y = 0;
    string num = to_string(x);
    for (int i = 0; i < num.size(); i++) {
        y += (num[i] - '0');
    }
    if (x % y == 0) answer = true;
    else answer = false;

    return answer;
}