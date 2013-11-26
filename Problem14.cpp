#include<iostream>
#include<stdio.h>

using namespace std;

long long generate_next_number(long long number){
  if(number == 1) return 1; // base condition
  else if(number % 2 == 0) return number/2; // when even
  else return (3 * number + 1); // when odd
}

long give_collatz_length_for(long long number){
  int length = 1;
  while(number != 1){
    length++;
    number = generate_next_number(number);
  }
  return length;
}

int main(){
  long long largest_length = 0, i, sequence_length, responsible_number;
  for(i = 1; i <= 1000000; i++){
    sequence_length = give_collatz_length_for(i);
    if(sequence_length > largest_length){
      largest_length = sequence_length;
      responsible_number = i;
    }
  }
  
  cout << responsible_number;
  return 0;
}
