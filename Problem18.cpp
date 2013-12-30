#include<iostream>
#include<string>
#include<stdio.h>
#include<fstream>
#include<iomanip>
using namespace std;

int numeric(string);
int find_max(int, int);
int main(){

  int size = 15; //matrix size;
  /* Acquiring input */
  ifstream ifile;
  ifile.open("Problem18_data", ifstream::in);
  string line; int i, j=0, k;
  string buffer = "";
  int arr[size][size]; long max[size][size];
  for(i = 0; i < size; i++) for(k = 0; k < size; k++) {arr[i][k] = 0; max[i][k] = 0; }

  while(ifile.good()){
    getline(ifile, line);
    //    ifile.get(); 

    buffer = ""; k = 0;
    for(i = 0; i < line.length(); i++){
      if(line[i] != ' '){
        buffer += line[i];
      }
      else{
        arr[j][k++] = numeric(buffer);
        buffer = ""; // clear buffer
      }
    }
    arr[j][k] = numeric(buffer);
    j++;
  }

  //Showing data matrix
  for(i = 0; i < size; i++){
    for(j = 0; j < size; j++)
      cout << setw(2) << arr[i][j] << " ";
    cout << endl;
  }

  //Dynamic programming approach:
  //Set maximum paths, starting from last row - boundary case:
  for(i = 0; i < size; i++) max[14][i] = arr[14][i];

  //now starting from last 2nd row till first, take two rows at time,
  //and set corresponding max
  for(i = size - 2, k = 1; i >= 0; i--, k++){
    for(j = 0; j < size-k; j++){
      max[i][j] = arr[i][j] + find_max(max[i+1][j], max[i+1][j+1]);
    }
  }

  cout << "\n\nMAX matrix " << endl;
  for(i = 0; i < size; i++){
    for(j = 0; j < size; j++)
      cout << setw(2) << max[i][j] << " ";
    cout << endl;
  }

  cout << "\nRESULT: " << max[0][0];
  return 0;
}

int find_max(int a, int b){
  return a > b ? a : b;
}
int numeric(string s){
  int num = 0;
  for(int i = 0; i < s.length(); i++){
    num = num * 10 + s[i] - 48;
  }
  return num;
}
