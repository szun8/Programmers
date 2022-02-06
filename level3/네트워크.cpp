#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int visited[201];  // 0 = 미방문 / 자연수 = 몇번 네트워크에 연결되어있는가.
int answer;
void BFS(int here, vector<vector<int> > computers){
    queue<int> network;
    network.push(here);
    visited[here]=answer;
    while (!network.empty()) {
        here = network.front(); network.pop();
        for (int there = 0; there < computers[here].size(); there++) {
            if(there!=here && visited[there]==0 && computers[here][there]==1){
                network.push(there);
                visited[there] = visited[here];
            }
        }  
    }
}

int solution(int n, vector<vector<int> > computers) {
    memset(visited,false,sizeof(visited));
    answer = 0;
    for (int i = 0; i < n; i++) {
        if(visited[i]==0) {
            ++answer;       // 달라지는 network가 시작될때마다 network counting+1;
            BFS(i, computers);
        }
    }
    return answer;
}