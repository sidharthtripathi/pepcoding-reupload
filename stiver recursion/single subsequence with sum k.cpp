#include <iostream>
using namespace std;
#include <vector>
void subWithSumK(int* arr ,int n , int k , bool &flag,int ans =0, vector<int> arrAns={}){
if(flag)
    return;
if(n<=0){
    if(ans == k){
        flag = true;
        for(int i = 0 ; i<arrAns.size() ; i++){
            cout<<arrAns[i]<<" ";
        }
        cout<<endl;
    }
    
    return;
}

ans = ans + arr[0];
arrAns.push_back(arr[0]);
subWithSumK(arr+1,n-1,k,flag,ans,arrAns);
ans = ans - arr[0];
arrAns.pop_back();
subWithSumK(arr+1,n-1,k,flag,ans,arrAns);


}


int main(){
int n; cin>>n;
int* arr  = new int[n];
for(int i = 0 ; i<n; i++)
cin>>arr[i];
int target; cin>>target;
bool flag = false;
subWithSumK(arr,n,target,flag);

}