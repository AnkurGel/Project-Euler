#include<iostream>
#include<stdio.h>
#include<map>
#include<string>
#include<vector>

using namespace std;

string number_in_words(int, map<int,string>);

int main(){
  int number,i;

  map<int, string> dict;
  string in_words;

  long long total_length = 0;
  
  // Composing dictionary
  dict[1] = "one"; dict[2] = "two"; dict[3] = "three"; dict[4] = "four"; dict[5] = "five";
  dict[6] = "six"; dict[7] = "seven"; dict[8] = "eight"; dict[9] = "nine";

  dict[10] = "ten"; dict[11] = "eleven"; dict[12] = "twelve";
  dict[13] = "thirteen"; dict[14] = "fourteen";
  dict[15] = "fifteen"; dict[16] = "sixteen";
  dict[17] = "seventeen"; //mo-fo, missed it, initially. 
  dict[18] = "eighteen"; dict[19] = "nineteen";
  dict[20] = "twenty"; dict[30] = "thirty";
  dict[40] = "forty"; dict[50] = "fifty"; 
  dict[60] = "sixty"; dict[70] = "seventy"; dict[80] = "eighty";
  dict[90] = "ninety";
  dict[100] = "hundred"; dict[1000] = "thousand";

  for(number = 1; number <= 999; number++){
    in_words = number_in_words(number, dict);
    cout << in_words << endl;
    total_length += in_words.size();
  }
  total_length += 11;
  cout << "Total length: " << total_length;
  return 0;
}


string number_in_words(int number, map<int, string> dict){
  vector<int> arr; int count = 0;
  string in_words = "";
  while(number != 0){
    arr.push_back(number % 10);
    number /= 10;
    count++;
  }
  
  for(int i = (arr.size() - 1); i >= 0; i--){
    if(i == 2){
      in_words.append(dict[arr[i]]);
      in_words.append("hundred");
      in_words.append("and");
    }
    if(i == 1) {
      if(arr[i] == 1){
        in_words.append((dict[arr[i] * 10 + arr[i-1]]));
        break;
      }
      else in_words.append(dict[arr[i] * 10]);
    }
    
    if(i == 0)
      in_words.append(dict[arr[i]]); 
  }

  return in_words;
}
