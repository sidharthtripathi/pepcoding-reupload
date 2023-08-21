#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

// solution
void solution(int i , int n , int  e, int minE, vector<int> &heights){
  if(i==n){
    return;
  }

  minE = min(minE,e);

  // jumping
  // energy on that stage
  e = abs(heights[i] - e);
  solution(i+1,n,e,minE,heights);

  // when jumping with 2
  e = abs(heights[i+1] - e);
  solution(i+2,n,e,minE,heights);


}


int main(){

int minE = INT_MAX;


}