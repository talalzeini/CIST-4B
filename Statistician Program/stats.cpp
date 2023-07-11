// TALAL EL ZEINI  CIST 004B
#include "stats.h"
#include <iostream>
// TALAL EL ZEINI  CIST 004B
namespace main_savitch_2C {

statistician::statistician()
{
    count = 0;
    total = 0;
}

void statistician:: next(double r)
{
    if (count == 0)
    {
        total = r;
        tinyest = r;
        largest = r;
    }
    else
    {
        total += r;
        if (r < tinyest) tinyest = r;
        if (r > largest) largest = r;
    }
    count++;
}
// TALAL EL ZEINI  CIST 004B
void statistician:: reset()
{
   count = 0;
   total = 0;
}
int statistician::length() const
{
   return count;
}
double statistician::sum() const
{
   return total;
}
double statistician:: mean( ) const
{
   assert(length() > 0);
   return (double(total) / double(count));
}

double statistician:: minimum( ) const
{
   assert(length() > 0);
   return tinyest;
   return 0.0;
}

double statistician:: maximum( ) const
{
   assert(length() > 0);
   return largest;
   return 0.0;
}
statistician operator +(const statistician& s1, const statistician& s2)
    {
        statistician result;

        if (s1.length() == 0)
            return s2;
        if (s2.length() == 0)
            return s1;
        
// TALAL EL ZEINI  CIST 004B
        result.count = s1.length() + s2.length();
        result.total = s1.length() * s1.mean() + s2.length() * s2.mean();
        
        if (s1.minimum() < s2.minimum())
            result.tinyest = s1.minimum();
        else result.tinyest = s2.minimum();
        
        if (s1.maximum() > s2.maximum())
            result.largest = s1.maximum();
        else result.largest = s2.maximum();
        return result;
    }

         
// TALAL EL ZEINI  CIST 004B
    statistician operator *(double scale, const statistician& s)
    {
       statistician result;
       
        if(s.length()==0)
        {return s;}
       
        result.count = s.count;
        result.total =  scale * s.length() * s.mean();
        if(scale<0)
        {
            result.tinyest = scale * s.maximum();
            result.largest = scale * s.minimum();
        }else{
        result.tinyest = scale * s.minimum();
        result.largest = scale * s.maximum();
        }
        return result;
    }




bool operator ==(const statistician& s1, const statistician& s2)
{
    if (s1.length() != s2.length())
        return false;
    if (s1.length() == 0)
        return true;
    return ((s1.mean() == s2.mean()) &&
            (s1.sum() == s2.sum())   &&
            (s1.minimum() == s2.minimum()) &&
            (s1.maximum() == s2.maximum())    );
}

}
// TALAL EL ZEINI  CIST 004B
