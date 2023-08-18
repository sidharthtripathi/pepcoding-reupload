#include <iostream>
using namespace std;
int main() {
	int n; cin >> n;
	for (int i = 0 ; i < n ; i ++)
		cout << "*\t";
	int spc = n-2;
	for (int i = 0 ; i < n - 2 ; i++) {
		for (int i = 0 ; i < spc ; i++) {
			cout << "\t";
		}
		spc--;
		cout << "*\t" << endl;
	}
	for (int i = 0 ; i < n ; i ++)
		cout << "*\t";

}