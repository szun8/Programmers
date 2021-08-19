#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Student {
public:
    int correctCount = 0;
    vector<int> studentAnswer;
public:

    int correctAnswer(vector<int>* answers) {
        // 각 인스턴스당 몇문제를 맞췄는지 count하는 함수
        for (int i = 0; i < answers->size(); i++) {
            if (answers->at(i) == studentAnswer.at(i))
                ++correctCount;
        }
        return correctCount;
    }
};

vector<int> solution(vector<int> answers) { // 주어진 답
    int size[3] = { 0,0,0 };

    Student s1;
    while (answers.size() != size[0]) {
        for (int j = 1; j < 6; j++) {
            if (answers.size() != size[0]) {
                s1.studentAnswer.push_back(j);  // 우선 2 삽입
                ++size[0];
            }
        }
    }
    s1.correctAnswer(&answers);

    Student s2;
    while (answers.size() != size[1]) {
        for (int j = 1; j < 6; j++) {
            if (answers.size() != size[1]) {
                s2.studentAnswer.push_back(2);  // 우선 2 삽입
                ++size[1];
            }
            if (answers.size() != size[1] && j == 2) {   // 2면, 3을 삽입
                s2.studentAnswer.push_back(++j);
                ++size[1];
            }
            else if (answers.size() != size[1]) {          // 1,4,5 삽입
                s2.studentAnswer.push_back(j);
                ++size[1];
            }
        }
    }
    s2.correctAnswer(&answers);

    Student s3;
    while (answers.size() != size[2]) {
        int array3[5] = { 3,1,2,4,5 };
        for (int i = 0; i < 5; i++) {
            if (answers.size() != size[2]) {
                s3.studentAnswer.push_back(array3[i]);
                ++size[2];
            }
            if (answers.size() != size[2]) {
                s3.studentAnswer.push_back(array3[i]);
                ++size[2];
            }
        }
    }
    s3.correctAnswer(&answers);

    vector<int> answer; // 정답자 출력/ 여러명일 경우, 오름차순 정렬
    if (s1.correctCount == s2.correctCount && s2.correctCount == s3.correctCount) {
        answer.push_back(1);
        answer.push_back(2);
        answer.push_back(3);
        cout << "everyone" << endl;
    }

    else if (s1.correctCount > s2.correctCount && s1.correctCount > s3.correctCount) {
        answer.push_back(1);
        cout << "1" << endl;
    }
    else if (s2.correctCount > s3.correctCount && s2.correctCount > s1.correctCount) {
        answer.push_back(2);
        cout << "2" << endl;
    }
    else if (s3.correctCount > s2.correctCount && s3.correctCount > s1.correctCount) {
        answer.push_back(3);
        cout << "3" << endl;
    }

    else if (s1.correctCount == s2.correctCount && s1.correctCount > s3.correctCount) {
        answer.push_back(1);
        cout << "1" << endl;
        answer.push_back(2);
        cout << "2" << endl;
    }
    else if (s1.correctCount == s3.correctCount && s1.correctCount > s2.correctCount) {
        answer.push_back(1);
        cout << "1" << endl;
        answer.push_back(3);
        cout << "3" << endl;
    }
    else if (s2.correctCount == s3.correctCount && s2.correctCount > s1.correctCount) {
        answer.push_back(2);
        cout << "2" << endl;
        answer.push_back(3);
        cout << "3" << endl;
    }
    else {
        cout << "anyone" << endl;
    }
    return answer;
}

int main() {
    solution({ 3,3,1,1 });
    return 0;
}