#include <iostream>

using namespace std;
void pattern(int n){
int spc = 2*n - 3;
for(int i = 1 ; i<=n; i++){
	int rowNum = 1;
	// printing num
	for(int j = 1; j<=i ; j++){
		cout<<rowNum<<"\t";
		rowNum++;
	}
	rowNum--;
	// printing spc
	for(int j = 1 ; j<=spc ; j++){
		cout<<"\t";
	}

	spc = spc - 2;

	// printing num again
	for(int j = 1; j<=i ; j++){
		if(i==n and j==1){
			rowNum--;
			continue;
		}
		cout<<rowNum<<"\t";
		rowNum--;

	}


	cout<<endl;

}
}
int main(int argc, char const *argv[])
{	int n; cin>>n;
	pattern(n);


}





