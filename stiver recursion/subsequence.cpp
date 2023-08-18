#include <iostream>
using namespace std;
#include <vector>
void printSub(int* a , int n, vector <int> ans = {}){

if(n<=0){
for(int i = 0 ; i<ans.size(); i++){
    cout<<ans[i]<<" ";
}
if(ans.size()==0)
cout<<"{}";
cout<<endl;
return;
}


ans.push_back(a[0]);
printSub(a+1,n-1,ans);
ans.pop_back();
printSub(a+1,n-1,ans);



}

int main(){

int a[] = {3,1,2};
printSub(a,3);

}