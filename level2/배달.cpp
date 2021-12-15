#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

bool visited[51];   // false = 미방문, true = 방문
vector<int> Time;

void dfs(vector<pair<int,int> > graph[], int start, int k, int times, int hours){
    visited[start]=true;
    int Hours= hours+times;
    if(Hours>k){
        visited[start]=false;
        return ;
    }
    else if(start==1) {
        Time.push_back(Hours);
        visited[start]=false;
        return ;
    }
    for (int i = 0; i < graph[start].size(); i++) {
        if(Time.size()>0) break;
        if(visited[graph[start][i].first]==false) { 
            dfs(graph, graph[start][i].first, k, graph[start][i].second, Hours);
        }
    }
    visited[start]=false;
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<pair<int,int> > graph[N+1]; // 연결된 노드, 가는 시간
    for (int i = 0; i < 7; i++) { // 무조건 길은 하나로 히고 작은 값이 들어가기
    // 입력수정하기
        graph[road[i][0]].push_back(pair<int,int>(road[i][1],road[i][2]));
        graph[road[i][1]].push_back(pair<int,int>(road[i][0],road[i][2]));
    }
    for (int i = 2; i <= N; i++) {
        memset(visited,false,sizeof(visited));
        Time.clear();
        dfs(graph,i, K, 0, 0);
        answer+=Time.size();
    }
    cout<< answer+1;
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