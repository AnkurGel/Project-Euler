#include<iostream>
#include<stdio.h>
#include<fstream>
#include<math.h>

using namespace std;

int main(){

  /*
    Approach:
    Read numbers as strings, maintain summation of digits[i] for
    each line, then use modulo and divisions to set carries and final
    additions.

    Another approach: Fixed length strings. Set decimal at 1. Add.
  */
  
  int max_digits = 50;
  long digits[max_digits]; // holds the summation of digit[i] for each line
  int i, carry = 0; char str[max_digits];
  for(i = 0; i < max_digits; i++) digits[i] = 0;

  ifstream ifile;
  ifile.open("Problem13_data", ifstream::in);
  
  while(ifile.good()){
    ifile.get(str, (max_digits + 1)); // 51 for null termination.
    ifile.get(); // for new line

    // now, that we have each line as string, iterate over the digits 

    for(i = 0; i < max_digits; i ++){
      digits[i] += (str[i] - 48);
    }
  }
  ifile.close();

  for(i = (max_digits - 1); i >= 0; i--){
    digits[i] = digits[i] + carry;
    if (i > 0){
      carry = digits[i] / 10;
      digits[i] = digits[i] % 10;
    }
  }

  // now showing first 10 digits of sum
  for(int i = 0; i < 10; i++)
    cout << digits[i]; // manually select 10 digits, from output, now.
  
  return 0;
}
