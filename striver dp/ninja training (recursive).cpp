#include <bits/stdc++.h>
using namespace std;

void answer(int stDay,int notToPick, int n , vector<vector<int>> &points , int ans ,int &maxAns){
    // if we reach to the end
    if(stDay == n){
        maxAns = max(maxAns,ans);
        return;
    }


    // pick anyone
    for(int i = 0 ; i<3 ; i++){
        if(i!=notToPick){
            ans = ans + points[stDay][i];
            answer(stDay+1,i,n,points,ans,maxAns);
            ans = ans - points[stDay][i];
        }
    }

}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    int maxAns = INT_MIN;
    answer(0,-1,n,points,0,maxAns);
    return maxAns;
    
}