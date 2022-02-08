#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
bool visited[10001];
vector<string> answer;
// 완전탐색 - DFS
bool DFS(string here, vector<vector<string> > tickets, int cntUse){
    answer.push_back(here);
    if(cntUse==tickets.size()) return true;     // 모든 티켓사용하여, 끝까지 도달함.
    for (int i = 0; i < tickets.size(); i++) {
        if(tickets[i][0]==here && !visited[i]){
            visited[i]=true;                                    // 일단 성공여부와 무관하게 방문처리
            bool how = DFS(tickets[i][1],tickets, cntUse+1);    // 선택한 다음행 비행기가 성공적인가?
            if(how == true) return true;
            visited[i]=false;       // 다음으로 갈수없다면, 다시 미방문처리해주기.
        }
    }
    answer.pop_back();  // here에서 출발하는 티켓이 없는 경우, 들어왔던 것을 빼주고 이전으로 돌아감
    return false;
}
vector<string> solution(vector<vector<string> > tickets) {
    memset(visited,false,sizeof(visited));
    sort(tickets.begin(),tickets.end());
    DFS("ICN", tickets, 0);    // 인천행부터 시작
    
    return answer;
}