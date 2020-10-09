#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 랭킹전 대기열

typedef pair<int, string> player;
int p, m;
vector <player> players;
vector <player> rooms[301];

bool compare(player a, player b) {
    return a.second < b.second;
}

int main() {
    
    cin >> p >> m;
    
    int level;
    string nick;
    for(int i = 0; i<p; i++)
    {
        cin >> level >> nick;
        players.push_back({level, nick});
    }
    
    int idx = 0;
    int room_count = 0;
    
    while(true) {
        
        int temp = idx;
        for(int i = 0; i<room_count; i++) {
            if(rooms[i].size() == m) continue;
            if(rooms[i][0].first - 10 <= players[idx].first && players[idx].first <= rooms[i][0].first + 10) {
                rooms[i].push_back(players[idx]);
                idx++;
                break;
            }
        }
        
        if(temp == idx) {
            rooms[room_count].push_back(players[idx]);
            idx++;
            room_count ++;
        }
        
        if(idx == players.size()) break;
    }
    
    for(int i = 0; i<room_count; i++) {
        
        sort(rooms[i].begin(), rooms[i].end(), compare);
        
        if(rooms[i].size() == m) cout << "Started!\n";
        else cout << "Waiting!\n";
        
        for(int j = 0; j<rooms[i].size(); j++)
            cout << rooms[i][j].first << " " << rooms[i][j].second << "\n";
        
    }
    
    
    return 0;
}
