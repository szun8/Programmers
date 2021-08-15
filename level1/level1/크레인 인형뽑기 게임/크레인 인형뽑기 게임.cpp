#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> box;
    while (!moves.empty()) {
        int pos = moves.front()-1;
        for (int i = 0; i < board.size() ; ++i) {
            if (board[i][pos] != 0) {
                if (!(box.empty()) && box.top() == board[i][pos]) {
                    answer += 2;
                    box.pop();
                    board[i][pos] = 0;
                    break;
                }
                box.push(board[i][pos]);
                board[i][pos] = 0;
                break;
            }
        }
        moves.erase(moves.begin());
    }
    return answer;
}

int main() {
    vector<vector<int>> board = { {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} };
    vector<int> moves = { 1,5,3,5,1,2,1,4 };
    solution(board, moves);
    return 0;
}