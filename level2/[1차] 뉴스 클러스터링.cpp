#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {
    vector<string> one,two,sum;             // one == str1 / two == str2 / sum == 합집합 원소
    for (int i = 0; i < str1.size(); i++){  // str1 대문자 만들기
        str1[i]=toupper(str1[i]);
    }
    for (int i = 0; i < str1.size()-1; i++){    // 영문자로만 이뤄진 원소만들고 push
        string word = "";
        if(str1[i]>=65 && str1[i]<=90) word+=str1[i];
        else continue;
        if(str1[i+1]>=65 && str1[i+1]<=90) word+=str1[i+1];
        else continue;
        one.push_back(word);
    }
    
    for (int i = 0; i < str2.size(); i++){  // str2 대문자 만들기
        str2[i]=toupper(str2[i]);
    }
    for (int i = 0; i < str2.size()-1; i++){    // 영문자로만 이뤄진 원소만들고 push
        string word = "";
        if(str2[i]>=65 && str2[i]<=90) word+=str2[i];
        else continue;
        if(str2[i+1]>=65 && str2[i+1]<=90) word+=str2[i+1];
        else continue;
        two.push_back(word);
    }
    
    // 교집합구하기
    int crossCnt = 0;
    if(one.size()<two.size()){  // one의 크기가 작은 경우,
        for (int i = 0; i < one.size(); i++){
            vector<string>::iterator iter = find(two.begin(),two.end(),one[i]);
            sum.push_back(one[i]);
            if(iter!=two.end()){    // 만약 one의 글자가 two에 있다면
                ++crossCnt;
                two[iter-two.begin()]="x";   // 교집합 확인 처리해주기.
            }
        }
        for (int i = 0; i < two.size(); i++){
            if(two[i]!="x") sum.push_back(two[i]);  // 합집합 원소 구하기
        }
    }
    else{   // 그 외의 경우 (two가 작거나 같은 경우,)
        for (int i = 0; i < two.size(); i++){ 
            vector<string>::iterator iter = find(one.begin(),one.end(),two[i]);
            sum.push_back(two[i]);
            if(iter!=one.end()){    // 만약 two의 글자가 one에 있다면
                ++crossCnt;
                one[iter-one.begin()]="x";   // 교집합 확인 처리해주기.
            }
        }
        for (int i = 0; i < one.size(); i++){
            if(one[i]!="x") sum.push_back(one[i]);
        }
    }
    int sumCnt = sum.size();    // 합집합 구하기
    if(crossCnt == 0 && sumCnt == 0) return 65536;  // 나눗셈이 안되는 경우.
    float jacquard = ((float)crossCnt/sumCnt)*65536;// 문제 조건에 맞춰 정답 구하기
    int answer = trunc(jacquard);
    return answer;
}
int main(){
    solution("aa1+aa2", "AAAA12");
    return 0;
}