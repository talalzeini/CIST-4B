//
//  main.cpp
//  sequence array
//
//  Created by Talal Zeini on 2/21/20.
//  Copyright © 2020 Talal Zeini. All rights reserved.
//

#include "sequence2.h"
#include <iostream>

using namespace std;
namespace main_savitch_4
{


// Talal El Zeini CIST 004B
const sequence::size_type sequence::DEFAULT_CAPACITY;
sequence::sequence(size_type initial_capacity)
    {
        data = new value_type[initial_capacity];
        capacity = initial_capacity;
        used = 0;
        current_index = 0;
    }


// Talal El Zeini CIST 004B


sequence::sequence(const sequence& source)
    {
        data = new value_type[source.capacity];
        capacity = source.capacity;
        used = source.used;
copy(source.data, source.data + used, data);
        current_index = source.current_index;
    }

// Talal El Zeini CIST 004B
sequence::~sequence()
    {
delete [] data;
    }


void sequence::start()
    {
        current_index = 0;
    }


void sequence::advance()
    {
        current_index+=1;
    }


bool sequence::is_item() const
    {
if(current_index>=used)
        {
return false;
        }
else
        {
return true;
        }
    }

sequence::size_type sequence::size()const
    {
return used;
    }

sequence::value_type sequence::current()const
    {
assert(is_item());
return data[current_index];
    }

// Talal El Zeini CIST 004B
void sequence::insert(const value_type& entry)
    {

if(used>= capacity)
        {
resize((capacity + 1)*1.1);
        }
if(is_item()==false)
        {
            current_index = 0;
        }
if(used>0)
        {
for( int i = used-1; i>=(int)current_index; --i)
            {
                data[i+1]=data[i];
            }
        }
        data[current_index] = entry;
        used+=1;
    }


// Talal El Zeini CIST 004B
void sequence::attach(const value_type& entry)
{
    
    if( size() == capacity ){
        resize(capacity+DEFAULT_CAPACITY);
    }
    
    if(!is_item())
    
    current_index = used-1;
    ++current_index;
    
    for(size_type i = used; i >current_index; --i)
        
    data[i] = data[i-1];
    data[current_index] = entry;
    ++used;
    
}

// Talal El Zeini CIST 004B

void sequence::resize(size_type new_capacity)
    {
        value_type * array;
if(new_capacity == capacity)
        {
return;
        }
if(new_capacity < used)
        {
            new_capacity = used;
        }
        array = new value_type[new_capacity];
copy(data, data+used, array);
delete [ ] data;
        data = array;
        capacity = new_capacity;
    }
void sequence::remove_current()
    {

assert(size()>0);
for(size_type i = current_index+1; i<used; i++){
            data[i-1]=data[i];
        }
        used-=1;
    }
// Talal El Zeini CIST 004B

void sequence::operator =(const sequence& source)
    {
        
        if(this == &source) return;
        
        value_type *new_data = new value_type [source.capacity];
        std::copy(source.data, source.data+source.used, new_data);
        delete [] data;
        
        data = new_data;
        used = source.used;
        capacity = source.capacity;
        
        if(source.is_item()){
            current_index = source.current_index;
        }else{
            current_index = used;
        }
}
}
// Talal El Zeini CIST 004B
