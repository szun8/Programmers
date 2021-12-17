#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

bool visited[51];   // false = 미방문, true = 방문
vector<int> Time;
// 특정마을에서 마을1에 가는 경로를 탐색하는 순으로 조건 검색
void dfs(vector<pair<int,int> > graph[], int start, int k, int times, int hours){
    // start = 시작지점, times = 이전마을에서 해당마을로 오기까지의 거리, hours = 시작마을부터 이전마을까지 이동한 거리
    visited[start]=true;
    int Hours= hours+times; // 시작마을부터 해당마을까지의 이동거리
    if(Hours>k){    // 배달시간이 요구조건보다 더 걸림
        visited[start]=false;
        return ;
    }
    else if(start==1) {
        Time.push_back(Hours);
        visited[start]=false;
        return ;
    }
    for (int i = 0; i < graph[start].size(); i++) {
        if(Time.size()>0) break;    // 하나라도 갈수있는 경로가 있다면 반복문 빠져나오기
        if(visited[graph[start][i].first]==false) { 
            dfs(graph, graph[start][i].first, k, graph[start][i].second, Hours);
            // 다음 마을을 갈수있다면, 거기로 가기
        }
    }
    visited[start]=false;
    // 다른 경우의 수에서 해당마을을 방문할수 있게 한 경우가 끝나면 미방문처리하기
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<pair<int,int> > graph[N+1]; // 연결된 노드, 가는 시간
    for (int i = 0; i < road.size(); i++) { 
        graph[road[i][0]].push_back(pair<int,int>(road[i][1],road[i][2]));
        graph[road[i][1]].push_back(pair<int,int>(road[i][0],road[i][2]));
    }
    for (int i = 2; i <= N; i++) {
        memset(visited,false,sizeof(visited));
        Time.clear();
        dfs(graph,i, K, 0, 0); // 마을i에서 마을1 가는 방법 순회 시작
        answer+=Time.size();
    }
    return answer+1;
}

int main(){
    vector<vector<int> > road(7);
    road[0].push_back(1);
    road[0].push_back(2);
    road[0].push_back(1);

    road[1].push_back(1);
    road[1].push_back(3);
    road[1].push_back(2);

    road[2].push_back(2);
    road[2].push_back(3);
    road[2].push_back(2);

    road[3].push_back(3);
    road[3].push_back(4);
    road[3].push_back(3);

    road[4].push_back(3);
    road[4].push_back(5);
    road[4].push_back(2);

    road[5].push_back(3);
    road[5].push_back(5);
    road[5].push_back(3);

    road[6].push_back(5);
    road[6].push_back(6);
    road[6].push_back(1);

    solution(6, road, 4);

    return 0;
}