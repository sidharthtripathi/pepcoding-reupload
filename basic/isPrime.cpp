#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n; cin>>n;
	for(int i = 2 ; i<n ; i++){
		if(n%2==0){
			cout<<"Not prime";
			return 0;
		}
	}
	cout<<"Prime";
	return 0;
}