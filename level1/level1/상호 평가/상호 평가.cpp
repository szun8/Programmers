#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string solution(vector<vector<int>> scores) {
	string answer = "";
	int size = scores.size();
	int max, min;
	for (int i = 0; i < size; ++i) {
		float average = 0;
		int count = 0;
		vector<int> num;
		for (int j = 0; j < size; ++j)
			num.push_back(scores[j][i]);
		max = *max_element(num.begin(), num.end());
		min = *min_element(num.begin(), num.end());
		for (int j = 0; j < size; ++j) {
			if (i != j && max == scores[i][i] && max == num[j])  break;
			else if (i != j && min == scores[i][i] && min == num[j])  break;
			++count;
		}
		if (count == size && (min == scores[i][i] || max == scores[i][i])) {
			num.erase(num.begin() + i);
		}
		
		for (int j = 0; j < num.size(); ++j) {
			average += num[j];
		}
		average/=num.size();

		if (average >= 90)
			answer += 'A';
		else if (average >= 80)
			answer += 'B';
		else if (average >= 70)
			answer += 'C';
		else if (average >= 50)
			answer += 'D';
		else 
			answer += 'F';
	}
	return answer;
}

int main() {
	vector<vector<int>> scores = { {100,90,98,88,65},{50,45,99,85,77},{47,88,95,80,67},{61,57,100,80,65},{24,90,94,75,65} };
	solution(scores);
	return 0;
}