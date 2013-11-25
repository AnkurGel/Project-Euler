#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

bool is_prime(long long n){
  long i = 2, max = sqrt(n);
  bool result = true;

  for(; i <= max; i++){
    if(n % i == 0){
      result = false; break;
    }
  }
  return result;
}

bool is_even(long long n){
  if(n%2 == 0) return true;
  else
    return false;
}

int main(){
  long long sum = 0, max = 2000000, i;
  // Damn! Everytime I read of 'prime' - 
  // "Autobots, roll out."

  for(i = 2; i < max; i++){
    if(is_even(i)) continue;
    else {
      if(is_prime(i)){
        sum += i;
      }
    }
  }
  cout << sum;
  return 0;
}
