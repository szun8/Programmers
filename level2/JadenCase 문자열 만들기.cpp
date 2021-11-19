#include <iostream>
#include <string>
using namespace std;

string solution(string s) {
    string answer = "";
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = tolower(s[i]);
    }
    if(s[0]>=97 && s[0]<=122) s[0]=toupper(s[0]);
    for (int i = 1; i < s.size(); i++)
    {
        if(s[i]==' '){
            s[i+1]=toupper(s[i+1]);
        }
    }
    return answer=s;
}