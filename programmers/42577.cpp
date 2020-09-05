#include <vector>
#include <string>
using namespace std;

// 전화번호 목록

bool solution(vector<string> phone_book) {
    bool answer = true;

    for (int i = 0; i < phone_book.size(); ++i)
        for (int j = i + 1; j < phone_book.size(); ++j)
        {
            if (phone_book.at(j).length() > phone_book.at(i).length())
            {
                if (!strncmp(phone_book.at(j).c_str(), phone_book.at(i).c_str(), phone_book.at(i).length()))
                    return false;
            }
            else
            {
                if (!strncmp(phone_book.at(j).c_str(), phone_book.at(i).c_str(), phone_book.at(j).length()))
                    return false;
            }
        }
    
    return answer;
}
