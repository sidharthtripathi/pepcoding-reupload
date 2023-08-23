#include <vector>
#include <iostream>
#include <climits>
using namespace std;

int maxNonAdj(int* arr , int n , int index){
   if(index == 0) return arr[index];
   if(index<0) return 0;

   // picking up element at index
   int pick = arr[index] + maxNonAdj(arr,n,index-2);
   int nonPick = 0 + maxNonAdj(arr,n,index-1);
   return max(pick,nonPick);

}


int main(){
   int n; cin>>n;
   int* arr = new int[n];
   for(int i = 0 ; i<n ; i++){
      cin>>arr[i];
   }
   cout<<maxNonAdj(arr,n,n-1);

}