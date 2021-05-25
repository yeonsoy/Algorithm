#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// H-Index

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end());

    int i = 0;
    while (i < citations.size()) {
        if (answer < citations[i]) {
            if (answer < citations.size() - i)
                answer++;
            else
                break;
        }
        else
            i++;
    }

    return answer;
}