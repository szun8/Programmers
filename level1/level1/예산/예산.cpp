#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 작은 수부터 더해주기 + 더해주고 나서 예산 넘는지 확인하는 절차
int solution(vector<int> d, int budget) {
    int answer = 0;
    int addD = 0;
    int count = 0;
    priority_queue<int, vector<int>, greater<int>> dQ;  //오름차순
    for (int i = 0; i < d.size(); i++) {
        dQ.push(d.at(i));
        //이러면 작은 수부터 저장
    }

    for (int i = 0; i < d.size(); i++) {
        int addBudget = dQ.top();
        dQ.pop();
        addD += addBudget;
        ++count;
        if (addD == budget) {
            return answer = count;
        }
        else if (addD > budget) {
            return answer = --count;
        }
        // 작으면, 계속 반복문 돌다가 다 더했는데도 예산이 남는다면 그것을 리턴
    }
    return answer = count;
}

int main() {
    vector<int> d = { 2,2,3,3 };
    int budget = 10;
    solution(d, budget);

    return 0;
}
