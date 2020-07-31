#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// 부먹왕국의 차원 관문

int T;
int N, D;
vector <int> city;
int answer = 0;
 
int main() {
     
    cin >> T;
     
    for(int test_case = 0; test_case < T; test_case++) {
         
        cin >> N >> D;
         
        city.push_back(1);
         
        for(int i = 0; i<N; i++) {
            int destroy;
            cin >> destroy;
            city.push_back(destroy);
        }
         
        city.push_back(1);
         
        int count = D - 1;
         
        for ( int i = 0; i <city.size(); i++)
        {
            if(!count && !city[i])
            {
                city[i] = 1;
                answer++;
                count = D - 1;
                continue;
            }
            if(city[i])
            {
                count = D - 1;
                continue;
            }
            count--;
        }
         
        cout << "#" << test_case + 1 << " " << answer << endl;
         
        answer = 0;
        city.clear();
    }
     
    return 0;
}
