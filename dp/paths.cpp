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

int main(){
    int n; cin>>n;
    double* solved = new double[n+1];
    for(int i = 0 ; i<n; i++)
        solved[i] = 0;
    double count = printPath(n,solved);
    cout<<count;
}