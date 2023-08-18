#include <iostream>
using namespace std;
int countDigits(int n);
int main(int argc, char const *argv[])
{	int n; cin >> n;
	cout<<countDigits(n);
}

int countDigits(int n){
	int digi = 0;
	while(n!=0){
		digi++;
		n = n/10;
	}
	return digi;
}

