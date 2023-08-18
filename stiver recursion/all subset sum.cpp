#include <iostream>
using namespace std;
#include <vector>
void subsetSum(vector <int> arr , vector <int> &sums, vector<int> picked={}){

if(arr.size()==0){
    int total = 0;
    for(int i = 0 ; i<picked.size() ; i++)
        total = total + picked[i];
    sums.push_back(total);
    return;
}

    picked.push_back(arr[0]);
    arr.erase(arr.begin());
    subsetSum(arr,sums,picked);
    picked.pop_back();
    subsetSum(arr,sums,picked);




}


int main(){

vector<int> arr;
int n; cin>>n;
for(int i =0 ; i<n ; i++){
    int temp; cin>>temp;
    arr.push_back(temp);
}
vector<int> ans;
subsetSum(arr,ans);
for(int i = 0 ; i<ans.size() ; i++)
cout<<ans[i]<<" ";


}