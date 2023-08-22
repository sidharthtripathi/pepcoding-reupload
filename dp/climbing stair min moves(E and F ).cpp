#include <vector>
#include <iostream>
#include <climits>
using namespace std;

int minMoves(int sp , int ep, vector<int> &jumps){
   if(sp == ep){
      return 0;
   }
   else if(sp>ep)
      return INT_MAX;


   // give me min moves from the following stairs
   int minimum = INT_MAX;
   for(int i = 1 ; i<=jumps[sp] ; i++){
      int mini = minMoves(sp+i,ep,jumps);
      minimum = min(minimum, mini);
       
   }

    return minimum + 1;
}



int main(){
   int n; cin>>n;
   vector<int> jumps;
   for(int i = 0 ; i<n ;i++){
      int temp; cin>>temp;
      jumps.push_back(temp);
   }

   cout<<minMoves(0,n,jumps);
   
   
}