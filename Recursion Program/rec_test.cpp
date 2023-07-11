#include <ostream>
#include <fstream>
#include <iostream>
#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;
void triangle(ostream& outs, unsigned int m, unsigned int n);
void numbers(ostream& outs, const string& prefix, unsigned int levels);
bool bears (int n);
int fibonacci(int n);
int fib_iterative(int n);

int main()
{
int choice;
cout << "\nTriangles.\n\n";
triangle(cout,3,5);
cout << "\nNumbers.\n\n";
numbers(cout, "THERBLIG", 2);

cout << "\nBears.\n\n";
cout << "bears(250) is "<< boolalpha << bears(250) << endl;
cout << "bears(42) is " << boolalpha << bears(42) << endl;
cout << "bears(84) is "<< boolalpha << bears(84) << endl;
cout << "bears(53) is "<< boolalpha << bears(53) << endl;
cout << "bears(41) is "<< boolalpha << bears(41) << endl;



cout<<"\nFibonacci\n\n";
cout << "n\t" << "Recursive\t\ttime_r(s)\tInterative\t  time_i(s)";
high_resolution_clock::time_point t1 = high_resolution_clock::now();

    


     
for(int i = 0; i <= 45; i++)
{
high_resolution_clock::time_point t1 = high_resolution_clock::now();
std::cout << fixed;
cout<< endl << i << setw(11) << fibonacci(i);
high_resolution_clock::time_point t2 = 
high_resolution_clock::now();
duration<double> time_span = t2 - t1; 
std::cout << fixed;
std::cout << setw(16) << time_span.count();

high_resolution_clock::time_point t3 = high_resolution_clock::now();
std::cout << fixed;
cout <<  setw(11) << fib_iterative(i);
high_resolution_clock::time_point t4 = high_resolution_clock::now();
duration<double> time_span1 = t4 - t3; 
std::cout << fixed;
std::cout << setw(16) << time_span1.count();
}






return 0;
}