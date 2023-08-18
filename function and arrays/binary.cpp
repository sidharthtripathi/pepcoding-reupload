#include <iostream>
using namespace std;

int binary(int* a, int n, int k){

int s = 0, e = n-1;
while(s<=e){
	int mid = (s+e)/2;
	if(k>a[mid])
		s = mid + 1;
	else if(k<a[mid])
		e = mid - 1;
	else
		return mid;
}
return -1;



}




int main(){
int n;cin>>n;
int* a = new int[n];
for(int i = 0 ; i<n; i++)
	cin>>a[i];
int k; cin>>k;
cout<<binary(a,n,k);

}