#include "sequence1.h"
#include <algorithm>
#include <iostream>

using namespace std;
//Talal El Zeini CIST 004B
namespace main_savitch_3
{


    sequence::sequence()
    {
        current_index = 0;
        used = 0;
    }
   
    void sequence::start()
    {
        current_index = 0;
    }

    void sequence::advance()
    {
        ++current_index;
    }

    void sequence::insert(const value_type& entry)
    {
          if (is_item())
       {
           for (size_type i = used; i > current_index; i--)
               data[i] = data[i-1];
           used++;
           data[current_index] = entry;
       }
       else
       {
           for (size_type j = used; j > 0; j--)
               data[j] = data[j-1];
           used++;
           current_index = 0;
           data[current_index] = entry;
       }
        
    }
//Talal El Zeini CIST 004B
   void sequence::attach(const value_type& entry)
     {
        if (is_item())
        {
            for (size_type i = used; i > current_index + 1; i--)
                data[i] = data[i-1];
            used++;
            current_index++;
            data[current_index] = entry;
        }
        else
        {
            used++;
            current_index = used - 1;
            data[current_index] = entry;
        }
     }
    void sequence::remove_current( )
      {
         size_type i;

         assert( is_item( ) );

         for ( i = current_index + 1; i < used; ++i )
            data[i-1] = data[i];
         --used;
      }
   sequence::size_type sequence::size( ) const
   {
      return used;
   }



   bool sequence::is_item( ) const
   {
      return (current_index < used);
   }

   sequence::value_type sequence::current( ) const
   {
      assert( is_item( ) );
      return data[current_index];
   }
}
//Talal El Zeini CIST 004B
