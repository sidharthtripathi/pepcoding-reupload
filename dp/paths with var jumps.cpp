#include <iostream>
using namespace std;

void toTheTop(int* arr , int n){
int m = n+1;
int* dp = new int[m];


dp[m-1] = 1;
for(int i = m-2 ; i>=0 ; i--){

    int jumps = arr[i];
    int ans = 0;
    for(int j = 1 ; j<=jumps ; j++){
        ans = ans + dp[i+j];
    }
    dp[i] = ans;
}

cout<<dp[0];


}


int main(){

int n; cin>>n;
int* arr = new int[n];
for(int i = 0 ; i<n ; i++)
    cin>>arr[i];

toTheTop(arr,n);

}