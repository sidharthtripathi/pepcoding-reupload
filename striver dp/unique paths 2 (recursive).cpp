#include <bits/stdc++.h>

int answer(int sr, int sc , vector <vector<int>> &mat){
    // base case
    if(sr == mat.size()-1 and sc == mat[0].size()-1)
    return 1;
    if(mat[sr][sc] == -1)
    return 0;
    // valid horizontal movement
    int hPaths = 0;
    if(sc<mat[0].size()-1 and mat[sr][sc+1]!=-1){
        hPaths = answer(sr,sc+1,mat);
    }

    // valid down movement
    int vPaths = 0;
    if(sr<mat.size()-1 and mat[sr+1][sc] != -1){
        vPaths = answer(sr+1,sc,mat);
    }

    return vPaths + hPaths;


}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    return answer(0,0,mat);
}