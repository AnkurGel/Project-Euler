#include<iostream>
#include<stdio.h>
using namespace std;

long long cost_for_ring(int n){
  // (2n+1)^2 for right upper corner
  // (2n+1)^2 - 2n for left upper corner
  // (2n+1)^2 - 4n for lower left corner
  // (2n+1)^2 - 6n for lower right corner
  // Total: 4(2n+1)^2 - 12n
  if (n == 0) return 1; // inner ring/element = 1
  return 4 * ((2*n+1) * (2*n+1)) - 12 * n;
}
long long total_diagonals_cost_till_level(int n){
  if (n == 1) return cost_for_ring(n);
  return cost_for_ring(n) + total_diagonals_cost_till_level(n-1);
}

int main(){

  // Each ring contains 2 rows, 2 columns
  // 500 rings will contain 1000 * 1000 matrix
  cout << total_diagonals_cost_till_level(500) + 1;
  return 0;
}
