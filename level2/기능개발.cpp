#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    int day;
    for (int i = 0; i < progresses.size(); i++)
    {
        // 꼭 speed나누기가 자연수로 떨어질 일은 없다 -> 올림(ceil in cmath)으로 배포 일수 조정
        day=ceil(float(100-progresses[i])/speeds[i]);
        days.push_back(day);
    }
    int i=0;
    while (i<days.size())
    {
       int baepo = days[i];
       int count = 1;
       for (int j = i+1; j < days.size(); j++)
       {
           if(baepo >= days[j]) count++;
           else j=days.size();
       }
       answer.push_back(count);
       i+=count;
    }
    for (int z = 0; z < answer.size(); z++)
    {
        cout<<answer[z]<<endl;
    }
    
    return answer;
}
int main(){
    vector<int> progresses;
    progresses.push_back(96);
    progresses.push_back(94);
    
    vector<int> speeds;
    speeds.push_back(3);
    speeds.push_back(3);
    
    solution(progresses,speeds);
    return 0;
}