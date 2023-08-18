#include <iostream>

using namespace std;
void pattern(int n){

int str = n;
for(int i = 0 ; i<n; i++){
	for(int j = 0 ; j<str ; j++){
		cout<<"*\t";
	}
	str--;
	cout<<endl;
}

}
int main(int argc, char const *argv[])
{	int n; cin>>n;
	pattern(n);


}





