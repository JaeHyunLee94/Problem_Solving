//
// Created by 이재현 on 2020/04/23.
//
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct tag{
    int importancy;
    bool is_tracked;
};



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;

    for(int t=0;t<test_case;t++){


        int N,M;
        cin >> N >> M;
        int order=0;

        queue<tag> q;
        vector<int> sorted(N);
        for(int i=0;i<N;i++){
            int tmp;
            cin >> tmp;
            sorted[i]=tmp;
            i==M ? q.push(tag{tmp,true}) : q.push(tag{tmp,false});
        }
        sort(sorted.begin(),sorted.end());


        while(!(q.front().is_tracked && q.front().importancy>=sorted.back())){
            tag nextval=q.front();
            q.pop();

            if(nextval.importancy >= sorted.back()){
                order++;
                sorted.pop_back();
            }else{
                q.push(nextval);
            }
        }


        cout << order+1<<'\n';


    }


    return 0;
}

