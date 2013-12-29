#include<iostream>
#include<fstream>
#include<stdio.h>
#include<math.h>
#include<string>
using namespace std;

int convert_to_num(string);

int main(){

  ifstream ifile;
  ifile.open("Problem11_data", ifstream::in);
  string line, number="";
  int i = 0, j, k;
  int arr[20][20];
  /* Reading input from file in 2D matrix */
  while(ifile.good()){
    getline(ifile, line);
    ifile.get(); // for null

    j = 0;
    // scan the line
    for(int k = 0; k < line.length(); k++){
      if(line[k] != ' '){
        number += line[k];
      }
      else{
        arr[i][j] = convert_to_num(number);
        number = "";
        j++;
      }
    }
    //boundary case -> no space will be present there
    arr[i][j] = convert_to_num(number);
    number = "";
    i++;
  }
  /* Input acquired */

  int elements_to_scan = 4;
  long product = 1, greatest_product = 1;
  /* Scanning begins */
  for(i = 0; i < 20; i++){
    for(j = 0; j < 20; j++){
      // Vertically downward "|"
      if(i+elements_to_scan - 1 < 20){
        product = 1;
        for(k = i; k < i+elements_to_scan; k++)
          product *= arr[k][j];
        greatest_product = product > greatest_product ? product : greatest_product;
      }

      // Horizontally forward "-"
      if(j + elements_to_scan - 1 < 20){
        product = 1;
        for(k = j; k < j+elements_to_scan; k++)
          product *= arr[i][k];
        greatest_product = product > greatest_product ? product : greatest_product;
      }

      // Diagonally downward-right "\"
      if((j + elements_to_scan - 1 < 20) and (i + elements_to_scan - 1 < 20)){
        product = 1;
        int i_temp = i;
        for(k = j; k < j + elements_to_scan; k++)
          product *= arr[i_temp++][k];
        greatest_product = product > greatest_product ? product : greatest_product;
      }

      // Diagonally downward-left "/"
      if((j - elements_to_scan + 1 > 0) and (i+elements_to_scan - 1 < 20)){
        product = 1;
        int j_temp = j;
        for(k = i; k < i+elements_to_scan; k++)
          product *= arr[k][j_temp--];
        greatest_product = product > greatest_product ? product : greatest_product;
      }
      
    }
  }

  cout << greatest_product;
  
  return 0;
}

int convert_to_num(string s){
  int num = 0;
  for(int i = 0; i < s.length(); i++){
    num = num * 10 + (s[i] - 48);
  }
  return num;
}
