#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int size = A.size()-1;
    for (int i = 0; i < A.size(); i++)
    {
        answer+=(A[i]*B[size-i]);
    }
    cout<<answer;
    return answer;
}

int main(){
    vector<int> A;
    A.push_back(1);
    A.push_back(4);
    A.push_back(2);

    vector<int> B;
    B.push_back(5);
    B.push_back(4);
    B.push_back(4);
    solution(A,B);
    return 0;
}