#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int answer = 0;
// 주어진 numbers 순서는 고정.
// 완전탐색 (접근인덱스, vector<int> numbers, 현재까지의 합, target)
void DFS(int here, vector<int> numbers, int sum, int target){
    if(sum==target && here == numbers.size()-1) {   // 모든 수를 사용해서 target에 도달하면,
        ++answer;
        return;
    }
    else if(here == numbers.size()-1) return ;        // 마지막 도달시 탈출
    DFS(here+1,numbers,sum+numbers[here+1],target);   // 다음 수 +
    DFS(here+1,numbers,sum-numbers[here+1],target);   // 다음 수 -
}
int solution(vector<int> numbers, int target) {
    DFS(-1,numbers,0,target);
    return answer;
}