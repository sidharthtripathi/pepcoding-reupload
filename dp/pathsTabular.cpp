#include <iostream>
using namespace std;
// possible jumsp are 1 , 2, 3
double printPath(int n,double* solved){
if(n<0)
    return 0;
if(n==0){
    return 1;
}

if(solved[n]!=0)
    return solved[n];


double x = printPath(n-1,solved);
double y = printPath(n-2,solved);
double z = printPath(n-3,solved);
solved[n] = x+y+z;
return x+y+z;


}

int printPathTab(int n){
int* a = new int[n+1];
a[0] = 1;

for(int i = 1 ; i<n+1; i++){
    if(i==1)
        a[i] = a[i-1];
    else if(i==2)
        a[i] = a[i-1] + a[i-2];
    else
        a[i] = a[i-1] + a[i-2] + a[i-3];
}

return a[n];


}

int main(){
    int n; cin>>n;
    cout<<printPathTab(n);
}