#include <iostream>
using namespace std;

// 거듭 제곱

int mul(int ans, int n, int m)
{
    if (m == 0)
        return ans;
 
    return mul(ans * n, n, m - 1);
}
 
int main(int argc, char** argv)
{
    for (int i = 0; i < 10; i++)
    {
        int t, n, m;
        cin >> t >> n >> m;
         
        cout << "#" << t << " " << mul(1, n, m) << endl;
 
    }
    return 0;
}
