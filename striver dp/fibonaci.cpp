#include <iostream>
#include <vector>
using namespace std;



long long fib(long long n,vector<long long> &solved){
   if(n==1) return 0;
   if(n==2) return 1;
   if(solved[n] != -1)
      return solved[n];

   long long ans =  fib(n-1,solved) + fib(n-2,solved);
   solved[n] = ans;
   return ans;
}

long long fibTab(int n){
   if(n<=2)
      return n-1;
   vector<long> solved(n+1,-1);
   solved[1] = 0;
   solved[2] = 1;
   int size = solved.size();
   for(int i = 3 ; i<solved.size() ; i++){
         solved[i] = solved[i-1] + solved[i-2];
   }
   return solved[size-1];
}

int main(){
   long long n; cin>>n;
   vector<long long> solved(n+1,-1);
   cout<<fib(n,solved)<<endl;
   cout<<fibTab(n);
}