#include <iostream>

using namespace std;
void pattern(int n){

for(int i = 1 ; i<=10 ; i++){
	cout<<i<<" * "<<n<<" = "<<i*n;
	cout<<endl;

}

}
int main(int argc, char const *argv[])
{	int n; cin>>n;
	pattern(n);


}





