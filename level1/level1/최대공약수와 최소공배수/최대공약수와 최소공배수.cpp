#include <string>
#include <vector>

using namespace std;
int gcd(int n, int m) {
    int r;
    while (m != 0) {
        r = n % m;
        n = m;
        m = r;
    }
    return n;
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.push_back(gcd(n, m));    //최대공약수
    answer.push_back(n * m / gcd(n, m));

    return answer;
}

int main() {
    solution(3, 12);
    return 0;
}