#include <string>
#include <vector>
using namespace std;

// 모의고사

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int ans1[] = { 1, 2, 3, 4, 5 };
    int ans2[] = { 2, 1, 2, 3, 2, 4, 2, 5 };
    int ans3[] = { 3, 3, 1, 1 ,2, 2, 4, 4, 5, 5 };

    int ans1_count = 0;
    int ans2_count = 0;
    int ans3_count = 0;

    for (int i = 0; i < answers.size(); i++)
    {
        if (answers.at(i) == ans1[i % 5])
            ans1_count++;
        if (answers.at(i) == ans2[i % 8])
            ans2_count++;
        if (answers.at(i) == ans3[i % 10])
            ans3_count++;
    }

    if (ans1_count > ans2_count && ans1_count > ans3_count)
        answer.push_back(1);
    if (ans2_count > ans1_count && ans2_count > ans3_count)
        answer.push_back(2);
    if (ans3_count > ans1_count && ans3_count > ans2_count)
        answer.push_back(3);

    if (ans1_count == ans2_count && ans1_count == ans3_count)
    {
        answer.push_back(1);
        answer.push_back(2);
        answer.push_back(3);
    }
    if (ans2_count == ans1_count && ans2_count > ans3_count)
    {
        answer.push_back(1);
        answer.push_back(2);
    }
    if (ans3_count == ans1_count && ans3_count > ans2_count)
    {
        answer.push_back(1);
        answer.push_back(3);
    }

    if (ans2_count > ans1_count && ans2_count == ans3_count)
    {
        answer.push_back(2);
        answer.push_back(3);
    }

    return answer;
}
