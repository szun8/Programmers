#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int size = 0;
    
    while (size < arr1.size()) {
        vector<string> map1, map2;
        map1.resize(n);  map2.resize(n);
        int number = n - 1;
        int num1 = arr1[size];
        while (num1 > 0) {
            int binary = num1 % 2;
            if (binary == 1)
                map1[number] = "#";
            else
                map1[number] = ' ';
            num1 /= 2;
            if (number > 0)
                --number;
        }
        number = n - 1;
        int num2 = arr2[size];
        while (num2 > 0) {
            int binary = num2 % 2;
            if (binary == 1)
                map2[number] = "#";
            else
                map2[number] = ' ';
            num2 /= 2;
            if(number > 0)
                --number;
        }
        for (int i = 0; i < n; ++i) {
            if (map1[i] == "")
                map1[i] = " ";
            if (map2[i] == "")
                map2[i] = " ";
        }
        string map;
        for (int i = 0; i < n; i++) {
            if (map1[i] == map2[i])
                map += map1[i];
            else {
                map1[i] = "#";
                map += map1[i];
            }  
        }
        answer.push_back(map);
        size++;
    }
    return answer;
}

int main() {
    vector<int> arr1 = { 9,20,28,18,11 };
    vector<int> arr2 = { 30,1,21,17,28 };
    solution(5, arr1, arr2);
    return 0;
}