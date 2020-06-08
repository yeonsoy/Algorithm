#include <iostream>
#include <vector>
using namespace std;

// 파티
// 지민 > 진실 or 과장해서 말한다
// 진실을 아는 사람이 파티에 오게되면, 무조건 진실을 이야기함.
// 동일한 사람이 참석한 파티에선 동일하게 이야기 해야함.

struct party {
    int attend;
    vector <int> person;
    bool check;
};

int N, M;
int trues;
vector <party> info;
int answer;
bool people[51];

int main() {
    cin >> N >> M;
    cin >> trues;
    
    // 진실을 아는 사람들
    int num;
    for(int i = 0; i<trues; i++) {
        cin >> num;
        people[num] = true;
    }
    
    for(int i = 0; i<M; i++) {
        party p;
        cin >> p.attend; // p에 참석한 인원 수
        p.check = false; // 진실을 말하는지 여부
        for(int j = 0; j<p.attend; j++) {
            cin >> num;
            p.person.push_back(num);
            if(people[num])
                p.check = true; // 진실을 아는 사람이 있다면 그 파티에선 무조건 진실을 말해야한다
        }
        
        if(p.check)
            for(int j = 0; j<p.attend; j++)
                people[p.person[j]] = true; // 진실을 말해야하는 파티에 참석한 사람들은 다 진실 알고 있다
        
        info.push_back(p);
    }
    
    while(true) {
        int temp = 0;
        for(int i = 0; i<info.size(); i++) {
            if(!info[i].check) {
                for(int j = 0; j<info[i].attend; j++)
                {
                    if(people[info[i].person[j]]) {
                        info[i].check = true;
                        break;
                    }
                }
                
                if(!info[i].check) temp++;
                else {
                    for(int j = 0; j<info[i].attend; j++)
                        people[info[i].person[j]] = true;
                }
            }
        }
        
        if(temp != answer) answer = temp;
        else break;
    }
    
    cout << answer;
    
    return 0;
}
