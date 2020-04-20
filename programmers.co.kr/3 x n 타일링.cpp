#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;

    vector<long long> table1(n+1,0);
    vector<long long> table2(n+1,0);
    vector<long long> table3(n+1,0);

    table1[2]=3;
    table2[3]=4;
    table3[2]=1;


    for(int i=4;i<n+1;i++){
        table1[i]=(table1[i-2]%1000000007+(2*table2[i-1])%1000000007)%1000000007;
        table2[i]=(table1[i-1]%1000000007+table3[i-1]%1000000007)%1000000007;
        table3[i]=table2[i-1];
    }
    answer=table1[n];
    return answer;
}

