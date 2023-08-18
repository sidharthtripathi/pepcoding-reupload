#include <iostream>
using namespace std;
#include <vector>
#include <set>
void NoDupsubset(vector <int> arr , vector<vector<int>> &setOfSubsets , set <vector<int>> &uniqueSet, vector <int> picked){

if(arr.size()==0){
    // check if subset is already there
    if(uniqueSet.find(picked) == uniqueSet.end()){
        uniqueSet.insert(picked);
        setOfSubsets.push_back(picked);
    }
    return;
}

    picked.push_back(arr[0]);
    arr.erase(arr.begin());
    NoDupsubset(arr,setOfSubsets,uniqueSet,picked);
    picked.pop_back();
    NoDupsubset(arr,setOfSubsets,uniqueSet,picked);




}




int main(){

vector<int> arr;
int n; cin>>n;
for(int i =0 ; i<n ; i++){
    int temp; cin>>temp;
    arr.push_back(temp);
}
vector <int> picked;
set <vector<int>> uniqueSet;
vector<vector<int>> ans;
NoDupsubset(arr,ans,uniqueSet,picked);

for(int i = 0 ; i<ans.size() ; i++){
    for(int j = 0 ; j<ans[i].size() ; j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}


}