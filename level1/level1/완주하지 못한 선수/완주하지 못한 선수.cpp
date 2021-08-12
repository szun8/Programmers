#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (int i = 0; i < participant.size(); i++) {
        if (participant[i] != completion[i])
            return participant[i];
    }
}

// 밑에 코드는 효율성 ㅠ 시간초과 탈락,,,ㅎㅠ
//string solution(vector<string> participant, vector<string> completion) {
//    string answer = "";
//    int i = 0;
//    while (i < participant.size()) {
//        int j = 0;
//        while (j < completion.size()) {
//            if (participant[i] == completion[j]) {
//                participant.erase(participant.begin() + i);
//                completion.erase(completion.begin() + j);
//                j = completion.size();
//                i--;
//            }
//            else
//                j++;
//        }
//        i++;
//    }
//    
//    return answer = participant[0];
//}

int main(){
    vector<string> participant = { "mislav", "stanko", "mislav", "ana" };
    vector<string> completion = { "stanko", "ana", "mislav" };
    solution(participant, completion);
    return 0;
}