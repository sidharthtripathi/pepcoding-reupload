#include <bits/stdc++.h>


int maxNonAdj(vector<int> &arr , int n , int index , int* dp){
   if(index == 0) return arr[index];
   if(index<0) return 0;
   if(dp[index]!=-1) return dp[index];

   // picking up element at index
   int pick = arr[index] + maxNonAdj(arr,n,index-2,dp);
   int nonPick = 0 + maxNonAdj(arr,n,index-1,dp);
   int ans =  max(pick,nonPick);
   dp[index] = ans;
   return ans;

}


int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code her  
    int* dp = new int[nums.size()];
    for(int i = 0 ; i<nums.size() ; i++)
        dp[i] = -1;
    return maxNonAdj(nums, nums.size(), nums.size()-1,dp);

}