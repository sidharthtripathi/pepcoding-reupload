#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <set>
void comboSum(vector <int> arr, int target, vector <vector<int>> &ans, set<vector<int>> &seti , vector<int> picked = {}){
if(target<0){
    return;
}
if(target==0){
    sort(picked.begin(), picked.end());
    
        if(seti.find(picked) == seti.end()){
            seti.insert(picked);
            ans.push_back(picked); 
        }
          
    return; 

}


    for(int i = 0 ; i<arr.size(); i++){
        picked.push_back(arr[i]);
        int num = arr[i];
        arr.erase(arr.begin()+i);
        comboSum(arr,target-num,ans,seti,picked);
        arr.insert(arr.begin()+i,num);
        picked.pop_back();
    }
}


int main(){
int n; cin>>n;
vector<int> arr;
for(int i = 0 ; i<n; i++){
    int temp; cin>>temp;
    arr.push_back(temp);
}
int target; cin>>target;
vector <vector<int>> ans;
set <vector<int>> seti;
comboSum(arr,target,ans,seti);
for(int i = 0 ; i<ans.size() ; i++){
    for(int j = 0 ; j<ans[i].size() ; j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}

}   