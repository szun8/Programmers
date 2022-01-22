#include <string>
#include <iostream>
#include <vector>
#include <algorithm>    // find_if
using namespace std;
class Path{ 
public:
    int dx,dy,ax,ay;    // 좌표저징 d = departure && a = arrival
};
int curX=0,curY=0,nextX=0,nextY=0;
bool isHere(Path path){
    // 지나온 길인지 아닌지 검사
    if(path.dx==curX && path.dy==curY && path.ax==nextX && path.ay==nextY){
        // 출발->도착 좌표가 같을 경우
        return true;
    }
    else if(path.dx==nextX && path.dy==nextY && path.ax==curX && path.ay==curY){
        // 도착->출발 좌표가 같을 경우
        return true;
    }
    else return false;  // 그외의 경우는 해당 길을 온적이 없는 경우임.
}

int solution(string dirs) {
    int answer = 0;
    vector<Path> path;      // departure, arrival로 각 좌표 저징
    for (int i = 0; i < dirs.size(); i++) {     // 좌표범위구간 확인!
        if(dirs[i]=='U' && curX>=-5 && (curY+1)>=-5 && curX<6 && (curY+1)<6){
            nextY=curY+1;
            vector<Path>::iterator iter = find_if(path.begin(),path.end(),isHere);
            if(iter==path.end()){
                Path newSpot;
                newSpot.dx=curX; newSpot.dy=curY;
                newSpot.ax=nextX; newSpot.ay=nextY;
                path.push_back(newSpot);
            }
            curY+=1;
        }
        else if(dirs[i]=='D' && curX>=-5 && (curY-1)>=-5 && curX<6 && (curY-1)<6){
            nextY=curY-1;
            vector<Path>::iterator iter = find_if(path.begin(),path.end(),isHere);
            if(iter==path.end()){
                Path newSpot;
                newSpot.dx=curX; newSpot.dy=curY;
                newSpot.ax=nextX; newSpot.ay=nextY;
                path.push_back(newSpot);
            }
            curY-=1;
        }
        else if(dirs[i]=='L' && curX-1>=-5 && curY>=-5 && (curX-1)<6 && curY<6){
            nextX=curX-1;
            vector<Path>::iterator iter = find_if(path.begin(),path.end(),isHere);
            if(iter==path.end()){
                Path newSpot;
                newSpot.dx=curX; newSpot.dy=curY;
                newSpot.ax=nextX; newSpot.ay=nextY;
                path.push_back(newSpot);
            }
            curX-=1;
        }
        else if(dirs[i]=='R' && curX+1>=-5 && curY>=-5 && curX+1<6 && curY<6){
            nextX=curX+1;
            vector<Path>::iterator iter = find_if(path.begin(),path.end(),isHere);
            if(iter==path.end()){
                Path newSpot;
                newSpot.dx=curX; newSpot.dy=curY;
                newSpot.ax=nextX; newSpot.ay=nextY;
                path.push_back(newSpot);
            }
            curX+=1;
        }
    }
    return answer=path.size();
}

int main(){
    string dirs="UDURL";
    solution(dirs);

    return 0;
}