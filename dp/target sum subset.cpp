#include <vector>
#include <iostream>
#include <climits>
using namespace std;


int targetSumSubset(vector<int> &arr, int target , int index =0 , int sum = 0){

if(index == arr.size()){
   // check if we found the sum
   if(sum == target) return true;
   else return false;
}

   // either pick where you stand
   sum = sum + arr[index];
   bool resultL = targetSumSubset(arr,target,index+1,sum);
   if(resultL) return true;
   // or don't pick the index where you stand
   sum = sum - arr[index];
   bool resultR = targetSumSubset(arr,target,index+1,sum);
   if(resultR) return true;

   return false;

}


int main(){
   int n; cin>>n;
   vector<int> arr;
   for(int i = 0 ; i<n; i++){
      int temp;cin>>temp;
      arr.push_back(temp);
   }
   int target; cin>>target;

   cout<<targetSumSubset(arr,target);
   
   
}