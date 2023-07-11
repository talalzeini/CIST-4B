// Talal El Zeini CIST 004B
#include <ostream>
#include <fstream>
#include <iostream>
#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

// Talal El Zeini CIST 004B
void triangle(ostream& outs, unsigned int m, unsigned int n)
{
  for(int i = 0; i < m; i++)
    {
        outs << "*";
    }
    outs  << endl;

    if(m == n)
    {
        for(int i = 0; i < m; i++)
        {
            outs << "*";
        }
        outs << endl;
        return;
    }

    triangle(outs, m+1,n);

    for(int i = 0; i < m; i++)
    {
        outs << "*";
    }
    outs << endl;
}
 

// Talal El Zeini CIST 004B
void numbers(ostream& outs, const string& prefix, unsigned int levels){
  string s;
  if(levels == 0)
	outs << prefix << endl;
  else{
    for (char c = '1'; c <='9'; c++){
      s = prefix + c + ".";
      numbers (outs, s, levels - 1);
    }
  }
}



bool bears (int n)
{
   int temp;
   if (n<42)
   return 0;
   else
   {   if (n==42) return 1;
       if ((n % 2) == 0)
       {   temp=n-n/2;
           if (bears(temp)==1) return 1;
       }
       if ((n % 3) == 0 || (n % 4) == 0)
       {   temp=n-(n%10)*((n%100)/10);
           if (temp!=n)
              if (bears(temp)==1) return 1;  
       }
       if ((n % 5) == 0 )
       {   temp=n-42;
           if (bears(temp)==1) return 1;
           else return 0;
       }  
       return 0;
   }
}
int fib_iterative(int n) {
    if(n == 1 || n == 2)
        return 1;
    int A[2][2] = { { 1, 1 },{ 1, 0 } };
    int B[2][2] = { { 1, 1 },{ 1, 0 } };
    int temp[2][2];
    while (n >= 2) {
         for (int i = 0; i < 2; i++)
             for (int k = 0; k < 2; k++) {
                 temp[i][k] = 0;
                 for (int j = 0; j < 2; j++)
                     temp[i][k] += A[i][j] * B[j][k];
              }
         for (int i = 0; i < 2; i++)
             for (int j = 0; j < 2; j++)
                 B[i][j] = temp[i][j];
         n--;
    }
    return B[0][1];
}

int fibonacci(int n)
{
 

    if (n < 2){
   
        return n;
}
else{
    return (fibonacci(n-1)+fibonacci(n-2));
}
}
// Talal El Zeini CIST 004B











