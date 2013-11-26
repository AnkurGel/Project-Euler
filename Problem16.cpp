#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
      
int main() {
  int power = 1000, base = 2, i, j, result[400], used_positions;
  long sum = 0;
  for(i = 0; i < 399; i++) result[i] = 0;
  result[0] = 2, used_positions = 0;

  /*
    multiplying
   */
  for(i = 2; i <= 1000; i++){
    for(j = 0; j <= used_positions; j++)
      result[j] = result[j] * 2;
    for(j = 0; j <= used_positions; j++){
      if(result[j] > 9) {
        result[j + 1] += result[j] / 10;
        result[j] %= 10;
        if((j+1) > used_positions) used_positions++;
      }
    }
  }
  cout << "2^1000 = ";
  for(i = 0; i <= used_positions; i++) {
    cout << result[used_positions-i];
    sum += result[i];
  }

  cout << sum;
  return 0;
}
