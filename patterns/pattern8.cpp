#include <iostream>

using namespace std;
void pattern(int n){


for(int i = 1 ; i<=n; i++){
	for(int j = 1 ; j<=n ; j++){
		if(i+j == n+1 or i==j)	
			cout<<"*\t";
		else
			cout<<"\t";
	}
	cout<<endl;
}

}
int main(int argc, char const *argv[])
{	int n; cin>>n;
	pattern(n);


}




