#include <iostream>
#include <vector>
using namespace std;

// 더하기 사이클

int N;
vector <int> nums;

void getUnits(int num)
{
    nums.clear();
    int number = num;
    
    while(number) {
        nums.push_back(number % 10);
        number /= 10;
    }
}

int main()
{
    cin >> N;
    int cycle = 0;
    
    getUnits(N);
    
    int now_number = N;
    
    while(true) {
        cycle ++;
        int sum = 0;
        for(int i =0; i<nums.size(); i++)
            sum += nums[i];
        
        int new_number = (sum % 10) + (now_number % 10) * 10;

        if(new_number == N)
            break;
        else
        {
            now_number = new_number;
            getUnits(new_number);
        }
    }
    
    cout << cycle;
    
    return 0;
}
