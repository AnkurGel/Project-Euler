#include<iostream>

using namespace std;

int main(){
  int a, b, c;

  /*
    Since a < b < c;
    for pythagoreous triplet, c is bound to be greater than b,
    that is only possibly when b doesn't cross 1000/2, because when it
    does that, c cannot be > b for total sum of 1000.
    Similarly, b > a, so a can't cross the 1000/3 limit, because when
    that happens, c wont' be able to be > b
  */
  for(a = 1; a < 1000/3; a++)
    for(b = a; b <= 1000/2; b++){
      c = 1000 - (a + b);
      if((a + b + c == 1000) && (a*a + b*b == c*c))
        cout << a << "\t" << b << "\t" << c;
    }
  
  return 0;
}
