#include <iostream>

using namespace std;
bool triplet(int a, int b , int c){
	if(a*a + b*b == c*c) return true;
	else if(a*a + c*c == b*b) return true;
	else if(b*b + c*c == a*a) return true;
	return false;

}
int main(int argc, char const *argv[])
{	int a,b,c;
	cin>>a>>b>>c;
	cout<<triplet(a,b,c);


}





