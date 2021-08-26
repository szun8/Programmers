#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<char> three;
    while (n > 0) {
        if (n % 3 == 0)
            three.push_back('0');
        else if (n % 3 == 1)
            three.push_back('1');
        else if (n % 3 == 2)
            three.push_back('2');
        n /= 3;
    }

    int mulby3 = 1;
    for (int i = three.size(); i >= 0; --i) {
        if (three[i] == '0')
            mulby3 *= 3;
        else if (three[i] == '1') {
            answer += (mulby3 * 1);
            mulby3 *= 3;
        }
        else if (three[i] == '2') {
            answer += (mulby3 * 2);
            mulby3 *= 3;
        }
    }
    return answer;
}