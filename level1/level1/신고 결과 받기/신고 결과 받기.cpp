#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class User{
public:
    string userName;
    vector<string> notifyUser;      // 내가 신고한 유저들 모음
    vector<string> notifiedUser;    // 나를 신고한 유저들 모음
    int answerCnt;                  // 처리결과 메일 전송 수
    User(){
        answerCnt=0;
    }
};

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> answer;
    User *user = new User[id_list.size()];
    for (int i = 0; i < id_list.size(); i++) {  // 입력된 유저별 class 생성
        user[i].userName = id_list[i];
    }
    for (int i = 0; i < report.size(); i++) {
        int j = 0;
        string reportName="", reportedName="";  // 신고한 사람 -> 신고당한 사람
        while(report[i][j]!=' '){
            reportName+=report[i][j];
            ++j;
        }
        ++j;
        while(report[i][j]!='\0'){
            reportedName+=report[i][j];
            ++j;
        }
        for (int j = 0; j < id_list.size(); j++){
            if(user[j].userName==reportName){
                // 내가 신고한 유저 입력
                user[j].notifyUser.push_back(reportedName);
                break;
            }
        }
        for (int j = 0; j < id_list.size(); j++){
            if(user[j].userName==reportedName){
                // 나를 신고한 유저 입력
                user[j].notifiedUser.push_back(reportName);
                break;
            }
        }
    }

    for (int i = 0; i < id_list.size(); i++) {
        // 동일한 유저에게는 1회 신고만 유효 -> 중복제거
        // 시간초과 원인 : 입력 때마다 있는지 없는지 찾는 find() 사용으로 매번 찾아주는 과정 발생
        // 시간초과 해결 : 일단 넣어주고 나중에 한번에 중복제거로 찾아주는 과정 생략
        sort(user[i].notifyUser.begin(),user[i].notifyUser.end());
        user[i].notifyUser.erase(unique(user[i].notifyUser.begin(),user[i].notifyUser.end()),user[i].notifyUser.end());
    
        sort(user[i].notifiedUser.begin(),user[i].notifiedUser.end());
        user[i].notifiedUser.erase(unique(user[i].notifiedUser.begin(),user[i].notifiedUser.end()),user[i].notifiedUser.end());
    }
    
    // 나를 신고한 사람 명단 size가 k이상이라면 그 명단의 사람에게 메일 발송 cnt++
    for (int i = 0; i < id_list.size(); i++){
        if(user[i].notifiedUser.size()>=k){
            for (int j = 0; j < id_list.size(); j++) {
                if(!user[i].notifiedUser.empty() && user[i].notifiedUser.back()==user[j].userName){
                    ++user[j].answerCnt;
                    user[i].notifiedUser.pop_back();
                    j=-1;
                }
            }   
        }
    }
    for (int i = 0; i < id_list.size(); i++){
        answer.push_back(user[i].answerCnt);
    }
    
    return answer;
}

int main(){
    vector<string> id_list;
    vector<string> report;
    id_list.push_back("muzi");
    id_list.push_back("frodo");
    id_list.push_back("apeach");
    id_list.push_back("neo");

    report.push_back("muzi frodo");
    report.push_back("apeach frodo");
    report.push_back("frodo neo");
    report.push_back("muzi neo");
    report.push_back("apeach muzi");
    solution(id_list, report, 2);
    return 0;
}