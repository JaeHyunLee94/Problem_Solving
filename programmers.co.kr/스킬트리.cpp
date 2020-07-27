#include <string>
#include <vector>
#include <iostream>



using namespace std;

int solution(string skill, vector<string> skill_trees) {
    
    
    vector<int> in_degree(26,0);
    
    for(int i=0;i<skill.size();i++){
        if(i!=0){
            in_degree[skill[i]-'A']++;
        }
        
    }
    
    
    int answer = 0;
    
    for(int i=0;i<skill_trees.size();i++){
        int k=0;
        vector<int> tmp_indegree(in_degree);
        string target=skill_trees[i];
        
        int flag=1;
        
        for(int j=0;j<target.size();j++){
            
            if(tmp_indegree[target[j]-'A']) {
                flag=0;
                break;
            }
            if(target[j]==skill[k]){
                k++;
                tmp_indegree[skill[k]-'A']=0;
                
            }
            
        }
        
        if(flag) answer++;
        
    }

    return answer;
}


