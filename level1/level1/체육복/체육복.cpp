#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n - (lost.size() + reserve.size());
	sort(reserve.begin(), reserve.end());
	sort(lost.begin(), lost.end());
	// 1) 도난당한자 = 여벌있는 자 : 자기꺼 자기가 하면 됨
	int i = 0;
	while (i < lost.size()) {
		bool isSame = false;
		int j = 0;

		while (j < reserve.size()) {
			if (lost.at(i) == reserve.at(j)) {
				answer+=2;
				lost.erase(lost.begin() + i);
				reserve.erase(reserve.begin() + j);
				isSame = true;
				j = reserve.size();
			}
			else  j++;
		}
		if (isSame == false) i++;
		// 맞는 체육복이 해당 lost에 없기에 다음으로 넘어가주기 
	}
	// 2) 왼쪽을 우선, 본인 양옆에 있으면 카운트
	int left, right;
	for (int i = 0; i < lost.size(); i++) {
		if (lost[i] == 1) 
			left = NULL;
		else
			left = lost[i] - 1;

		if (lost[i] == n)
			right = NULL;
		else
			right = lost[i] + 1;

		for (int j = 0; j < reserve.size(); j++) {
			if (left == reserve[j] || right == reserve[j]) {
				answer += 2;	//왼쪽이나 오른쪽의 값이 reserve에 있으면 카운트
				reserve.erase(reserve.begin() + j);
				lost.erase(lost.begin() + i);
				--i;
				j = reserve.size();
			}
		}
	}
	if (!reserve.empty()) answer += reserve.size();
	return answer;
}

int main() {

	int studentN = 5;
	vector<int> lost = { 2,4 };
	vector<int> reserve = { 3,1 };

	solution(studentN, lost, reserve);
	return 0;
}