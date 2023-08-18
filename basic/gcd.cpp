#include <iostream>
#include <cmath>
using namespace std;
int gcd(int a, int b){
	int smallerNum = a<b ? a : b;
	int biggerNum  = a>b ? a : b;
	while(smallerNum >= 1){
		if(a%smallerNum ==0 and b%smallerNum ==0)
			return smallerNum;
		smallerNum--;
	}
	return smallerNum;

}
int main(int argc, char const *argv[])
{	
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b);


}





