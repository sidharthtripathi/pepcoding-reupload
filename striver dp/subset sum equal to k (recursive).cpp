#include <bits/stdc++.h> 

bool answer(int index,int n, int target , vector<int> &arr){
    if(index == n){
        if(target == 0){
            return true;
        }
        else return false;
    }

    if(target == 0) return true;

    // travelling
    // pick
    target = target - arr[index];
    bool lc = answer(index+1,n,target,arr);
    if(lc) return lc;

    // not pick
    target = target + arr[index];
    bool rc = answer(index+1,n,target,arr);
    return rc;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    bool ans = answer(0,n,k,arr);
}