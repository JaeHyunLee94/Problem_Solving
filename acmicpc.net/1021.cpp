#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;



int min_count_23(int to_be_out,int first ,vector<int>& is_out){
    
    int N=(int)is_out.size();
    
    int before=0;
    int after=1;
    int flag=1;
   
    int now=first;
    int count=0;
    
    while(count<N){
        
        if (now==to_be_out){
            flag=0;
            now=(now+1)%N;
            count++;
            continue;
        }
    
        if(flag==1 && is_out[now]==0){
            before++;
        }
        else if(flag==0 && is_out[now]==0) {
            after++;
        }
        
        
        
        now=(now+1)%N;
        count++;
    }
    
    return min(before,after);
    
}

int next_first(int to_be_out,vector<int>& is_out){
    
    int size=(int)is_out.size();
    int now=(to_be_out+1)%size;
    int count=0;
    
    while(is_out[now] && count <=size){
        
        now=(now+1)%size;
        count++;
    }
    
    return now;
    
    
}

int main(){
 
  
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> d_list(M,0);
    vector<int> is_out(N,0);
    
    for(int i=0;i<M;i++){
        int tmp;
        cin >> tmp;
        d_list[i]=tmp-1;
    }
    
    int count=0;
    int first=0;
    
    for(int n=0;n<M;n++){
        int to_be_out=d_list[n];
        
        count +=min_count_23(to_be_out,first, is_out);
        
        is_out[to_be_out]=1;
        first=next_first(to_be_out, is_out);
        
    }
    
    cout <<count<<'\n';
    
    
    return 0 ;
    
}
