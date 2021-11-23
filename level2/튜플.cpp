#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(vector<int> a, vector<int> b){
    return a.size()<b.size();
}
vector<int> solution(string s) {
    vector<int> answer;

    vector< vector<int> > what;
    for (int i = 1; i < s.size(); i++)
    {
        vector< int> what2;
        if(s[i]=='{'){
            ++i;
            while(s[i]!='}'){
                if(s[i]!=','){
                    string strN="";
                    while(isdigit(s[i])!=0){
                        strN+=s[i];
                        ++i;
                    }
                    int n = stoi(strN);
                    what2.push_back(n);
                }
                else ++i;
            }
            what.push_back(what2);
        }
    }
    sort(what.begin(),what.end(),cmp);
    answer.push_back(what[0][0]);
    for (int i = 1; i < what.size(); i++)
    {
        for (int j = 0; j < what[i].size(); j++)
        {
            if(find(answer.begin(),answer.end(),what[i][j])!=answer.end()){
                // answer에 있으면 다음으로 넘어가기
                continue;
            }
            else{
                answer.push_back(what[i][j]);
            }
        }
    }
    
    return answer;
}

int main(){
    string s = "{{123}}";
    solution(s);

    return 0;
}