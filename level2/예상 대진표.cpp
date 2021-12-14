#include <iostream>
#include <cmath>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int vsA, vsB, count = 0;
    while (true)
    {
        if(a%2==0){
            vsA = a-1;
        }
        else{
            vsA = a+1;
        }

        if(b%2==0){
            vsB = b-1;
        }
        else{
            vsB = b+1;
        }

        if(vsA==b && vsB == a) {
            return count+1;
        }
        else{
            ++count;
            a = ceil((float)a/2);
            b = ceil((float)b/2);
        }
    }
}

int main(){
    solution(8,4,7);
    return 0;
}