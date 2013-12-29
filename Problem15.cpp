#include<iostream>
#include<stdio.h>
using namespace std;

int main(){

  long total_ways = 0;
  int gsize = 20;
  long long arr[gsize+1][gsize+1]; //nodes = gsize+1 * gsize+1
  int i, j;

  /* Number of ways to reach from terminal nodes = 1
     These terminal nodes are vertical terminal points in last column
     grid, and horizontal terminal points in last row grid
  */
     
  for(i = 0; i < gsize; i++){
    arr[i][gsize] = 1; 
    arr[gsize][i] = 1;
  }
  
  for(i = gsize - 1; i >= 0; i--){
    for(j = gsize - 1; j >= 0; j--){
      arr[i][j] = arr[i+1][j] + arr[i][j+1];
    }
  }
  cout << "RESULT " << arr[0][0];
  return 0;
}
