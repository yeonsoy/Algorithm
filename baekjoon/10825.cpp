#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 국영수

int N;

struct student {
    string name;
    int korean;
    int english;
    int math;
};

vector <student> students;

bool compare(student a, student b) {
    if(a.korean == b.korean) {
        if(a.english == b.english) {
            if(a.math == b.math)
                return a.name < b.name;
            else return a.math > b.math;
        }
        else return a.english < b.english;
    }
    else return a.korean > b.korean;
}

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    students.resize(N + 1);
    for(int i = 0; i<N; i++) {
        
        cin >> students[i].name;
        cin >> students[i].korean >> students[i].english >> students[i].math;
    }
    
    sort(students.begin(), students.end(), compare);
    
     for(int i = 0; i<N; i++)
       cout << students[i].name << '\n';
}

