#include<iostream>
#include<stdio.h>
using namespace std;

int main(){

  /*
    Sum of first n natural nos = (n)(n+1)/2;
    Sum of series: 1^2 + 2^2 + 3^2 + .... + n^2 = (n * (n+1) * (2n+1)/6)
  */
  int n = 100;
  long sum = (n * (n+1)) / 2;
  
  long long square_of_sums = sum * sum;

  long long sum_of_squares = (n * (n+1) * (2*n + 1))/6;

  cout << square_of_sums - sum_of_squares;
  return 0;
}
