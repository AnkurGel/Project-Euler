#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int main(){

  /*
    Explanation:
    Golden Ratio rule states: 
      F(n) = phi^n/root(5)
    Applying log on both sides:
    log(F(n)) = nlog(phi) - log(5) / 2
    phi = (1 + root(5)) / 2;

    Now, ceiling of log10 of a number gives the number of digits in a
    number.
    CLRS FTW
  */
  long n = ((log(10) * 999) + (log(5) / 2 ))/log(1.6180);
  cout << n;
  
  return 0;
  
}
