#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for (int l = left; l <= right; l++) {
        int count = 0;
        for (int i = 1; i <= l; i++) {
            if (l % i == 0)
                ++count;
        }
        if (count % 2 == 0)
            answer += l;
        else
            answer -= l;
    }
    return answer;
}