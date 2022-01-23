#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int cmpNum;
bool morethan(int num){
    return num >= cmpNum;
}

int solution(vector<int> citations) {
    int answer = 0;
    cmpNum = citations.size();  // 비교하는 수는 size~0 사이
    sort(citations.begin(),citations.end(),greater<int>()); // 내림차순 정렬
    while(cmpNum>=0){
        int cntCitation = count_if(citations.begin(),citations.end(),morethan);
        if(cntCitation>=cmpNum){    // 인용된 논문의 수가 조건에 만족한다면,
            answer = cmpNum;
            break;
        }
        else cmpNum--;
    }
    return answer;
}

int main(){
    vector<int> citations;
    citations.push_back(6);
    citations.push_back(1);
    citations.push_back(0);
    citations.push_back(5);
    citations.push_back(4);

    solution(citations);
    return 0;
}