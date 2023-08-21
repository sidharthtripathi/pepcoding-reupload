#include <iostream>
#include <vector>
using namespace std;

// to print array
void printArr(vector<int> &arr){
   for(int i = 0 ; i<arr.size() ; i++)
      cout<<arr[i]<<" ";
   cout<<endl;
}

void printJumps(int n,vector <int> psf = {}){

  if(n==0){
   printArr(psf);
   return;
  } 


  // now taking the jumps
  for(int i = 1 ; i<=n ; i++){
      psf.push_back(i);
      printJumps(n-i,psf);
      psf.pop_back();
  }


}


int main(){

printJumps(3);



}