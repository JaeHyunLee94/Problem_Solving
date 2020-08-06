//
//  1043.cpp
//  PS_xcode
//
//  Created by 이재현 on 2020/08/01.
//  Copyright © 2020 이재현. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    int N,M;
    cin >> N >> M;
    
    vector<vector<int>> arr(M);
    
    
    int know_num=0;
    cin >> know_num;
    vector<int> know_list(know_num,0);
    for(int i=0;i<know_num;i++){
        int tmp;
        cin >> tmp;
        know_list[i]=tmp-1;
        
    }
    
    for(int i=0;i<M;i++){
        int party_num;
        cin >> party_num;
        for(int j=0;j<party_num;j++){
            int num;
            cin >> num;
            arr[i].push_back(num-1);
        }
        
    }
    
    
    
    
    return 0;
}
