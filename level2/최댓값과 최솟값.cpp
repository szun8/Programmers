#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> nums;
    for (int i = 0; i < s.size(); i++)
    {
        string snum;
        int num;
        if(s[i]=='-'){
            int j=i+1;
            while(s[j]<=57 && s[j]>=48){
                snum.insert(snum.end(),s[j]);
                j++;
            }
            num = stoi(snum)*-1;
            nums.push_back(num);
            i=j-1;
        }
        else if(s[i]<=57 && s[i]>=48){
            snum.insert(snum.end(),s[i]);
            int j=i+1;
            while(s[j]<=57 && s[j]>=48){
                snum.insert(snum.end(),s[j]);
                j++;
            }
            num = stoi(snum);
            nums.push_back(num);
            i=j-1;
        }
        // 공백이면 걍 다음 진행
    }
    int min = *min_element(nums.begin(),nums.end());
    int max = *max_element(nums.begin(),nums.end());
    string smin = to_string(min);
    string smax = to_string(max);
    answer+=(smin + " " + smax);
    return answer;
}

int main(){
    string s;
    
    getline(cin, s);
    solution(s);
    return 0;
}