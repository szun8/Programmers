using namespace std;
#include <iostream>

long long solution(int price, int money, int count)
{
	long long answer = -1;
	long long sumMoney = 0;

	for (int i = 1; i <= count; i++) {
		sumMoney += (price * i);
	}

	long long finalMoney = money - sumMoney;
	if (finalMoney < 0)
		answer = finalMoney * -1;

	else if (finalMoney >= 0)
		answer = 0;
	cout << answer;
	return answer;
}

int main() {
	int price = 300;
	int money = 1600;
	int count = 6;
	solution(price, money, count);
	return 0;
}