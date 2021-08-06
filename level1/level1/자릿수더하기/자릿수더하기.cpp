#include <iostream>
#include <string>
using namespace std;
int solution(int n) {
	int answer = 0;
	string numberStr = to_string(n);
	for (int i = 0; i < numberStr.size(); i++) {
		answer += (numberStr[i] - '0');
	}
	return answer;
}
