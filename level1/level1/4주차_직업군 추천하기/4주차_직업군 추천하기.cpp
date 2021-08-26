#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

enum SCORES {
    zero = 0,
    one = 1,
    two = 2,
    three = 3,
    four = 4,
    five = 5
};

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    vector<int> v_scores(5);
    vector<vector<string>> lan(5, vector<string>(6));
    for (int i = 0; i < 5; ++i) {
        int j = 0;
        istringstream ss(table[i]);
        string stringBuffer;
        while (getline(ss, stringBuffer, ' ')) {
            lan[i][j]=stringBuffer;
            ++j;
        }
    }
    map<string, int> m_scores = { {"SI",0},{"CONTENTS",0},{"HARDWARE",0},{"PORTAL",0},{"GAME",0} };
    
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < languages.size(); ++j) {
            for (int z = 1; z < 6; ++z) {
                if (lan[i][z] == languages[j]) {
                    switch (z)
                    {
                    case one:
                        v_scores[i] += (preference[j] * 5);
                        break;
                    case two:
                        v_scores[i] += (preference[j] * 4);
                        break;
                    case three:
                        v_scores[i] += (preference[j] * 3);
                        break;
                    case four:
                        v_scores[i] += (preference[j] * 2);
                        break;
                    case five:
                        v_scores[i] += (preference[j] * 1);
                        break;
                    }
                    break;
                }
            }
            //auto it = find(lan[i].begin(), lan[i].end(), languages[j]);
            //if (it == lan[i].end()){}  => 열번호를 찾는 방법 몰라서 사용못함 ㅜㅜ
        }
    }
    for (map<string, int>::iterator it = m_scores.begin(); it != m_scores.end(); ++it) {
        if (it->first == "SI")
            it->second = v_scores[0];
        else if (it->first == "CONTENTS")
            it->second = v_scores[1];
        else if (it->first == "HARDWARE")
            it->second = v_scores[2];
        else if (it->first == "PORTAL")
            it->second = v_scores[3];
        else if (it->first == "GAME")
            it->second = v_scores[4];
    }

    auto it = max_element(m_scores.begin(), m_scores.end(),
        [](const pair<string, int>& p1, const pair<string, int>& p2) {
            return p1.second < p2.second; });
    return answer = it->first;
}

int main() {
    vector<string> table = {
        "SI JAVA JAVASCRIPT SQL PYTHON C#",
        "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++",
        "HARDWARE C C++ PYTHON JAVA JAVASCRIPT",
        "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP",
        "GAME C++ C# JAVASCRIPT C JAVA" };
    vector<string> languages = { "PYTHON", "C++", "SQL" };
    vector<int> preference = { 7,5,5 };
    solution(table, languages, preference);
    return 0;
}