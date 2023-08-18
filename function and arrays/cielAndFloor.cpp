#include <iostream>
using namespace std;

void floor(int* a, int n, int k){

int s = 0 , e = n-1;
int pFloor = a[0];
int pCiel = a[n-1];
while(s<=e){
	int mid = (s+e)/2;
	if(a[mid]<=k){
		pFloor = a[mid];
		s = mid+1;
	}
	else{
		pCiel = a[mid];
		e = mid - 1;
	}
}
cout<<pFloor<<" "<<pCiel;

}




int main(){
int n;cin>>n;
int* a = new int[n];
for(int i = 0 ; i<n; i++)
	cin>>a[i];
int k; cin>>k;
floor(a,n,k);

}