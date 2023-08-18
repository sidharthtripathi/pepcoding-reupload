#include <iostream>
using namespace std;
#include <vector>

void comboSum(int* arr, int n , int target, vector<int> picked = {}){
if(target <= 0){
    if(target==0){
    for(int i = 0 ; i<picked.size() ; i++){
        cout<<picked[i]<<" ";
    }
    cout<<endl;
}
    return;
}


    for(int i =0 ; i<n; i++){
        picked.push_back(arr[i]);
        comboSum(arr+i,n-i,target-arr[i],picked);
        picked.pop_back();
    }
}


int main(){
int n; cin>>n;
int* arr  = new int[n];
for(int i = 0 ; i<n; i++)
cin>>arr[i];
int target; cin>>target;
comboSum(arr,n,target);

}