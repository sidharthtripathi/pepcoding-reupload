#include <iostream>
using namespace std;
void fibTillN(int n);
int main(int argc, char const *argv[])
{	int n; cin >> n;
	fibTillN(n);
}


void fibTillN(int n) {
	if(n==1){
		cout<<0;
		return;
	}
	int f = 0;
	int s = 1;
	int t = f + s;
	cout << f << " " << s << " ";
	for (int i = 0 ; i < n - 2 ; i++) {
		cout<<t<<" ";
		f = s;
		s = t;
		t = f+s;
	}


}
