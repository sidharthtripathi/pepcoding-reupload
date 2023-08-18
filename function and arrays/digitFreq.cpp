#include <iostream>
using namespace std;
int digitFreq(int n , int k){
	int count = 0;
	while(n>0){
		if(n%10==k) count++;
		n = n/10;

	}
	return count;


}

int main(){
int n,k;
cin>>n>>k;
cout<<digitFreq(n,k);

}