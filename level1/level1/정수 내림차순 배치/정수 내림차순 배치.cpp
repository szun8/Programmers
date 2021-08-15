#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> num;
    for (int i = 0; n > 10; i++) {
        num.push_back(n % 10);
        n/= 10;
    }
    num.push_back(n);
    sort(num.begin(), num.end());
    
    for (int i = 0; i <num.size(); i++) {
        answer += num[i]*pow(10, i);
    }
    return answer;
}

int main() {
    solution(118372);
    return 0;
}