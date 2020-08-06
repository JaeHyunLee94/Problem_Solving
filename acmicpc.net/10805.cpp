//
//  10804.cpp
//  PS_xcode
//
//  Created by 이재현 on 2020/07/29.
//  Copyright © 2020 이재현. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;


int dp[51][51][51][51]={0};
int INF=987654321;

int find_sol(int h1,int w1,int h2,int w2){
    
    int& ret=dp[h1][w1][h2][w2];
    
    if(ret!=-1){
        return ret;
    }
    if(h1==0 || w1==0){
        return ret=0;
    }
    if(h1==w1 && (h2==0 || w2==0)){
        return ret=1;
    }
    int ans=INF;
    
    
    for(int i=1;i<h1;i++){
        if(i<h1-h2){
            ans=min(ans,find_sol(i,w1,0,0)+find_sol(h1-i, w1, h2, w2));
        }else if(i==h1-h2){
            ans=min(ans,find_sol(i,w1, 0, 0)+find_sol(h2, w1-w2, 0, 0));
        }else{
            ans=min(ans,find_sol(i,w1, i-(h1-h2), w2)+find_sol(h1-i, w1-w2, 0, 0));
        }
    }
    for(int j=1;j<w1;j++){
        if(j<w1-w2){
            ans=min(ans,find_sol(h1,j,0,0)+find_sol(h1, w1-j, h2, w2));
        }else if(j==w1-w2){
            ans=min(ans,find_sol(h1,j, 0, 0)+find_sol(h1-h2, w2, 0, 0));
        }else{
            ans=min(ans,find_sol(h1,j, h2, j-(w1-w2))+find_sol(h1-h2, w1-j, 0, 0));
        }
        
    }
    
    return ret=ans;
}



int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int h1,w1,h2,w2;
    
    cin >> h1 >> w1 >> h2 >> w2;
    
    
    memset(dp, -1, sizeof(dp));
    dp[1][1][0][0]=1;
     for (int i = 1; i <= 50; i++)
        {
            dp[i][i][0][0] = 1;
            dp[i][1][0][0] = i;
            dp[1][i][0][0]= i;
     
        }

    
    cout << find_sol(h1, w1, h2, w2)<<'\n';
    
   
    
    return 0;
}
