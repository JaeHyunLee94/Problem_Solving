//
// Created by 이재현 on 2020/07/19.
//


#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 0;
    cin >> n;

    vector<vector<int>> arr(n + 1);

    for (int i = 1; i <= n; i++) {
        int x, color;
        cin >> x >> color;
        arr[color].push_back(x);
    }


    for (int i = 1; i <= n; i++) {
        sort(arr[i].begin(), arr[i].end());
    }
    long long sum = 0;

    for (int i = 1; i <= n; i++) {
        if(arr[i].size()<2) continue;

        for(int j=0;j<arr[i].size();j++){
            if(j==0) {
                sum+=(arr[i][j+1]-arr[i][j]);


            }else if(j==arr[i].size()-1){
                sum+=(arr[i][j]-arr[i][j-1]);

            }else{
                sum+=min(arr[i][j]-arr[i][j-1],arr[i][j+1]-arr[i][j]);

            }
        }
    }

    cout << sum;

    return 0;


}