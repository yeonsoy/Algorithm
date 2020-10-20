#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// 인형들

int N, K;
vector <double> d;

int main() {
    
    scanf("%d %d", &N, &K);
    d.resize(N);
    
    for(int i = 0; i<N; i++)
        scanf("%lf", &d[i]);
    
    int idx = 0;
    int temp = K;
    double sum = 0;
    double avg = 0;
    double sd = 0;
    double answer = 2e9;
    
    while(temp <= N) {
        
        if(idx + temp <= N) {
            for(int i = idx; i < idx + temp; i++)
                sum += d[i];
        
            avg = sum / temp;
            
            for(int i = idx; i < idx + temp; i++)
                sd += (d[i] - avg) * (d[i] - avg);
            
            sd /= temp;
            sd = sqrt(sd);
            
            answer = min(sd, answer);
            sum = 0;
            sd = 0;
            idx++;
        }
        else {
            idx = 0;
            temp++;
        }
        
    }
    
    printf("%.11lf", answer);
    
    
    return 0;
}
