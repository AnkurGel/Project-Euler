#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<fstream>

using namespace std;

int calculate_rank(string name, int index){
  int positional_sum = 0;
  for(int i = 0; i < name.size(); i++){
    positional_sum += (name[i] - 64); 
  }
  return (positional_sum * index);
}

int main(){
  vector<string> names;
  string str;
  long long total_rank_summation = 0;
  ifstream ifile;

  
  ifile.open("Problem22-names.txt", ifstream::in);
  int OFF = 0, ON = 1; int reading_switch = OFF, i, j;
  while(ifile.good()){
    char c = ifile.get();
    if(c == '"' && reading_switch == OFF) reading_switch = ON;
    else if(c == '"' && reading_switch == ON)
      {names.push_back(str); reading_switch = OFF; str = "";}
    else if(c == ',') continue;
    else if(reading_switch == ON) str.push_back(c);
    else continue;
  }

  sort(names.begin(), names.end()); // algorithm

  for(i = 0; i < names.size(); i++){
    // index = i+1
    total_rank_summation += calculate_rank(names[i], i+1);
  }


  cout << "Total rank summation : " << total_rank_summation;

  return 0;
}
