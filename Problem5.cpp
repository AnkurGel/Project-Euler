#include<iostream>
#include<math.h>
#include<stdio.h>
#include<map>
#include<cctype>
using namespace std;

bool is_prime(long n);
long next_prime(long n); // prime generator

int main(){
  // Simply, we can find least common multiple of numbers (1..20)
  // One way: Find GCD. Then, LCM = (a*b)/GCD(a,b)
  // Second way: Factorize each number, then express LCM in unique powers.

  // By Factorization:
  long long product = 1;
  map<int, int> hash;
  int i;
  for(i = 1; i <= 20; i++) hash[i] = 0;


  int prime_power = 0, prime = 2;
  
  for(i = 2; i < 20; i++){
    prime = 2, prime_power = 0;
    if(is_prime(i) and hash[i] == 0){
      hash[i] = 1;
    }
    else{
      int number = i; // to be prime factored
      while(number != 1){
        if(number % prime == 0){
          prime_power++;
          number /= prime;
        }
        else{
          if(prime_power > 0 && hash[prime] < prime_power){
            hash[prime] = prime_power;
            prime_power = 0;
            prime = next_prime(prime);
          }
          else{ prime_power = 0;
            prime = next_prime(prime);
          }
        }
        
      }
      if(prime_power > 0 ){
        if(hash[prime] < prime_power) hash[prime] = prime_power;
      }
      
    }
  }
  
  for(i = 1; i <= 20; i++){
    if(hash[i] > 0){
      product *= pow(i, hash[i]);
    }
  }
  cout << product;
  
  return 0;
}
bool is_prime(long n) {
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

long next_prime(long n){
  long n_next = n + 1;
  while(!is_prime(n_next)){
    if(n_next % 2 == 0) n_next += 1;
    else n_next += 2;
  }
  return n_next;
}
