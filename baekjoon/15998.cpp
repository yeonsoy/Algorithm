#include <iostream>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 카카오머니

long long minB = 10e18;
long long money = 0;
long long N, M;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

int main()
{
    fastio();

    cin >> N;

    bool check = false, isPossible = true;
    long long a, b;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;

        // 충전해야 하는 경우
        if (money + a < 0)
        {
            long long temp = b - a - money;

            // 충전 단위 최소값 갱신
            if (b != 0 && b < minB)
            {
                check = true;
                minB = b;
            }

            if (M == 0)
                M = temp;
            else {
                M = gcd(M, temp);

                // 최대공약수로 구한 충전 단위가 충전 단위 최소값보다 작다면
                if (M <= minB && check)
                {
                    isPossible = false;
                    break;
                }
            }

        }
        else {
            // 충전이 필요 없는 경우
            if (money + a != b)
            {
                isPossible = false;
                break;
            }
        }
        money = b;
    }
    if (isPossible && M > 0)
        cout << M;
    else if (isPossible && M == 0)
        cout << 1;
    else
        cout << -1;

    return 0;
}
