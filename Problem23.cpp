#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<map>

using namespace std;

long sum_of_proper_divisors(int number){
  int i; long sum = 1;
  for(i = 2; i <= sqrt(number); i++){
    if(number % i == 0){
      sum += i;
      if(i != sqrt(number)) sum += number/i;
    }
  }
  return sum;
}

int main(){

  vector<int> abundant_numbers;
  map<int, bool> sum_of_abundant;
  int max_limit = 28123, i, j;
  for(i = 2; i <= max_limit; i++){
    if(sum_of_proper_divisors(i) > i)
      abundant_numbers.push_back(i);
  }
  // cout << sum_of_proper_divisors(10533)
  for(i = 1; i <= max_limit; i++) sum_of_abundant[i] = false;
  for(i = 0; i < abundant_numbers.size(); i++){
    for(j = i; j < abundant_numbers.size(); j++){
      int sum_of_two = abundant_numbers[i] + abundant_numbers[j];
      if(sum_of_two <= max_limit){
        // since numbers above max_limit can be represented by sum of
        // 2 abundant numbers, so go till that limit only.
        sum_of_abundant[sum_of_two] = true;
      }
      else break; 
    }
  }

  long sum = 0;
  for(i = 1; i < max_limit; i++)
    if(sum_of_abundant[i] == false) sum += i;
  
  cout << sum;

  return 0;
}
