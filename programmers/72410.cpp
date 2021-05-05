#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// 신규 아이디 추천

string solution(string new_id) {
    string answer = "";
    stack <char> st;

    // 1단계
    for (int i = 0; i < new_id.size(); i++)
        if (new_id[i] >= 'A' && new_id[i] <= 'Z')
            new_id[i] += ('a' - 'A');

    // 2단계
    for (int i = 0; i < new_id.size(); i++)
        if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9')
            || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
            answer += new_id[i];

    // 3단계
    for (int i = 0; i < answer.size(); i++) {
        if (answer[i] == '.')
        {
            if (!st.empty()) {
                if (st.top() != '.')
                    st.push('.');
            }
            else {
                st.push('.');
            }
        }
        else
            st.push(answer[i]);
    }

    answer = "";
    while (!st.empty()) {

        // 4단계
        if ((answer.size() == 0 && st.top() == '.') || (st.size() == 1 && st.top() == '.')) {
            st.pop();
            continue;
        }

        answer += st.top();
        st.pop();
    }

    reverse(answer.begin(), answer.end());

    // 5단계
    if (answer.size() == 0)
        answer += "a";

    // 6단계
    if (answer.size() >= 16)
        answer = answer.substr(0, 15);

    while (answer.back() == '.')
        answer.pop_back();

    // 7단계
    while (answer.size() < 3)
        answer += answer.back();

    return answer;
}