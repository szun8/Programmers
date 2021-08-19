#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0)
            answer += i;
    }
    return answer;
}

int main() {
    cout<<sqrt(3);
    solution(3);
    return 0;
}