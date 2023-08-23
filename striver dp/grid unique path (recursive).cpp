#include <bits/stdc++.h> 

int answer(int sr, int sc , int dr, int dc){
   if(sr==dr and sc == dc){
      return 1;
   }
   
   // valid horizontal move
   int hPaths = 0;
   if(sc<dc){
      hPaths = answer(sr,sc+1,dr,dc);
   }
   // valid down movement
   int vPaths = 0;
   if(sr<dr){
      vPaths = answer(sr+1,sc,dr,dc);
   }
   return hPaths + vPaths;

}

int uniquePaths(int m, int n) {
   // Write your code here.
   return answer(1,1,m,n);
}