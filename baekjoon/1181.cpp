#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 단어 정렬

int N;
vector <string> str;

bool compare(string a, string b) {

    if (a.size() == b.size())
        return a < b;
    else
        return a.size() < b.size();
}

int main() {

    cin >> N;

    str.resize(N);
    for (int i = 0; i < N; i++)
        cin >> str[i];

    sort(str.begin(), str.end(), compare);
    str.erase(unique(str.begin(), str.end()), str.end());

    for (int i = 0; i < str.size(); i++)
        cout << str[i] << "\n";

    return 0;
}
