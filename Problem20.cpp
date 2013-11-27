#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
  int factorial[200], number = 100, used_positions = 0;
  int i, j, k;
  long sum = 0;
  
  for(i = 0; i <= 200; i++) factorial[i] = 0;
  factorial[0] = 1;
  
  for(i = 2; i <= number; i++){

    for(j = 0; j <= used_positions; j++)
      factorial[j] *= i;
    
    for(j = 0; j <= used_positions; j++){
      if(factorial[j] > 9){

        factorial[j + 1] += factorial[j] / 10;
        factorial[j] %= 10;
        if((j + 1) > used_positions) used_positions++;
        
      }
    }
    for(j = used_positions; j>=0; j--)
      cout << factorial[j];
    cout << endl;
  }
  for(j = 0; j <= used_positions; j++)
    sum += factorial[j];
  cout << "\nSUM: " << sum;
}
