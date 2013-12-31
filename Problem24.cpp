#include<iostream>
#include<math.h>
#include<stdio.h>
#include<vector>
#include<map>

using namespace std;

map<int, int> factorial_lookup;
int list_size = 10;

int give_maximum_factorial(int upper_limit){
  for(int i = 1; i <= 10; i++){
    if(factorial_lookup[i] > upper_limit)
      return i-1;
    if(factorial_lookup[i] == upper_limit)
      return i;
  }
}

vector<int> give_factoroid(int fact){
  vector<int> factoroid;
  int maximum_factorial = give_maximum_factorial(fact);
  while(maximum_factorial >= 0){
    factoroid.push_back(fact / factorial_lookup[maximum_factorial]);
    if(fact >= factorial_lookup[maximum_factorial]) fact %= factorial_lookup[maximum_factorial];
    maximum_factorial--; 
  }

  while(factoroid.size() < list_size)
    factoroid.insert(factoroid.begin(), 0);
  return factoroid;
}

vector<int> give_permutation(vector<int> factoroid, vector<int> list){
  vector<int> result; int position;

  //0-indexed
  for(int i = 0; i < factoroid.size(); i++){
    position = factoroid[i];
    result.push_back(list[position]);
    list.erase(list.begin() + position);
  }
  return result;
}

int main(){

  //Permutation inspired by Factoroid permutation:
  // http://en.wikipedia.org/wiki/Factorial_number_system#Permutations
  int list[] = {0,1,2,3,4,5,6,7,8,9};
  vector<int> processing_list;
  int *ptr = list; int i, j;
  //Setting up factorial lookup table
  factorial_lookup[0] = 1; 
  for(i = 1; i <= 10; i++)
    factorial_lookup[i] = factorial_lookup[i-1] * i;

  //Doing permutation
  vector<int> factoroid, result;
  processing_list.insert(processing_list.begin(), list, list+list_size);
  
  for(i = 0; i <= factorial_lookup[10] - 1; i++){
    factoroid = give_factoroid(i);
    result = give_permutation(factoroid, processing_list);
    for(j = 0; j < result.size(); j++) cout << result[j];
    cout << endl;
    if(i == 1000000 - 1) break;
  }
  return 0;
}
