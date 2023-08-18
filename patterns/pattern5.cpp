#include <iostream>

using namespace std;
void pattern(int n){

int spc = n/2;
int str = 1;
for(int i = 1 ; i<=n; i++){
	for(int j = 0 ; j<spc ; j++){
		cout<<"\t";
	}
	for(int j = 0 ; j<str ; j++){
		cout<<"*\t";
	}
	if(i>=n/2+1){
		str = str - 2;
		spc++;
	}
	else{
		str = str +2;
		spc--;
	}
	cout<<endl;
}

}
int main(int argc, char const *argv[])
{	int n; cin>>n;
	pattern(n);


}





