#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string num = "";
    int j, i = 0;
    
    while (i < s.size()) {
        if (s[i]<10 && s[i] > -1) {
            
        }
        else if (s.find("one") != string::npos) {
            j = s.find("one");
            s[j] = '1';
        }
        else if (s.find("two") != string::npos) {
            j = s.find("two");
            s[j] = '2';
        }
        else if (s.find("three") != string::npos) {
            j = s.find("three");
            s[j] = '3';
        }
        else if (s.find("four") != string::npos) {
            j = s.find("four");
            s[j] = '4';
        }
        else if (s.find("five") != string::npos) {
            j = s.find("five");
            s[j] = '5';
        }
        else if (s.find("six") != string::npos) {
            j = s.find("six");
            s[j] = '6';
        }
        else if (s.find("seven") != string::npos) {
            j = s.find("seven");
            s[j] = '7';
        }
        else if (s.find("eight") != string::npos) {
            j = s.find("eight");
            s[j] = '8';
        }
        else if (s.find("nine") != string::npos) {
            j = s.find("nine");
            s[j] = '9';
        }
        else if (s.find("zero") != string::npos) {
            j = s.find("zero");
            s[j] = '0';
        }
        i++;
    }

    for (int i = 0; i < s.size(); i++) {
        if (s[i]<='9' && s[i] >= '0')
            num += s[i];
    }
    return answer = stoi(num);
}

int main() {
    solution("one4seveneight");
    return 0;
}