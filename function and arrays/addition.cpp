#include <iostream>
using namespace std;
void sum(int* a , int n , int* b , int m){
	int o = n>m ? n+1 : m+1;
	int* ans = new int[o];
	// setting all zeroes
	for(int i = 0 ; i<o ; i++)
		ans[i] = 0;


	int i = n-1 , j = m-1;
	int k  = o-1 ;
	int c = 0;
	while(i>=0 and j>=0){
		ans[k] = (a[i] + b[j] + c)%10;
		c = (a[i] + b[j])/10;
		k--;
		i--;
		j--;
	}
	if(i<0){
		while(j>=0){
		ans[k] = (b[j] + c)%10;
		c =  (b[j] + c)/10;
		k--;
		j--;
	}

	}
	else if(j<0){
		while(i>=0){
		ans[k] = (a[i] + c)%10;
		c =  (a[i] + c)/10;
		k--;
		i--;
	}
	}
	if(c>0)
		ans[k] = c;

	// printing sum
	int pos = 0;
	while(ans[pos]==0)
		pos++;
	for(int i = pos ; i<o ; i++)
		cout<<ans[i];


}

int main(){
int n;cin>>n;
int* a = new int[n];
for(int i = 0 ; i<n; i++)
	cin>>a[i];

int m; cin>>m;
int* b = new int[m];
for(int i = 0 ; i<m ; i++)
	cin>>b[i];

sum(a,n,b,m);

}