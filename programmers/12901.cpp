#include <string>
#include <vector>
using namespace std;

// 2016년

string solution(int a, int b) {
    string week [] = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };
    int mon [] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sum = 0;
    
    for(int i =0; i<a - 1; i++)
        sum += mon[i];

    sum += b - 1;

    return week[sum % 7];
}
