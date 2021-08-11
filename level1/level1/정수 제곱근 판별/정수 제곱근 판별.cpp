#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long num = 1;
    while (num * num != n) {
        if (num > n) {
            answer = -1;
            return answer;
        }
        ++num;
    }
    answer = (num + 1) * (num + 1);
    return answer;
}