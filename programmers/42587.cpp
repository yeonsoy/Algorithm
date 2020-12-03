#include <string>
#include <vector>
#include <queue>
using namespace std;

// 프린터

int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue <int> que;
    priority_queue <int> pq;

    for (int i = 0; i < priorities.size(); i++)
    {
        que.push(i);
        pq.push(priorities[i]);
    }

    while (!que.empty())
    {
        int size = que.size();
        while (size--)
        {
            int idx = que.front();
            que.pop();
            if (pq.top() == priorities[idx])
            {
                pq.pop();
                answer++;

                if (idx == location)
                    return answer;
                else
                    continue;
            }

            que.push(idx);
        }
    }

    return answer;
}