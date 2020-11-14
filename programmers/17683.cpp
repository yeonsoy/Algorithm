#include <string>
#include <vector>
#include <sstream>
#include <cstring>

using namespace std;

// 방금그곡

vector<string> Split(string str, char delimiter)
{
    vector<string> internal;
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, delimiter))
        internal.push_back(temp);

    return internal;
}

int getDiff(string a, string b)
{
    int a_hour = (a[0] - '0') * 10 + (a[1] - '0');
    int b_hour = (b[0] - '0') * 10 + (b[1] - '0');

    int a_min = (a[3] - '0') * 10 + (a[4] - '0');
    int b_min = (b[3] - '0') * 10 + (b[4] - '0');

    return (b_hour * 60 + b_min) - (a_hour * 60 + a_min);
}

string melody(string s)
{
    string res = "";
    int idx = 0;
    while (true)
    {
        if (idx >= s.size())
            break;

        string temp = "";
        if (s[idx] == 'C' || s[idx] == 'D' || s[idx] == 'F' || s[idx] == 'G' || s[idx] == 'A')
        {
            if (idx + 1 < s.size())
            {
                if (s[idx + 1] == '#')
                {
                    res += (s[idx] + 6);
                    idx += 2;
                    continue;
                }
            }
        }
        res += s[idx];

        idx++;
    }

    return res;
}

int getSameCount(string a, string b)
{
    vector <vector<int>> LCS(a.size() + 1, vector <int>(b.size() + 1, 0));
    int res = 0;
    for (int i = 1; i <= a.size(); i++)
        for (int j = 1; j <= b.size(); j++)
            if (a[i - 1] == b[j - 1])
            {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
                if (res < LCS[i][j])
                    res = LCS[i][j];
            }
    return res;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";

    int min = m.size();
    int max_same = 0;
    int max_diff = 0;
    string origin = melody(m);

    for (int i = 0; i < musicinfos.size(); i++)
    {
        vector <string> info = Split(musicinfos[i], ',');
        int diff = getDiff(info[0], info[1]);
        string temp = "";

        info[3] = melody(info[3]);

        for (int j = 0; j < diff; j++)
            temp += info[3][j % info[3].size()];

        int same = getSameCount(origin, temp);

        if (origin.size() > same)
            continue;

        if (diff > max_diff)
        {
            max_diff = diff;
            answer = info[2];
        }
    }

    return answer;
}