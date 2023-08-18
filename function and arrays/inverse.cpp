#include <iostream>
using namespace std;

void inverse(int* a, int n){
int* b = new int[n];
for(int i = 0 ; i<n ; i++){
	b[a[i]] = i;
}
for(int i = 0 ; i<n ; i++)
cout<<b[i]<<" ";
}




int main(){
int n;cin>>n;
int* a = new int[n];
for(int i = 0 ; i<n; i++)
	cin>>a[i];

inverse(a,n);

}