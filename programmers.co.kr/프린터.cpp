#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>


using namespace std;

struct element{
    int priority;
    int is_key;
};

int solution(vector<int> priorities, int location) {
    
    queue<element> qq;
    
    for(int i=0;i<priorities.size();i++){
        if(i==location){
            qq.push({priorities[i],1});
        }
        else qq.push({priorities[i],0});
    }
    
    
    
    
    
    int count=0;

    element next=qq.front();
    
    sort(priorities.begin(),priorities.end());
    int max_index=priorities.size()-1;

    
    while(!qq.empty()){
    
        if(next.priority==priorities[max_index]){
            count++;
            qq.pop( );
            max_index--;
            
            if(next.is_key) break;
            
        }
        else{
            element n=qq.front();
            qq.pop();
            qq.push(n);
            
        }
        
        next=qq.front();
    
        
    }
    
    
    
    return count;
}


int main(){
    
    
    //[2, 1, 3, 2]    2    1
    //[1, 1, 9, 1, 1, 1]    0    5
    
   
    vector<int> priorities{2, 1, 3, 2};
    vector<int> priorities2{1, 1, 9, 1, 1, 1};
    
    cout << solution(priorities, 2);
    cout << solution(priorities2, 0);
    
    return 0;
}
