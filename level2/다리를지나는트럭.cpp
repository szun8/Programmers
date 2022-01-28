#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

int curWeights = 0;
class Truck{
public:
    int weight,time;
};
deque<Truck> truck;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1, i=0;
    Truck newTruck;                 // 일단 처음은 무조건 가능!!
    curWeights+=truck_weights[i];   // 현재 다리에 올라간 트럭들의 무게
    newTruck.time=1; newTruck.weight=truck_weights[i++];
    truck.push_back(newTruck);

    while (!truck.empty()) {   // 대기중인 트럭이 없을때까지.
        ++answer;                                   // 매 케이스마다 횟수 증가처리
        if(truck.front().time == bridge_length){    // 다리의 끝에 도달하면,
            curWeights-=truck.front().weight;       // 다리에 올라간 트럭들의 무게 차감
            truck.pop_front();                      
        }
        if(i<=truck_weights.size()-1 && truck_weights[i]+curWeights <= weight && truck.size()+1 <= bridge_length){
            // 다리에 대기중인 다음 트럭이 들어갈 수 있다면,
            if(!truck.empty()) {    // 현재 다리위에 있는 트럭들을 1칸 전진시켜준 뒤,
                for (int j = 0; j < truck.size(); j++) truck[j].time++;
            }
            curWeights+=truck_weights[i];   // 트럭 한개 다리로 옮겨주기
            newTruck.time=1; newTruck.weight=truck_weights[i++];
            truck.push_back(newTruck);
        }
        else if(!truck.empty()){    // 해당 조건을 해주지 않으면 무조건 else라, 비어있는 truck를 건드리게됨!!
            // 1칸씩 전진하는 코드가 아닌(시간초과됨) 앞으로 전진해야하는 상황일 시, 바로 다리의 끝으로 옮겨주는 코드로 시간 단축
            int sumLength = bridge_length-truck.front().time;
            answer+=sumLength;  // 옮겨진 만큼 케이스횟수도 더하기
            for (int j = 0; j < truck.size(); j++) truck[j].time+=sumLength;

            if(truck.front().time == bridge_length) {
                curWeights-=truck.front().weight;
                truck.pop_front();
                if(!truck.empty()) {
                    for (int j = 0; j < truck.size(); j++) truck[j].time++;
                }
                if(i<=truck_weights.size()-1 && truck_weights[i]+curWeights <= weight && truck.size()+1 <= bridge_length){
                    curWeights+=truck_weights[i];
                    newTruck.time=1; newTruck.weight=truck_weights[i++];
                    truck.push_back(newTruck);
                }
            }
        }
    }
    return answer;
}

int main(){
    vector<int> truck_weights;
    truck_weights.push_back(2);
    truck_weights.push_back(2);
    truck_weights.push_back(2);
    truck_weights.push_back(2);
    truck_weights.push_back(1);
    truck_weights.push_back(1);
    truck_weights.push_back(1);
    truck_weights.push_back(1);
    truck_weights.push_back(1);
    solution(5,5,truck_weights);
    return 0;
}