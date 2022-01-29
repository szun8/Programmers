#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

struct Document {
public:
    int importance, location;   // 중요도와 원 위치 저장
};

int solution(vector<int> priorities, int location) {
    deque<Document> document;
    Document doc;
    for (int i = 0; i < priorities.size(); i++){
        doc.location=i;
        doc.importance=priorities[i];
        document.push_back(doc);
    }
    int max = *max_element(priorities.begin(),priorities.end());
    priorities[max_element(priorities.begin(),priorities.end())-priorities.begin()]=-1; // 최댓값 조정
    int answer = 0;
    while(!document.empty()){
        if(document.front().importance==max){   // 제일 중요한 문서가 제일 앞인경우.
            if(document.front().location == location){  // && 원하는 위치인경우.
                ++answer;
                break;
            }
            // && 아닌 경우.
            document.pop_front();
            max = *max_element(priorities.begin(),priorities.end());
            priorities[max_element(priorities.begin(),priorities.end())-priorities.begin()]=-1;
            answer++;
        }
        else{   // 최댓값이 아닌 경우.
            doc.importance = document.front().importance;
            doc.location = document.front().location;
            document.push_back(doc);
            document.pop_front();
        }
    }
    return answer;
}

int main(){
    int location;
    vector<int> priorities;
    priorities.push_back(4);
    priorities.push_back(2);
    priorities.push_back(3);
    priorities.push_back(2);
    
    solution(priorities, 2);
    return 0;
}