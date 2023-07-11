// TALAL EL ZEINI CIST 004B
// TALAL EL ZEINI CIST 004B

#include <cassert> 
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "node2.h"
#include "sequence4.h"
using namespace std;
namespace main_savitch_6B
{
    template<class Item>
    sequence<Item>::sequence()
    {
        head_ptr = 0;
        tail_ptr = 0;
        cursor = 0;
        precursor= 0;
        many_nodes = 0;
    }
    template<class Item>
    sequence<Item>::sequence(const sequence& source)
    {
   if (source.is_item() == false) 
   {
       list_copy(source.head_ptr, head_ptr, tail_ptr); 
       precursor = 0;
       cursor = 0;
   }else if (source.cursor == source.head_ptr)
          {
               list_copy(source.head_ptr, head_ptr, tail_ptr);
                precursor = 0;
               cursor = head_ptr;
          }else{
                list_copy(source.head_ptr, head_ptr, tail_ptr);
                node<Item>* temp = source.head_ptr;
                this->start();
                while (temp != source.cursor)
       {
           temp = temp->link(); 
           this->advance();
       }
       }
   many_nodes = source.many_nodes; 
    }
    template<class Item>
    sequence<Item>::~sequence()
        {
            list_clear(head_ptr);
        }
    template<class Item>
    void sequence<Item>::start()
    {
        if(head_ptr==0)
        {
            cursor=0;
            precursor=0;
        }
        else
        {
            precursor = 0;
            cursor=head_ptr;
        }
    }
    // TALAL EL ZEINI CIST 004B
    // TALAL EL ZEINI CIST 004B 
    template<class Item>
    void sequence<Item>::advance()
    {
        assert(is_item());
        precursor=cursor;
        cursor = cursor->link();
    }
    template<class Item>
    void sequence<Item>::insert(const Item& entry)
    {
        if (is_item( ))
        {
            if(precursor==0 || cursor==0)
            {
                list_head_insert(head_ptr, entry);
                cursor=head_ptr;
                precursor=0;
            }
            else
            {
                list_insert(precursor, entry);
                cursor= precursor->link();
            }
        }
        else
        {
            list_head_insert(head_ptr, entry);
            cursor = head_ptr;
            precursor=0;
        }
	++many_nodes;
}
    template<class Item>
    void sequence<Item>::attach(const Item& entry)
    {
        if (is_item( ))
        {
            precursor = cursor;
            list_insert(cursor, entry);
            cursor=cursor->link();
        }
        else
        {
            if(head_ptr==0)
            {
                list_head_insert(head_ptr, entry);
                cursor = head_ptr;
                precursor=0;
            }
            else
            {
                precursor=list_locate(head_ptr,list_length(head_ptr));
                list_insert(precursor,entry);
                cursor=precursor->link();
            }
        }
	++many_nodes;
    }
    template<class Item>
    void sequence<Item>::remove_current()
    {
        assert(is_item());
        if(cursor == head_ptr)
        {
            if(many_nodes == 1)
            {
                list_head_remove(head_ptr);
                precursor = 0;
                cursor = 0;
                head_ptr = 0;
            }
            else
            {
                node<Item>* tmp = head_ptr;
                head_ptr = head_ptr->link();
                delete (tmp);
                cursor = head_ptr;
                precursor = 0;
            }
        }
        else
        {
            cursor = cursor -> link();
            list_remove(precursor);
        }
        --many_nodes;
    }
    template<class Item>
    void sequence<Item>::operator =(const sequence& source)
    {
        if(this == &source)
        {
            return;
        }
        else
        {
            list_copy(source.head_ptr, head_ptr, tail_ptr);
            if(source.precursor == 0)
            {
                if(source.cursor == 0)
                {
                    cursor = 0;
                    precursor = 0;
                }
                else
                {
                    cursor = head_ptr;
                    precursor = 0;
                }
            }
            else
            {
                node<Item> *tmp_ptr = head_ptr;
                node<Item> *source_ptr = source.head_ptr;
                while(source_ptr != source.precursor)
                {
                    source_ptr = source_ptr -> link();
                    tmp_ptr = tmp_ptr -> link();
                }
                cursor = tmp_ptr -> link();
                precursor = tmp_ptr;
            }
        }
	many_nodes = source.many_nodes;

    }
    template<class Item>
    Item sequence<Item>::current() const
    {
        assert(is_item());
        return cursor->data();
    }
}
// TALAL EL ZEINI CIST 004B
