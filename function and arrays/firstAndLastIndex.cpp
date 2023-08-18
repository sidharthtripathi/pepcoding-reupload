#include <iostream>
using namespace std;

void firstIndex(int* a, int n, int k){

int s = 0 , e = n-1;
int fi = -1;
int mid = (s+e)/2;
while(s<=e){
	mid = (s+e)/2;
	if(a[mid]>k){
		e = mid -1;
	}
	else if(a[mid]<k){
		s = mid + 1;
	}
	else{
		e = mid-1;
		fi = mid;
	}
}
cout<<fi;


}

void lastIndex(int* a, int n, int k){

int s = 0 , e = n-1;
int li = -1;
int mid = (s+e)/2;
while(s<=e){
	mid = (s+e)/2;
	if(a[mid]>k){
		e = mid -1;
	}
	else if(a[mid]<k){
		s = mid + 1;
	}
	else{
		s = mid+1;
		li = mid;
	}
}
cout<<li;


}




int main(){
int n;cin>>n;
int* a = new int[n];
for(int i = 0 ; i<n; i++)
	cin>>a[i];
int k; cin>>k;
lastIndex(a,n,k);

}