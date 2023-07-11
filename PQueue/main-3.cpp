// TALAL EL ZEINI CIST004B
#include <iostream>
#include "pqueue1.h"

PriorityQueue::PriorityQueue( )
{
    many_nodes = 0;
    head_ptr = NULL;
}

// TALAL EL ZEINI CIST004B
PriorityQueue::PriorityQueue(const PriorityQueue& source)
{
    if (source.head_ptr == NULL)
    {
        head_ptr = NULL;
        many_nodes = 0;
    }
    else
    {
        head_ptr = new Node;
        head_ptr->link = NULL;

        Node *iter = head_ptr,
             *sIter = source.head_ptr;

        for (int i = 0; i < source.many_nodes - 1; i++)
        {
            iter->data = sIter->data;
            iter->priority = sIter->priority;
        
            iter->link = new Node;
            iter = iter->link;
            sIter = sIter->link;
        }
       
        iter->data = sIter->data;
        iter->priority = sIter->priority;
        iter->link = NULL;
    }
    
    many_nodes = source.many_nodes;
}

// TALAL EL ZEINI CIST004B
PriorityQueue::~PriorityQueue( )
{
    Node *previous,
            *current = head_ptr;
    
    while(current != NULL)
    {
        previous = current;
        current = current->link;
        delete previous;
    }
}

// TALAL EL ZEINI CIST004B
void PriorityQueue::operator =(const PriorityQueue& source)
{
    if (this == &source) return;
    

    Node *sIter,
    *iter = head_ptr;

    while(iter != NULL)
    {
        sIter = iter;
        iter = iter->link;
        delete sIter;
    }

    if (source.head_ptr == NULL)
    {
        head_ptr = NULL;
    }
    else
    {
        iter = head_ptr = new Node;
        sIter = source.head_ptr;

        for (int i = 0; i < source.many_nodes - 1; i++)
        {
            iter->data = sIter->data;
            iter->priority = sIter->priority;
        
            iter->link = new Node;
            iter = iter->link;
            sIter = sIter->link;
        }
   
        iter->data = sIter->data;
        iter->priority = sIter->priority;
        iter->link = NULL;
    }

    many_nodes = source.many_nodes;
}

// TALAL EL ZEINI CIST004B
void PriorityQueue::insert(const Item& entry, unsigned int priority)
{
    Node *iter = head_ptr,
         *previous = NULL,
         *temp;
    while ((iter != NULL) && (priority <= iter->priority))
    {
        previous = iter;
        iter = iter->link;
    }


    if (previous == NULL)
    {
        if (iter = NULL)
        { //case 2: create head
            head_ptr = new Node;
            head_ptr->link = NULL;
            temp = head_ptr;
        }
        else
        {
            previous = new Node;
            previous->link = head_ptr;
            head_ptr = previous;
            temp = head_ptr;
        }
    }
    else
    {
        temp = new Node;
        previous->link = temp;
        temp->link = iter;
    }
   
    temp->data = entry;
    temp->priority = priority;
    many_nodes++;
}

// TALAL EL ZEINI CIST004B
PriorityQueue::Item PriorityQueue::get_front( )
{
    if (many_nodes > 0)
    {
        Node *temp = head_ptr;
        
        head_ptr = head_ptr->link;
        Item frontItem = temp->data;
        
        delete temp;
        many_nodes--;
        return frontItem;

    }
    return 0;
}
