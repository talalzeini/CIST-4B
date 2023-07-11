// TALAL EL ZEINI CIST 004B

#ifndef MAIN_SAVITCH_SEQUENCE4_H
#define MAIN_SAVITCH_SEQUENCE4_H 

#include <iostream> 

namespace main_savitch_6B
{
    template<class Item>
    class sequence
    {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef std::size_t size_type;
        // CONSTRUCTORS and DESTRUCTOR
        sequence( );
        sequence(const sequence& source);
        ~sequence( );
        // MODIFICATION MEMBER FUNCTIONS
        void start( );
        void advance( );
        void insert(const Item& entry);
        void attach(const Item& entry);
        void operator =(const sequence& source);
        void remove_current( );
        // CONSTANT MEMBER FUNCTIONS
        size_type size( ) const { return many_nodes; }
        bool is_item( ) const { return (cursor != NULL); }
        Item current( ) const;

    private:
    node<Item> *head_ptr;
	node<Item> *tail_ptr;
	node<Item> *cursor;
	node<Item> *precursor;
	size_type many_nodes;
    };
}
#include "sequence4.cxx"
#endif
// TALAL EL ZEINI CIST 004B
