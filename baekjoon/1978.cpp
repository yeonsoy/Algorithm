#include <iostream>
#include <map>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 소수 찾기

int N;
int answer;
bool era[1001];

void getEratos() {
    era[0] = era[1] = true;
    for (int i = 2; i < 1001; i++)
        if (era[i] == false)
            for (int j = i + i; j < 1001; j += i)
                era[j] = true;
}

int main() {

    fastio();

    cin >> N;

    getEratos();
    int temp;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        if (!era[temp])
            answer++;
    }

    cout << answer << endl;

    return 0;
}
