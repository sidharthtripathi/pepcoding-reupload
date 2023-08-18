#include <iostream>

using namespace std;
void pattern(int n){
int f = 0;
int s = 1;
int t = f+s;
int num = 1;
for(int i = 1 ; i<=n ; i++){
	for(int j = 1 ; j<=i ; j++){
		if(i==1)
			cout<<0<<" ";
		else if(i==2 and j==1)
			cout<<1<<" ";
		else{
			cout<<t<<" ";
			f = s;
			s = t;
			t = f+s;
		}
			
			
		
	}
	cout<<endl;
}

}
int main(int argc, char const *argv[])
{	int n; cin>>n;
	pattern(n);


}





