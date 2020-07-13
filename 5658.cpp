#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int T, N, K;
string str;
vector <int> nums;

// 보물상자 비밀번호
 
void rotate()
{
    char b = str.back();
    str.pop_back();
    str = b + str;
 
    for (int i = 0; i < N; i += N / 4)
    {
        int nDec = (int)strtol(str.substr(i, N / 4).c_str(), NULL, 16);
        nums.push_back(nDec);
    }
}
 
int main()
{
 
    int test = 0;
    cin >> test;
 
    for (int t = 0; t < test; t++)
    {
        cin >> N >> K;
        cin >> str;
        for (int i = 0; i < N; i += N / 4)
        {
            int nDec = (int)strtol(str.substr(i, N / 4).c_str(), NULL, 16);
            nums.push_back(nDec);
        }
 
        for (int i = 0; i < N / 4; i++)
            rotate();
 
        sort(nums.begin(), nums.end(), greater<int>());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
 
        cout << "#" << t + 1 << " " << nums[K - 1] << endl;
        nums.clear();
    }
     
    return 0;
}
