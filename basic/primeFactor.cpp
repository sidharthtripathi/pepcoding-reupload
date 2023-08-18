#include <iostream>
#include <cmath>
using namespace std;
void primeFactor(int n){
	if(n==1){
		cout<<1;
		return;
	}
	int f = 2;
	while(n!=1){
		while(n%f==0){
			n = n/f;
			cout<<f<<" ";
		}
		f++;
	}

}
int main(int argc, char const *argv[])
{	
	int n;cin>>n;
	primeFactor(n);


}





