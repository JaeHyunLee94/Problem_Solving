#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    answer.resize(heights.size());
    answer[0]=0;
    for(int i = 1 ; i <heights.size();i++){
        int j=i-1;
        int now_height=heights[i];
        while(j>=0&&now_height>=heights[j]){
            j--;
        }
        answer[i]=j+1;
    }

    return answer;
}