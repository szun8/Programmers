#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int arrRow = arr1.size();
    int arrColumn = arr1[0].size();
    vector<vector<int>> answer(arrRow, vector <int>(arrColumn, NULL));

    for (int i = 0; i < arr1.size(); i++) {
        for (int j = 0; j < arr1[i].size(); j++) {
            answer[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    return answer;
}

int main() {
    vector<vector<int>> arr1 = { {1},{2} };
    vector<vector<int>> arr2 = { {3},{4} };
    solution(arr1, arr2);
    return 0;
}