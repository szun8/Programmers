#include <string>
#include <vector>

using namespace std;
class Yellow{   // 노랑색 카펫의 가로,세로가 될 수 있는 경우의 수
public:
    int width, height;
    Yellow(int w, int h){
        width=w;    height=h;
    }
};

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<Yellow> yellowArea;
    int yW=yellow, yH=1, area = brown + yellow;
    // 길이조건 : 가로 >= 세로
    while(yH<=yW){
        if(yellow%yH==0 && yH <= yellow/yH){
            yW = yellow/yH;
            Yellow thing(yW,yH);
            yellowArea.push_back(thing);
            ++yH;
        }
        else ++yH;
    }
    for (int i = 0; i < yellowArea.size(); i++) {
        int bW = yellowArea[i].width+2;
        int bH = yellowArea[i].height+2;
        if(bW*bH==area){
            answer.push_back(bW);
            answer.push_back(bH);
            break;
        }
        else if(bW*bH < area){
            while (bW*bH < area) {
                bW+=2;
                bH+=2;
            }
            if(bW*bH==area){
                answer.push_back(bW);
                answer.push_back(bH);
                break;
            }
        }
    }
    return answer;
}

int main(){
    solution(8,1);
    return 0;
}