#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zeroN = 0;
    int correctN = 0;

    for (int i = 0; i < lottos.size(); i++) {
        if (lottos[i] != 0) {
            for (int j = 0; j < win_nums.size(); j++) {
                if (win_nums[j] == lottos[i]) {
                    ++correctN;
                    win_nums.erase(win_nums.begin() + j);
                    break;
                }
            }
        }
        else
            ++zeroN;
    }

    int max = correctN + zeroN;
    int min = correctN;

    if (max == 6) answer.push_back(1);
    else if (max == 5) answer.push_back(2);
    else if (max == 4) answer.push_back(3);
    else if (max == 3) answer.push_back(4);
    else if (max == 2) answer.push_back(5);
    else answer.push_back(6);

    if (min == 6) answer.push_back(1);
    else if (min == 5) answer.push_back(2);
    else if (min == 4) answer.push_back(3);
    else if (min == 3) answer.push_back(4);
    else if (min == 2) answer.push_back(5);
    else answer.push_back(6);

    return answer;
}