#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int size = nums.size() / 2;
    sort(nums.begin(), nums.end());
    // unique()를 써줄 때는 항상 sort() 정렬을 해주자!
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    if (size < nums.size())
        answer = size;
    else if (size >= nums.size())
        answer = nums.size();

    return answer;
}

int main() {
    vector<int> nums = { 1,1 };
    solution(nums);
    return 0;
}