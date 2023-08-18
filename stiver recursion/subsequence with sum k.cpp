#include <iostream>
using namespace std;
#include <vector>
void subWithSumK(int* arr ,int n , int k , vector<int> ans = {}){
if(n<=0){
    int sum = 0;
    for(int i =0; i<ans.size() ; i++){
        sum = sum + ans[i];
        // cout<<ans[i]<<" ";
    }
    if(sum == k){
        for(int i =0; i<ans.size() ; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    } 
    
    return;
}

ans.push_back(arr[0]);
subWithSumK(arr+1,n-1,k,ans);
ans.pop_back();
subWithSumK(arr+1,n-1,k,ans);


}


int main(){

int a[] = {1,2,3};
int target; cin>>target;
subWithSumK(a,3,target);

}