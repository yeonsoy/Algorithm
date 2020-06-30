#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Ski Course Design

int N;
int answer = 2e9;
vector <int> number;

int main() {
    
    cin >> N;
    
    number.resize(N);
    
    for(int i = 0; i<N; i++)
        cin >> number[i];
    
    sort(number.begin(), number.end());
    
    int high = 0;
    for(int low = 1; low <= 83; low++)
    {
        high = low + 17;
        
        int temp = 0;
        
        for (int i = 0; i < N; i++)
        {
            if(number[i] >= low && number[i] <= high)
                continue;
            
            if (number[i] < low)
                temp += (low - number[i]) * (low - number[i]);
            if (number[i] > high)
                temp += (number[i] - high) * (number[i] - high);
        }
        
        answer = min(answer, temp);
    }
    
    cout << answer << endl;
    
    return 0;
}
