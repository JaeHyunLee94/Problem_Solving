//
// Created by 이재현 on 2020/07/20.
//

#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int inf=987654321;
int solution(int n, vector<vector<int>> edge) {

    vector<vector<int>> adj_list(n+1);
    vector<int> dis(n+1,inf);
    for(auto& m : edge){
        adj_list[m[0]].push_back(m[1]);
        adj_list[m[1]].push_back(m[0]);

    }
    queue<int> q;

    q.push(1);
    dis[1]=0;

    while(!q.empty()){
        int next=q.front();
        q.pop();

        for(auto& m: adj_list[next]){
            if(dis[m]==inf){
                dis[m]=dis[next]+1;
                q.push(m);
            }
        }

    }

    int max=-1;
    int count=0;

    for(int i=1;i<=n;i++){
        if(dis[i]> max){
            count=1;
            max=dis[i];
        }
        else if (dis[i]==max){
            count++;
        }


    }

    int answer = 0;
    answer=count;
    return answer;
}

int main(){
    //[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2
    vector<vector<int>> edge;
    edge.push_back(vector<int>{3,6});
    edge.push_back(vector<int>{4,3});
    edge.push_back(vector<int>{3,2});
    edge.push_back(vector<int>{1,3});
    edge.push_back(vector<int>{1,2});
    edge.push_back(vector<int>{2,4});
    edge.push_back(vector<int>{5,2});

    int n =6;


    cout << solution(6,edge);









}