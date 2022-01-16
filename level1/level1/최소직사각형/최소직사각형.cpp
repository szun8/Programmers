#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int> > sizes) {
    int answer = 0;
    int maxW=0, maxH=0;
    for (int i = 0; i < sizes.size(); i++){
        // 현 sizes내 최대 w,h 구하기
        if(sizes[i][0]>maxW) maxW = sizes[i][0];
        if(sizes[i][1]>maxH) maxH = sizes[i][1];
    }
    if(maxW > maxH){
        // 더 큰 W을 기준으로 H 더 작게 회전해서 바꾸기
        for (int i = 0; i < sizes.size(); i++) {
            if(sizes[i][0] < sizes[i][1]){
                int tmp = sizes[i][1];
                sizes[i][1] = sizes[i][0];
                sizes[i][0] = tmp;
            }
        }
        maxH=0;
        for (int i = 0; i < sizes.size(); i++){
            if(sizes[i][1]>maxH) maxH = sizes[i][1];
        }
    }
    else{
        // 더 큰 H을 기준으로 W 더 작게 회전해서 바꾸기
        for (int i = 0; i < sizes.size(); i++) {
            if(sizes[i][0] > sizes[i][1]){
                int tmp = sizes[i][1];
                sizes[i][1] = sizes[i][0];
                sizes[i][0] = tmp;
            }
        }
        maxW=0;
        for (int i = 0; i < sizes.size(); i++){
            if(sizes[i][0]>maxW) maxW = sizes[i][0];
        }
    }

    return answer=maxW*maxH;
}

int main(){
    vector<vector<int> > sizes(5);
    sizes[0].push_back(10);
    sizes[0].push_back(7);
    sizes[1].push_back(12);
    sizes[1].push_back(3);
    sizes[2].push_back(8);
    sizes[2].push_back(15);
    sizes[3].push_back(14);
    sizes[3].push_back(7);
    sizes[4].push_back(5);
    sizes[4].push_back(15);

    solution(sizes);
    return 0;
}