#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 나이순 정렬

int N;

struct client {
    int age;
    int idx;
    string name;
};

vector <client> clients;

bool compare(client a, client b) {
    if (a.age == b.age)
        return a.idx < b.idx;
    else
        return a.age < b.age;
}

int main() {

    fastio();

    cin >> N;

    for (int i = 0; i < N; i++) {
        client c;
        cin >> c.age >> c.name;
        c.idx = i;

        clients.push_back(c);
    }

    sort(clients.begin(), clients.end(), compare);

    for (int i = 0; i < N; i++)
        cout << clients[i].age << " " << clients[i].name << "\n";

    return 0;
}
