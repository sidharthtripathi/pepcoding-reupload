#include <iostream>
using namespace std;
#include <vector>
int NofsubWithSumK(int* arr ,int n , int k ,int ans =0){

if(n<=0){
    if(ans == k){
        
      return 1;
    }
    
    return 0;
}

ans = ans + arr[0];

int a = NofsubWithSumK(arr+1,n-1,k,ans);
ans = ans - arr[0];

int b = NofsubWithSumK(arr+1,n-1,k,ans);

return a+b;

}


int main(){
int n; cin>>n;
int* arr  = new int[n];
for(int i = 0 ; i<n; i++)
cin>>arr[i];
int target; cin>>target;
cout<<NofsubWithSumK(arr,n,target);

}