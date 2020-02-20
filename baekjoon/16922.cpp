#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int nums[4] = {1, 5, 10, 50};
vector <int> answer;

void solve(int idx, int count, int sum)
{
    if(count >= N)
    {
        answer.push_back(sum);
        return;
    }
    
    for(int i =idx; i<4; i++)
        solve(i, count+1, sum + nums[i]);
}

int main() {
    
    cin >> N;
    
    solve(0, 0, 0);
    
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    
    cout << answer.size();
    
    return 0;
}
