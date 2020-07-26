#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// 재관이의 대량 할인
// 세일 조건 : 세 벌의 옷을 사면 그 중 가장 저렴한 한 벌에 해당하는 값은 내지 않아도 된다는 조건
// 가장 높은 순으로 정렬해서 3개씩 나눠서 계산하기
 
int T, N;
vector <int> nums;
 
bool desc(int a, int b)
{
    return a > b;
}
int main() {
     
    cin >> T;
     
   for(int test_case = 0; test_case < T; test_case ++) {
    cin >> N;
     
       nums.clear();
    for(int i =0; i<N; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }
     
    sort(nums.begin(), nums.end(), desc);
     
    int sum = 0;
    for(int i =0; i<N; i++) {
     
        if((i + 1) % 3 != 0)
            sum += nums[i];
    }
     
     
    cout << "#" << test_case + 1 << " " <<  sum << endl;
   }
    return 0;
}
