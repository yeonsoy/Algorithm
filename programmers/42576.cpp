#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 완주하지 못한 선수

string solution(vector<string> participant, vector<string> completion) {

   string answer = "";

   sort(participant.begin(), participant.end());
   sort(completion.begin(), completion.end());

   for (int i = 0; i < participant.size() ; i++)
   {
      if (participant[i] != completion[i])
          return participant[i];
   }

   return answer;
}
