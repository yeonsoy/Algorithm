#include <iostream>
#include <vector>
using namespace std;

// 덩치
struct person {
    int height;
    int weight;
    int rank;
};

int N;
vector <person> people;

int main() {
    
    cin >> N;
    
    for(int i = 0; i<N; i++) {
        int w, h;
        cin >> w >> h;
        people.push_back({h, w, 1});
    }
    
    for(int i = 0; i<N; i++) {
        person &pivot = people[i];
        for(int j = 0; j<N; j++)
        {
            if(i == j) continue;
            if(people[j].height > pivot.height && people[j].weight > pivot.weight)
                pivot.rank++;
        }
        
        cout << pivot.rank << " ";
    }
    
    return 0;
}
