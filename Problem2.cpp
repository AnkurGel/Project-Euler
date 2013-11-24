#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
  long i = 0, j = 1, sum = 0, temp;
  while(j < 4000000){
    temp = i; i = j; j = temp + j;
    if(j % 2 == 0)
      sum += j;
  }
  cout << sum;
}
