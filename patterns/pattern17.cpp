#include <iostream>

using namespace std;
void pattern(int n){
int str = 1;
for(int i = 1 ; i<=n ; i++){
	// priting spc or tail
	if(i==n/2+1){
		for(int j = 1 ; j<=n/2 ; j++)
			cout<<"*\t";
	}
	else{
		for(int j = 1; j<=n/2 ; j++)
			cout<<"\t";
	}

	for(int j = 1; j<=str ; j++)
		cout<<"*\t";

	cout<<endl;
	if(i>=n/2+1)
		str--;
	else
		str++;

}

}
int main(int argc, char const *argv[])
{	int n; cin>>n;
	pattern(n);


}





