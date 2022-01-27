#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    sort(scoville.begin(),scoville.end(),greater<int>());
    priority_queue<int, vector<int>, greater<int> > hot;
    if(scoville.back() < K){
        int what = scoville.back() + (scoville[scoville.size()-2]*2);
        hot.push(what);
        scoville.pop_back();
        scoville.pop_back();
        ++answer;
    }
    while (!scoville.empty()){
        hot.push(scoville.back());
        scoville.pop_back();
    }
    while (!hot.empty()) {
        if(hot.size()>=2 && hot.top() < K){
            int tmpTop = hot.top();
            hot.pop();
            int tmpNext =  hot.top();
            hot.pop();
            int tmpHot = tmpTop + (tmpNext*2);
            hot.push(tmpHot);
            ++answer;
        }
        else {
            scoville.push_back(hot.top());
            hot.pop();
        }
    }
    if(answer==0 || (scoville.size()==1 && scoville.front()<K)) answer=-1;  // 답이 나올 수 없는 경우
    return answer;
}

int main(){
    vector<int> scoville;
    scoville.push_back(1);
    scoville.push_back(2);
    // scoville.push_back(3);
    // scoville.push_back(9);
    // scoville.push_back(10);
    // scoville.push_back(12);

    int K=7;
    solution(scoville, K);
    return 0;
}