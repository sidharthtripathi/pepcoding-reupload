#include <vector>
#include <iostream>
#include <climits>
using namespace std;



void climbingStairMinMoves(int n , int index , vector<int> &jumps , int moves ,int &minMoves){
   if(index==n){
      minMoves = min(moves,minMoves);
      return;
   }
   if(index>n)
      return;

   // jumping from ith ladder
   for(int i = 1 ; i<= jumps[index] ; i++){
      moves++;
      climbingStairMinMoves(n,index + i ,jumps,moves,minMoves );
      moves--;
   
   }


}

int main(){
   int n; cin>>n;
   vector<int> jumps;
   for(int i = 0 ; i<n ;i++){
      int temp; cin>>temp;
      jumps.push_back(temp);
   }
   int minMoves = INT_MAX;
   climbingStairMinMoves(n,0,jumps,0,minMoves);
   cout<<minMoves;
}