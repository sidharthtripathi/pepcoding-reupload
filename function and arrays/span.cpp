#include <iostream>
using namespace std;
int span(int* a,int n){
	int min = a[0],max=a[0];
	for(int i = 0 ; i<n ; i++){
		if(a[i]<min)
			min = a[i];
		if(a[i]>max)
			max = a[i];
	}
	return max-min;


}

int main(){
int n;cin>>n;
int* a = new int[n];
for(int i = 0 ; i<n; i++)
	cin>>a[i];

cout<<span(a,n);

}