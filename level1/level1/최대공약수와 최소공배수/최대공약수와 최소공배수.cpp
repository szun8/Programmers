#include <string>
#include <vector>

using namespace std;
vector<int> max(int n) {
    vector<int> num;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) 
            num.push_back(i);
    }
    return num;
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    vector<int> N = max(n);
    vector<int> M = max(m);

    // 최대 공약수 찾기!
    for (int i = 1; i < N.size(); ++i) {
        for (int j = 1; j < M.size(); ++j) {
            if (N[i] == M[j]) {
                answer.push_back(N[i]);
                i = N.size();
                break;
            }  
        }
    }
    // 최대 공약수 없으면, 1 넣기
    if (answer.empty()) answer.push_back(1);

    //최소 공배수 찾기!
    if (m % n == 0) {
        answer.push_back(m);
    }
    else if (n % m == 0) {
        answer.push_back(m);
    }
    else
        answer.push_back(m*n);

    return answer;
}

int main() {
    solution(3, 12);
    return 0;
}