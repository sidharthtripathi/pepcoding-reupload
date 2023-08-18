#include <iostream>
using namespace std;
void swap(int* a , int i , int j){

	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void reverse(int* a , int n){
	int i = 0 , j = n-1;
	while(i<=j){
		swap(a,i,j);
		i++;
		j--;
	}

}

void rotate(int* a , int n , int k){
	if(k<0)
		k = n + k;
	k = k%n;
	reverse(a,n-k);
	reverse(a+(n-k),k);
	reverse(a,n);



}




int main(){
int n;cin>>n;
int* a = new int[n];
for(int i = 0 ; i<n; i++)
	cin>>a[i];
int k; cin>>k;
rotate(a,n,k);
for(int i = 0 ; i<n ; i++)
cout<<a[i]<<" ";

}