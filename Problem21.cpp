#include<iostream>
#include<stdio.h>
#include<math.h>
#include<map>
using namespace std;

long sum_of_proper_divisors(int number);
int main(){

  int i;
  map<int, long> hash; // stores number and it's sum of proper divisors
  for(i = 2; i < 10000; i++) hash[i] = sum_of_proper_divisors(i);

  long collective_sum = 0;
  for(i = 2; i < 10000; i++){
    int temp = hash[i];
    if(hash[temp] == i && i < temp){
      cout << i << " and " << hash[i] << endl;
      collective_sum += hash[i] + i;
    }
  }

  cout << "Collective sum : " << collective_sum;

  return 0;
}

long sum_of_proper_divisors(int number){
  int i; long sum = 1;
  for(i = 2; i <= sqrt(number); i++){
    if(number % i == 0){
      sum += i; sum += number/i;
    }
  }
  return sum;
}
