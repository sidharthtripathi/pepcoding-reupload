#include <iostream>

using namespace std;
void pattern(int n){
int rowNum = 1;
int inNum = 1;
int spc = n/2;
for(int i = 1 ; i<=n; i++){
	// print spacing
	for(int j = 1 ; j<=spc ; j++){
		cout<<"\t";
	}
	int colNum = rowNum;
	for(int j = 1; j<=inNum ; j++){
		cout<<colNum<<"\t";
		if(j>=inNum/2+1)
			colNum--;
		else
			colNum++;
	}
	cout<<endl;
	if(i>=n/2+1){
		spc++;
		inNum = inNum-2;
		rowNum--;
	}
	else{
		spc--;
		inNum = inNum + 2;
		rowNum++;
	}
}


}
int main(int argc, char const *argv[])
{	int n; cin>>n;
	pattern(n);


}





