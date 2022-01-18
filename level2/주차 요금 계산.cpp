#include <string>
#include <vector>
#include <iostream>
#include <algorithm>    // find_if, sort
#include <cmath>        // ceil
using namespace std;

class Car {         // 들어온 차량 정보
public:
    string name, inHour, inMinute, outHour, outMinute;
    // 차량번호, 입차시, 입차분, 출차시, 출차분
    int times;      // 누적 주차시간
    bool isHere;    // 현 주차 상태
    Car(){
        isHere=false;   // 기본 out인 상태
    }
};
vector<Car> car;
string findName;
bool isName(Car car){       // 기록이 있는 차량인지 확인하는 조건 함수
    return car.name==findName;
}

bool inOrder(Car a, Car b){ // 차량번호가 작은 순으로 정렬되게 해주는 조건 함수
    return a.name < b.name;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    for (int i = 0; i < records.size(); i++) {
        int j=0;
        string hour="", minute="", name="", state="";
        while (records[i][j]!=':') {    // 입력 시
            hour+=records[i][j++];
        }
        j++;
        while (records[i][j]!=' ') {    // 입력 분
            minute+=records[i][j++];
        }
        j++;
        while (records[i][j]!=' ') {    // 차량번호
            name+=records[i][j++];
        }
        ++j;
        while (records[i][j]!='\0') {   // 입,출차 여부
            state+=records[i][j++];
        }
        if(state=="IN"){                // 입차 시,
            findName = name;
            vector<Car>::iterator iter = find_if(car.begin(),car.end(),isName);
            if(iter!=car.end()){    // 이미 한번 이상 입/출차를 한 차량이라면,
                iter->inHour=hour;
                iter->inMinute=minute;
                iter->isHere=true;
            }
            else {                  // 새로 들어온 차량이라면,
                Car newCar;
                newCar.name=name;           // 차량번호
                newCar.inHour=hour;         // 들어온 시
                newCar.inMinute=minute;     // 들어온 분
                newCar.times=0;             // 누적시간 초기화
                newCar.isHere=true;         // 주차상태 on
                car.push_back(newCar);
            }
        }
        else {  // OUT = 출차 시,
            for (int j = 0; j < car.size(); j++) {
                if(car[j].name==name){  // 출차하는 차량번호의 정보 찾기
                    car[j].outHour = hour; car[j].outMinute=minute; // 출차 시간 입력
                    int inH = stoi(car[j].inHour);
                    int inM = stoi(car[j].inMinute);
                    int outH = stoi(car[j].outHour);
                    int outM = stoi(car[j].outMinute);
                    car[j].times += (((outH-inH)*60)+outM-inM); // 주차 누적시간 기입
                    car[j].isHere=false;    // 주차상태 off
                    break;
                }
            }
        }
    }
    sort(car.begin(),car.end(),inOrder);    // 차량번호가 작은 차순으로 정렬
    for (int i = 0; i < car.size(); i++){
        if(car[i].isHere==true){            // 출차가 되지 않은 차가 있다면, 출차처리해주기
            int inH = stoi(car[i].inHour);
            int inM = stoi(car[i].inMinute);
            car[i].times+=((23-inH)*60)+(59-inM);
        }

        if(car[i].times<=fees[0]) answer.push_back(fees[1]);    // 3) 기본시간보다 적게 주차했다면, 기본요금 처리
        else{   // 2) 그 이상이라면,
            int permin = ceil(float(car[i].times-fees[0])/fees[2]); // 단위시간으로 나누기(올림처리)
            int price = fees[1]+(permin*fees[3]);
            answer.push_back(price);
        }
    }
    return answer;
}

int main(){
    vector<int> fees(4);
    // 1) [기본시간, 기본요금, 단위시간, 단위요금] 순으로 입력
    // 2) 초과한 부분에 대해서는 단위시간만큼 계산(단, 단위시간으로 나뉘지 않는 경우 올림)
    // 3) 기본 시간이하의 경우 기본 요금 청구
    for (int i = 0; i < 4; i++){
        cin>>fees[i];
    }
    
    vector<string> records;
    records.push_back("16:00 3961 IN");
    records.push_back("16:00 0202 IN");
    records.push_back("18:00 3961 OUT");
    records.push_back("18:00 0202 OUT");
    records.push_back("23:58 3961 IN");
    solution(fees, records);
    return 0;
}