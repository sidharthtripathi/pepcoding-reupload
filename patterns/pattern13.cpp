#include <iostream>

using namespace std;
void pattern(int n){

for(int i = 0 ; i<n ; i++){
	int icj = 1;
	for(int j = 0 ; j<=i ; j++){
			if(j==0)
				icj = 1;
			else if(j==1)
				icj = i;
			else
			icj = (icj * (i-j+1))/j;
		cout<<icj<<" ";

	}
	cout<<endl;


}

}
int main(int argc, char const *argv[])
{	int n; cin>>n;
	pattern(n);


}





