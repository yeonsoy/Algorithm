#include <string>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

// 신고 결과 받기

vector<string> split_space(string str)
{
    string id = "";
    string report_id = "";
    bool next_id = false;

    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == ' ')
        {
            next_id = true;
            continue;
        }

        if (!next_id)
            id += str[i];
        else
            report_id += str[i];
    }

    return { id, report_id };
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    answer.resize(id_list.size());
    unordered_map <string, set<string>> id_to_report;
    unordered_map <string, int> report_count;
    unordered_map <string, int> id_index;
    vector<string> suspend_id;

    for (int i = 0; i < id_list.size(); ++i)
    {
        auto const& id = id_list[i];
        id_index[id] = i;
        id_to_report[id] = {};
    }

    // id_to_report[아이디] = 신고한 아이디
    for (const auto& r : report)
    {
        auto split_list = split_space(r);
        id_to_report[split_list[0]].insert(split_list[1]);
    }

    // report_count[신고된 아이디] = 신고된 횟수
    for (auto it = id_to_report.begin(); it != id_to_report.end(); ++it)
    {
        const auto& id_report_set = id_to_report[it->first];
        for (auto iter = id_report_set.begin(); iter != id_report_set.end(); ++iter)
            report_count[*iter] ++;
    }

    // k번 이상 신고된 아이디 리스트
    for (auto it = report_count.begin(); it != report_count.end(); ++it)
        if (it->second >= k)
            suspend_id.push_back(it->first);

    for (auto it = id_to_report.begin(); it != id_to_report.end(); ++it)
    {
        const auto& id_report_set = id_to_report[it->first];

        for (auto suspend : suspend_id)
        {
            auto iter = id_report_set.find(suspend);
            if (iter != id_report_set.end())
                answer[id_index[it->first]]++;
        }
    }

    return answer;
}