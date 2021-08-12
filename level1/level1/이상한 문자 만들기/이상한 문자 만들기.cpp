#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    for (int z = 0; z < s.size(); z++) {
        s[z] = tolower(s[z]);
    }
    int i = 0;
    int j = 0;
    while (i != s.size()) {
        if (s[i] == 32) {
            j = -1;
        }
        else if (j == 0 || j % 2 == 0) {
            s[i] = toupper(s[i]);
        }
        i++; j++;
    }
    
    return answer = s;
}

int main() {
    solution("apple banana couple");
    return 0;
}