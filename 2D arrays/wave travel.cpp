#include <iostream>
using namespace std;


int main(){
int m,n;
cin>>m>>n;
int a[m][n];
for(int i = 0 ; i<m ; i++){
	for(int j = 0 ; j<n ; j++){
		cin>>a[i][j];
	}
}

// printing
for(int j = 0 ; j<n ; j++){

	// printing top to down
	if(j%2==0)
	for(int i = 0 ; i<m ; i++)
		cout<<a[i][j]<<" ";

	// printing down to top
	if(j%2==1)
	for(int i = m-1 ; i>=0 ; i--)
		cout<<a[i][j]<<" ";

	cout<<endl;

}


}