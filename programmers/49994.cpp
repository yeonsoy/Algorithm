#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 방문 길이

typedef pair<int, int> point;
point dir[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
bool visited[11][11][11][11];

int solution(string dirs) {
    int answer = 0;
    
    point cur = {5, 5};
    
    for(char d : dirs) {
        
        point next = cur;
        if(d == 'U')
            next = {cur.first + dir[0].first, cur.second + dir[0].second};
        else if(d == 'D')
            next = {cur.first + dir[1].first, cur.second + dir[1].second};
        else if(d == 'R')
            next = {cur.first + dir[2].first, cur.second + dir[2].second};
        else
            next = {cur.first + dir[3].first, cur.second + dir[3].second};
        
        if(next.first < 0 || next.first > 10 || next.second < 0 || next.second > 10)
            continue;
        
        if(!(visited[cur.first][cur.second][next.first][next.second] ||
          visited[next.first][next.second][cur.first][cur.second]))
            answer++;
        
        visited[cur.first][cur.second][next.first][next.second] = true;
        cur = next;
    }
    
    return answer;
}

int main()
{
    cout << solution("ULURRDLLU") << endl; // 7
    cout << solution("LULLLLLLU") << endl; // 7
}
