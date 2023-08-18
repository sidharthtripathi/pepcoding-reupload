#include <iostream>
using namespace std;
void primeTillN(int n);
int main(int argc, char const *argv[])
{	int n; cin>>n;
	primeTillN(n);
}

bool isPrime(int n){
	for(int i = 2 ; i<n ; i++){
		if(n%2==0){
			
			return false;
		}
	}
	
	return true;

}

void primeTillN(int n){
	for(int i = 1 ; i<n ; i++){
		if(isPrime(i))
			cout<<i<<" ";
	}
	return;
}