#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int count = 0, answer = 0, len = people.size()-1;
    int amount = limit;
    sort(people.begin(),people.end(),greater<int>());
    while (count<=len)
    {
        amount-=people[count];
        people[count] = -1;
        ++count;
        if(people[len] != -1 && people[len] <= amount) {
            people[len]=-1;
            --len;
        }
        ++answer;
        amount = limit;
    }
    cout<<answer;
    return answer;
}
int main(){
    vector<int> people;
    int limit=200;
    people.push_back(160);
    people.push_back(150);
    people.push_back(50);
    people.push_back(40);
    solution(people, limit);
    return 0;
}