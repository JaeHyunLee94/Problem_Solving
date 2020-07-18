//
// Created by 이재현 on 2020/04/22.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int vowel_num=0;
int consonance_num=0;
int L=0;
int C=0;

bool check_vowel(char c){
    if (c=='a' || c=='e'|| c=='i'|| c=='o'|| c=='u') return true;
    else return false;
}


void solution(int now,vector<char>& list,vector<char>& stack){
    int str_len=stack.size();
    if(str_len==L){
        if(vowel_num<1 || consonance_num <2){
            return;
        }
        else{
            for(auto& n: stack) cout << n;
            cout << '\n';
            return;
        }
    }

    for(int i=now;i<C;i++){
        bool is_vowel=check_vowel(list[i]);

        is_vowel ? vowel_num++:consonance_num++;
        stack.push_back(list[i]);
        solution(i+1,list,stack);
        stack.pop_back();
        is_vowel ? vowel_num--: consonance_num--;
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> L >> C;

    vector<char> list(C,0);
    vector<char> stack;



    for(int i=0;i<C;i++) {
        char tmp;
        cin >> tmp;
        list[i]=tmp;

    }
    sort(list.begin(),list.end());
    solution(0,list,stack);

    return 0;
}

