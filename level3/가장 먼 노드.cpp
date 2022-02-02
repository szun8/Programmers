#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int visited[20001]; // 0 == 미방문, 이상의 상수면 초기화 (단, 상수인데 또 상수가 들어온다하면 더 적다면 갱신)

void BFS(vector<int> adj[], int start){
    memset(visited,false,sizeof(visited));
    visited[0]=-1;
    queue<int> node;
    node.push(start);
    while (!node.empty()) {
        int nextNode, curNode = node.front();
        int cnt=visited[curNode]+1;
        node.pop();
        for (int i = 0; i < adj[curNode].size(); i++) {
            nextNode = adj[curNode][i];
            if(nextNode!=1 && visited[nextNode]==0 || visited[nextNode]>cnt){
                visited[nextNode]=cnt;
                node.push(nextNode);
            }
        }
    }
}
int solution(int n, vector<vector<int> > edge) {
    int answer = 0;
    vector<int> adj[n+1];
    for (int i = 0; i < edge.size(); i++) {
        int a = edge[i][0];
        int b = edge[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n+1; i++) {
        sort(adj[i].begin(),adj[i].end());
    }
    BFS(adj, 1);
    int max = *max_element(visited,visited+n+1);
    return answer = count(visited,visited+n+1,max);
}