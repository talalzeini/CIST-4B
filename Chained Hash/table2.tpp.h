// Talal El Zeini CIST 004B
// FILE: table2.tpp.h
// TEMPLATE CLASS IMPLEMENTED: Table (see table2.h for documentation)
// INVARIANT for the Table ADT:
//   1. The number of records in the Table is in the member variable
//      total_records.
//   2. The actual records of the table are stored in a chained hash table.
//      An entry with key i is stored on the linked list with the head
//      pointer at data[hash(i)].
// Talal El Zeini CIST 004B

#include <assert.h> // Provides assert
#include <stdlib.h> // Provides nullptr, size_t
#include "link2.h"  // Provides the linked list toolkit

template <class RecordType>
Table<RecordType>::Table( )
// Library facilities used: stdlib.h
{
    size_t i;

    total_records = 0;
    for (i = 0; i < TABLE_SIZE; i++)
        data[i] = nullptr;
}

template <class RecordType>
Table<RecordType>::Table(const Table<RecordType>& source) 
// Library facilities used: link2.h, stdlib.h 
{
    size_t i;
    Node<RecordType>* tail_ptr; // Needed for list_copy

    for (i = 0; i < TABLE_SIZE; i++)
        list_copy(source.data[i], data[i], tail_ptr);
    total_records = source.total_records;
}

template <class RecordType>
Table<RecordType>::~Table( )
// Library facilities used: link2.h
{
    size_t i;

    total_records = 0;
    for (i = 0; i < TABLE_SIZE; i++)
        list_clear(data[i]);
}

// Talal El Zeini CIST 004B
template <class RecordType>
void Table<RecordType>::insert(const RecordType& entry)
// Library facilities used: assert.h, link2.h
{
    Node<RecordType>* cursor;
    Node<RecordType> *precursor;
    assert(entry.key >= 0);
    precursor = nullptr;
    cursor = find_node(entry.key);

    if (cursor != nullptr){
        cursor -> data = entry;
    }else{
        list_head_insert(data[hash(entry.key)], entry);
        total_records++;
    }
}

// Talal El Zeini CIST 004B
template <class RecordType>
void Table<RecordType>::remove(int key)
// Library facilities used: assert.h, link2.h
{
   
Node<RecordType> *cursor;  
Node<RecordType> *precursor;

assert(key >= 0);
cursor = data[hash(key)];
precursor = nullptr;
  while ((cursor != nullptr) && ((cursor->data).key != key))
  {
      precursor = cursor;
      cursor = cursor->link;
  }
      if ((cursor != nullptr) && (precursor != nullptr))
      {
          list_remove(precursor);
          total_records--;
      }else if (cursor != nullptr){
            list_head_remove(data[hash(key)]);
            total_records--;
        }
}

// Talal El Zeini CIST 004B
template <class RecordType>
void Table<RecordType>::operator =(const Table<RecordType>& source) 
// Library facilities used: link2.h, stdlib.h 
{
    size_t i;
    Node<RecordType>* tail_ptr; // Needed for list_copy

    if (this == &source)
        return; 

    for (i = 0; i < TABLE_SIZE; i++)
    {
	list_clear(data[i]);
  list_copy(source.data[i], data[i], tail_ptr);
    }
    total_records = source.total_records;
}

// Talal El Zeini CIST 004B
template <class RecordType>
bool Table<RecordType>::is_present(int key) const
// Library facilities used: assert.h, stdlib.h
{
    assert(key >= 0);
    return (find_node(key) != NULL); 
}

template <class RecordType>
void Table<RecordType>::find(int key, bool& found, RecordType& result) const
// Library facilities used: stdlib.h
{
    Node<RecordType> *cursor;
    cursor = find_node(key);
    found = (cursor != nullptr);
    if (found)
        result = cursor->data;

}

// Talal El Zeini CIST 004B
template <class RecordType>
size_t Table<RecordType>::hash(int key) const
// Library facilities used: stdlib.h
{
    return (key % TABLE_SIZE);
}

// Talal El Zeini CIST 004B
template <class RecordType>
Node<RecordType>* Table<RecordType>::find_node(int key) const
// Postcondition: The return value is a pointer to the record with the
// specified key (if there is one). If there is no such node, the return value
// is the nullptr pointer.
// Library facilities used: link2.h, stdlib.h
{
    Node<RecordType>* cursor = nullptr;

    cursor = data[hash(key)];
    while (cursor != nullptr){
        if (cursor -> data.key == key) {
            return cursor;
        }
        cursor = cursor -> link;
    }

    return cursor;
}

