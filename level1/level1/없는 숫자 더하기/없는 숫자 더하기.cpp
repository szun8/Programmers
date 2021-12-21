#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    bool number[10]={false, };
    int answer = 0;
    for (int i = 0; i < numbers.size(); i++) {
        number[numbers[i]]=true;
    }

    for (int i = 0; i < 10; i++) {
        if(number[i]==false) answer+=i;
    }
    
    return answer;
}