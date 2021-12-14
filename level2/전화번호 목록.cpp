#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool solution(vector<string> phone_book) {
    sort(phone_book.begin(),phone_book.end());
    bool isOk = false;
    for (int i = 0; i < phone_book.size()-1; i++) {
        if(phone_book[i][0]==phone_book[i+1][0]){
            string cmpStr = phone_book[i+1].substr(0, phone_book[i].size());
            if(cmpStr == phone_book[i]) return false;
        }
    }
    if(isOk == false) return true;
}