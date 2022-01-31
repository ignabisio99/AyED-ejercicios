#include <iostream>
 
using namespace std;


int main()
{   
   int *x;
   int *y;
   int i;

   i = 10;
   x = &i;
   y = x;
   *x = *y + 1; // 10 + 1

   cout << *x << endl; // 11

   *y = *x + 1; // 11 + 1
   cout << i << endl; // 12

   y = new int;
   *y = *x/2; // 12 / 2

   cout << *y << endl; // 6
   cout << *x << endl; // 12
   
   delete y;
   

    return 0;
}
