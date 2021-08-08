#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long long n = num;
    int answer = 0;
    while (n != 1) {  // 1이 될때까지 돌려주기
        if (answer >= 500)
            return -1;

        if (n % 2 == 0) {    // if Even,
            n /= 2;
            answer++;
        }
        else if (n % 2 == 1) {    // if Odd,
            n = (n * 3) + 1;
            answer++;
        }
    }
    return answer;
}

int main() {
    solution(6);
    return 0;
}