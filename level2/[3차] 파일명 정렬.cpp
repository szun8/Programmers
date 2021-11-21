#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(pair<int, pair<string, int> >a, pair<int, pair<string, int> > b){
    if(a.second.first != b.second.first) return a.second.first<b.second.first;
    else  return a.second.second < b.second.second;
    // head와 number 둘다 동일하면 그냥 그 순서 유지.
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    vector<pair<int, pair<string, int> > > name;  //index - (head-number)
    for (int i = 0; i < files.size(); i++)
    {
        string head = "";
        int j=0;
        string number = "";
        while(isdigit(files[i][j])==0){
            //숫자가 아니라면, 계속 head추가
            head+=files[i][j];
            ++j;
        }
        transform(head.begin(),head.end(), head.begin(), ::tolower);
        while (isdigit(files[i][j])!=0)
        {
            //숫자라면,
            number+=files[i][j];
            j++;
        }
        int num = stoi(number);
        name.push_back(pair<int, pair<string, int> >(i,pair<string, int>(head,num)));
    }
    stable_sort(name.begin(),name.end(),cmp);
    vector<pair<int, pair<string, int> > >::iterator iter = name.begin();
    for (int i = 0; i < name.size(); i++)
    {
        answer.push_back(files[iter->first]);
        ++iter;
    }
    
    return answer;
}
int main(){
    vector<string> files;
    files.push_back("img12.png");
    files.push_back("img10.png");
    files.push_back("img02.png");
    files.push_back("img1.png");
    files.push_back("IMG01.GIF");
    files.push_back("img2.JPG");
    solution(files);
    return 0;
}
