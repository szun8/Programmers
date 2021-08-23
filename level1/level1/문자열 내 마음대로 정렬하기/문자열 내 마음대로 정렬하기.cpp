#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    multimap<char, string> ch;
    // a = 97 ~ z = 122

    for (int i = 0; i < strings.size(); ++i) {
        ch.insert(make_pair(strings[i].at(n), strings[i]));
    }

    for (multimap<char, string>::iterator it = ch.begin(); it != ch.end();) {
        multimap<char, string>::iterator itA = it;
        vector<string> a;
        for (multimap<char, string>::iterator it2 = ch.lower_bound(it->first); it2 != ch.upper_bound(it->first); ++it2) {
            a.push_back(it2->second);
            ++itA;
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < a.size(); i++) {
            answer.push_back(a[i]);
        }
        it = itA;
    }
    return answer;
}

int main() {
    vector<string> strings = { "sun", "bed", "car" };
    solution(strings, 1);
    return 0;
}