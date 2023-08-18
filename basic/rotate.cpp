#include <iostream>
#include <cmath>
using namespace std;
long long rotate(int n,int rot);
int main(int argc, char const *argv[])
{	int n; cin >> n;
	int rot; cin>>rot;
	cout<<rotate(n,rot);
}
int countDigits(int n){
	int digi = 0;
	while(n!=0){
		digi++;
		n = n/10;
	}
	return digi;
}
long long rotate(int n,int rot){
	int digits = countDigits(n);
	if(rot<0){
		rot = digits + rot;
	}
	rot = rot % digits;
	long long ans = 0;
	int pos = 1;
	while(n!=0){
		if(pos<=rot){
			ans = ans + (n%10)*pow(10,pos+(digits-rot)-1);
		}
		else{
			ans = ans + (n%10)*pow(10,(pos-rot-1));
		}
		pos++;
		n = n/10;
	}
	return ans;
	
}

