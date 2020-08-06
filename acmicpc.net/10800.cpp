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


struct ball{
    int index;
    int color;
    int size;
    int answer;
};

using namespace std;

bool cmp(const ball& a, const ball& b){
    
    if(a.size<b.size) return true;
    else if (a.size==b.size){
        return a.color<b.color;
    }
    else{
        return false;
    }
    
}




int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<ball> ball_arr(N);
    
    vector<int> color_byfar(N+1,0);

    for(int i=0;i<N;i++){
        
        int color;
        int size;
        cin >> color >> size;
        ball_arr[i].index=i;
        ball_arr[i].color=color;
        ball_arr[i].size=size;
        ball_arr[i].answer=0;
        
    }
    vector<ball> ball_arr_answer(ball_arr);
    sort(ball_arr.begin(),ball_arr.end(),cmp);
    
    int now_index=-1;
    int sum=0;
    
    for(int i=1;i<N;i++){
        
        if(ball_arr[i-1].size<ball_arr[i].size){
           
            for(int j=now_index+1 ;j<i;j++){
                sum+=ball_arr[j].size;
                color_byfar[ball_arr[j].color]+=ball_arr[j].size;
            }
            now_index=i-1;
        
            
        }
        ball_arr_answer[ball_arr[i].index].answer=sum-color_byfar[ball_arr[i].color];
        
        
    
    }
    
    
    for(auto& e : ball_arr_answer){
        cout <<e.answer<<'\n';
    }
    
    
    
    return 0;
}
