
//https://www.acmicpc.net/problem/2473

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

long long SUM(int a,int b,int c){
    return a+b+c;
}

long long ABS(int a){
    return a>0 ? a:-a;
}

using namespace std;

int main(int argc, char const *argv[])
{   
    vector<int> Liquid_list;

    int n=0;
    int tmp;
    cin>>n;

    for(int i=0;i<n;i++){

        cin>>tmp;
        Liquid_list.push_back(tmp);

    }
    sort(Liquid_list.begin(),Liquid_list.end());

    if(n==3||Liquid_list[0]>=0){
        cout<<Liquid_list[0]<<" "<<Liquid_list[1]<<" "<<Liquid_list[2];
        return 0;
    }
    if(Liquid_list[n-1]<=0){
        cout<<Liquid_list[n-3]<<" "<<Liquid_list[n-2]<<" "<<Liquid_list[n-1];
        return 0;
    }


    int liq_iter1,liq_iter2,liq_iter3;

    long long tmp_sum=Liquid_list[0]+Liquid_list[1]+Liquid_list[2];

    int liq_opt1=0;
    int liq_opt2=1;
    int liq_opt3=2;
    long long opt_sum=tmp_sum;

    for(int liq_iter1=0; liq_iter1<n-2;liq_iter1++){

            liq_iter3=n-1;

        for(int liq_iter2=liq_iter1+1;liq_iter2<n-1;liq_iter2++){


            while(1){

                if(liq_iter3<=liq_iter2) break;

                if(Liquid_list[liq_iter1]+Liquid_list[liq_iter2]+Liquid_list[liq_iter3] <= 0) break;

                liq_iter3--;

            }

            if(liq_iter3==liq_iter2){

                if(ABS(SUM(Liquid_list[liq_iter1],Liquid_list[liq_iter2],Liquid_list[liq_iter3+1])<=opt_sum)){

                    liq_opt1=liq_iter1;

                    liq_opt2=liq_iter2;

                    liq_opt3=liq_iter3+1;

                    opt_sum=ABS(SUM(Liquid_list[liq_iter1],Liquid_list[liq_iter2],Liquid_list[liq_iter3+1]));
                
                }
                
                
                

            }

            for(int liq4=liq_iter3-1 ; liq4 <= liq_iter3+1 ; liq4++){
                
                if(ABS(SUM(Liquid_list[liq_iter1],Liquid_list[liq_iter2],Liquid_list[liq4])<=opt_sum)){

                    liq_opt1=liq_iter1;

                    liq_opt2=liq_iter2;

                    liq_opt3=liq4;

                    opt_sum=ABS(SUM(Liquid_list[liq_iter1],Liquid_list[liq_iter2],Liquid_list[liq4]));
                
                }




            }    

        }


    }


    /* code */
    return 0;
}
