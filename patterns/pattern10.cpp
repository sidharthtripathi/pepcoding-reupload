#include <iostream>

using namespace std;
void pattern(int n){

int outspc = n/2;
int inspc = -1;

for(int i = 1 ; i<=n; i++){
	// outer spc
	for(int j = 1 ; j<=outspc ; j++){
		cout<<"\t";
	}
	cout<<"*\t";
	// inner spc
	for(int j = 1 ; j<=inspc ; j++){
		cout<<"\t";
	}

	if(i>1 and i<n)
	cout<<"*\t";



	if(i<=n/2){
		inspc = inspc + 2;
		outspc--;
	}
	else{
		inspc = inspc - 2;
		outspc++;
	}


	cout<<endl;
}

}
int main(int argc, char const *argv[])
{	int n; cin>>n;
	pattern(n);


}





