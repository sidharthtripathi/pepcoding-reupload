#include <iostream>
using namespace std;
void digits(int n);
int main(int argc, char const *argv[])
{	int n; cin >> n;
	digits(n);
}

void digits(int n){
	
	while(n!=0){
		cout<<n%10<<" ";
		n = n/10;
	}
	
}

