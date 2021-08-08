#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int countP = 0;
    int countY = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'p' || s[i] == 'P')
            countP++;
        if (s[i] == 'y' || s[i] == 'Y')
            countY++;
    }
    // 인자로 받은 문자를 대문자 혹 소문자로 만들어서 문제푸는 방법도 가능
    // tolower() || toupper()
    // https://blockdmask.tistory.com/452
    if (countP != countY)
        answer = false;

    return answer;
}