#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string reverseN = to_string(n);
    for (int i = reverseN.size() - 1; i >= 0; i--) {
        answer.push_back(reverseN[i] - '0');
    }
    return answer;
}

int main() {
    long long n = 12345;
    solution(n);
    return 0;
}