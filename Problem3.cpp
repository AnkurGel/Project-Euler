#include<iostream>
#include<math.h>
#include<limits>
using namespace std;

bool is_prime(long n) {
  long i = 2, max = sqrt(n);
  bool result = true;
  for(; i <= max; i++){
    if(n % i == 0)
      result = false;
  }
  return result;
}

long generate_next_prime(long n){
  long next_trial = n + 1;
  while(!(is_prime(next_trial))){
    if((next_trial % 2) == 0)
      next_trial++;
    else
      next_trial += 2;
  }
  return next_trial;
}

int main(){
  long long n = 600851475143;

  // if a number = a * b; then, one of the factor must always be less than square_root(number).
  long max_limit = sqrt(n), iter = 2, max_prime_factor = 2;

  while(iter <= max_limit){
    iter = generate_next_prime(iter);
    cout << iter << endl;
    if(n % iter == 0)
      max_prime_factor = iter;
  }
  cout << max_prime_factor << " THIS "; 
  return 0;
}
