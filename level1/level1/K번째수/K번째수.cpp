#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	priority_queue<int, vector<int>, greater<int>> sortQ;

	for (int i = 0; i < commands.size(); i++) {
		vector<int> notAnswer;
		int a = commands[i][0] - 1;		//start
		int b = commands[i][1] - 1;		//end
		int c = commands[i][2] - 1;		//need num

		for (int j = a; j <= b; j++) {
			sortQ.push(array.at(j));
		}

		int size = sortQ.size();
		for (int j = 0; j < size; j++) {
			notAnswer.push_back(sortQ.top());
			sortQ.pop();
		}
		answer.push_back(notAnswer.at(c));
	}
	return answer;
}

int main() {

	vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
	vector<vector<int>> commands = { {2, 5, 3},{4, 4, 1},{1, 7, 3} };
	solution(array, commands);

	return 0;
}