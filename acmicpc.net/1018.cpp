//
//  1018.cpp
//  PS_xcode
//
//  Created by 이재현 on 2020/08/03.
//  Copyright © 2020 이재현. All rights reserved.
//


#include <iostream>
#include <vector>

using namespace std;

int INF=98765421;

int find_min(vector<vector<int>>& table,int starty,int startx){
    
    int cnt1=0;
    int cnt2=0;
    
    
        
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if((i+j)%2==0 && table[starty+i][startx+j]==0){
                    cnt1++;
                }else if((i+j)%2==1 && table[starty+i][startx+j]==1){
                    cnt1++;
                }
            }
        }
        
    
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if((i+j)%2==0 && table[starty+i][startx+j]==1){
                    cnt2++;
                }else if((i+j)%2==1 && table[starty+i][startx+j]==0){
                    cnt2++;
                }
            }
        }
        
        
        
    
    return min(cnt1,cnt2);
    
    
    
    
    
}
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    int row,col;
    cin >> row >> col;
    vector<vector<int>> table(row,vector<int>(col,0));
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            char tmp;
            cin >> tmp;
            table[i][j]= (tmp=='W') ? 0 : 1;
 
        }
    }
    
    int count=INF;
    
    for(int i=0;i<=row-8;i++){
        for(int j=0;j<=col-8;j++){
            
            count=min(count,find_min(table,i,j));
            
            
        }
    }
    
    cout <<count<<'\n';
    
    
    
    
    return 0;
}
