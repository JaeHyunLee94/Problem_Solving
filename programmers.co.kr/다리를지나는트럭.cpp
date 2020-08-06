#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {

    int t=0;
    int now_weight=0;
    
    queue<int> wait;
    queue<int> now;
    
    for(auto& e: truck_weights){
        wait.push(e);
    }
    for(int i=0;i<bridge_length;i++){
        now.push(0);
    }
    
    while(!wait.empty()){
        t++;
        int next=wait.front();
        if(now_weight+next-now.front()<=weight){
            wait.pop();
            now_weight+=next-now.front();
            now.push(next);
            now.pop();
        }
        else {
            now_weight-=now.front();
            now.push(0);
            now.pop();
        }
        
        
    }
    
    
    return t+bridge_length;
}


int main(){
    /*
     2    10    [7,4,5,6]    8
     100    100    [10]    101
     100    100    [10,10,10,10,10,10,10,10,10,10]    110
     */
    
    vector<int> t1{7,4,5,6};
    vector<int> t2{10};
    vector<int> t3{10,10,10,10,10,10,10,10,10,10};
    
    cout <<solution(2, 10, t1)<<'\n';
    cout <<solution(100, 100, t2)<<'\n';
    cout <<solution(100, 100, t3)<<'\n';
    
    
    
    return 0 ;
    
}
