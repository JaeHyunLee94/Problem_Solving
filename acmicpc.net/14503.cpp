//
//  14503.cpp
//  PS_xcode
//
//  Created by 이재현 on 2020/08/07.
//  Copyright © 2020 이재현. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};

int left(int dir){
    return (dir+3)%4;
}
int back(int dir){
    return (dir+2)%4;
}


int find_sol(vector<vector<int>>& table,int r,int c,int dir){
    
    int N=(int)table.size();
    int M=(int)table[0].size();
    
    int nowy=r;
    int nowx=c;
    int nowdir=dir;
    int cnt=0;
    int flag=1;
    int rot_cnt=0;
    
    while(flag){
        
        int lefty=nowy+dy[left(nowdir)];
        int leftx=nowx+dx[left(nowdir)];
        
        int backy=nowy+dy[back(nowdir)];
        int backx=nowx+dx[back(nowdir)];
        
        if(table[nowy][nowx]==0){
            table[nowy][nowx]=2;
            cnt++;
        }
        
        if(rot_cnt==4){
            
            if(backy<N && backy>=0 && backx<M && backx>=0 && table[backy][backx]!=1){
                nowx=backx;
                nowy=backy;
                rot_cnt=0;
                continue;
            }
            else{
                flag=0;
                continue;
            }
          
            
        }
        
       
        if(lefty<N && lefty>=0 && leftx>=0 && leftx<M && table[lefty][leftx]==0){
            
            nowx=leftx;
            nowy=lefty;
            nowdir=left(nowdir);
            rot_cnt=0;
            continue;
           
       
        }else{
            nowdir=left(nowdir);
            rot_cnt++;
            continue;
            
        }
        
        
        
        
    }
    
    
    return cnt;
}


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    int N,M;
    cin >> N >> M;
    int r,c,dir;
    cin >> r >> c >> dir;
    
    vector<vector<int>> table(N,vector<int>(M,0));
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int tmp;
            cin >>tmp;
            table[i][j]=tmp;
        
            
        }
    }
    
    
    cout <<find_sol(table, r, c, dir)<<'\n';
    
    
    
    
    
    return 0;
}
