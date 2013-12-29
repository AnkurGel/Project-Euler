//OPTIMUS PRIME
#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

bool is_prime(long);

int main(){
  int counter = 1, i = 3;
  while (counter != 10001){
    if(is_prime(i)){
      counter += 1;
      cout << i << "\t" << counter << endl;
      i += 2;
    }
    else i++;
  }
  return 0;
}

bool is_prime(long n) {
  // Autobots, Roll out! 
  long i = 2, max = sqrt(n);
  bool result = true;
  for(; i <= max; i++){
    if(n % i == 0){
      result = false;
      break;
    }
  }
  return result;
}
