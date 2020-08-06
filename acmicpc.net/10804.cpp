//
//  10804.cpp
//  PS_xcode
//
//  Created by 이재현 on 2020/07/28.
//  Copyright © 2020 이재현. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    
    
    vector<int> arr(20,0);
    
    for(int i=0;i<20;i++){
        arr[i]=i;
    }
    
    
    for(int i=0;i<10;i++){
        int start,end;
        cin >> start>>end;
        
        reverse(arr.begin()+start-1, arr.begin()+end);
    }
    
    for(auto e: arr) cout << e+1<< " ";
    
    
    return 0;
}
