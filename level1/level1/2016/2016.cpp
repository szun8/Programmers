#include <string>
#include <iostream>
#include <vector>

using namespace std;
// 2016-01-01 = FRI
// 31days = 1,3,5,7,8,10,12 = next month +3
// 30days = 4,6,9,11 = next month +2
// 29days = 2 = next month +1
// 
// SUN,MON,TUE,WED,THU,FRI,SAT
string solution(int a, int b) {
    string answer = "";
    vector<int> monthDays = { 3,1,3,2,3,2,3,3,2,3,2,3 };
    vector<string> days{ "FRI","SAT","SUN","MON","TUE","WED","THU" };
    int startDay = 0;
    // STEP1) 선택 월 1일 찾기
    for (int i = 0; i < a - 1; i++) {
        startDay += monthDays.at(i);
    }
    startDay = startDay % 7;

    // STEP2) 선택 일 요일 찾기
    int b_days = (b + startDay - 1) % 7;

    return answer = days.at(b_days);
}

void main() {
    int a = 8;  //month
    int b = 4;  //day
    cout << solution(a, b);
}