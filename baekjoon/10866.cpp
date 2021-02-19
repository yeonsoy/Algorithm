#include <iostream>
#include <deque>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 덱

int N;
deque <int> que;

int main() {

    fastio();

    cin >> N;
    string oper;
    int num;
    for (int i = 0; i < N; i++) {

        cin >> oper;
        if (oper == "push_front") {
            cin >> num;
            que.push_front(num);
        }
        else if (oper == "push_back") {
            cin >> num;
            que.push_back(num);
        }
        else if (oper == "pop_front") {
            if (que.empty())
                cout << "-1" << endl;
            else {
                cout << que.front() << endl;
                que.pop_front();
            }
        }
        else if (oper == "pop_back") {
            if (que.empty())
                cout << "-1" << endl;
            else {
                cout << que.back() << endl;
                que.pop_back();
            }
        }
        else if (oper == "size")
            cout << que.size() << endl;
        else if (oper == "empty")
            cout << que.empty() << endl;
        else if (oper == "front") {
            if (que.empty())
                cout << "-1" << endl;
            else
                cout << que.front() << endl;
        }
        else if (oper == "back") {
            if (que.empty())
                cout << "-1" << endl;
            else
                cout << que.back() << endl;
        }
    }

    return 0;
}
