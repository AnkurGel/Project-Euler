#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

/* Generator for triangular numbers */
long long generate_next_tri_number(long long *previous_num, long long *counter){
  *counter = *counter + 1;
  long number = *previous_num + *counter;
  *previous_num = *previous_num + *counter;
  return(number);
}

bool is_prime(long n);
long next_prime(long n);

long number_of_factors(long long number){
  // Now, simply calculate the number of factors
  // by prime factorization
  int factors = 1;
  int prime_power = 0;
  long prime = 2;
  if(is_prime(number)) return 2;
  while(number != 1){
    if(number % prime == 0) {
      prime_power++;
      number = number / prime;
    }
    else {
      if(prime_power > 0) factors *= (prime_power+1);
      prime = next_prime(prime);
      prime_power = 0;
    }
  }
  if(prime_power > 0) factors *= (prime_power += 1);
  return factors;
}

int main(){
  int total_divisors = 500;
  long long triangular_number = 1;
  long long counter = 1;
  long intermediate_divisors = 0;

  while(intermediate_divisors < total_divisors) {
    generate_next_tri_number(&triangular_number, &counter);
    cout << " Trying " << triangular_number;
    intermediate_divisors = number_of_factors(triangular_number);
    cout << " which has " << intermediate_divisors << " factors"  << endl;
  }
  cout << " RESULT " << triangular_number;
  return 0;
}

bool is_prime(long n){
  long i = 2, max_iter = sqrt(n);
  for(; i <= max_iter; i++){
    if(n % i == 0){
      return false;
    }
  }
  return true;
}
long next_prime(long n){
  long n_next = n + 1;
  while(!(is_prime(n_next))){
    if(n_next % 2 == 0) n_next++;
    else n_next+=2;
  }
  return n_next;
}
