#include<iostream>
#include<stdio.h>
using namespace std;

bool is_palindrome(long number){
  long rem = 0, rev_number = 0;
  long temp = number;
  while(number != 0){
    rem = number % 10;
    rev_number = rev_number * 10 + rem;
    number /= 10;
  }number = temp;
  if(rev_number == number)
    return true;
  else
    return false;
}
int main(){
  int a, b;
  long long largest_palindrome = 0, prod;
  for(a = 100; a <= 999; a++){
    for(b = 100; b <= 999; b++) {
      prod = a * b;
      if(is_palindrome(prod) && (prod > largest_palindrome))
        largest_palindrome = prod;
    }
  }
  cout << largest_palindrome;
  return 0;
}
