#include<iostream>

using namespace std;

int main(){
  int a, b, c;
  for(a = 1; a < 1000; a++)
    for(b = a; b <= (1000-a); b++){
      c = 1000 - (a + b);
      if((a + b + c == 1000) && (a*a + b*b == c*c))
        cout << a << "\t" << b << "\t" << c;
    }
  
  return 0;
}
