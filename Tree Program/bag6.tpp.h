#include <cassert>
#include <cstdlib>
// Talal El Zeini CIST 004B
// Talal El Zeini CIST004B
namespace main_savitch_10
{

    template <class Item>
	void bst_remove_max(binary_tree_node<Item>*& root_ptr, Item& removed)
	{
	    if(root_ptr == nullptr)
        {
            return;
        }
        else if(root_ptr -> right()== nullptr)
        {
            removed = root_ptr -> data();
            binary_tree_node <Item> *to_delete = root_ptr;
            root_ptr = root_ptr -> left();
            delete to_delete;
        }
        else
        {
            bst_remove_max(root_ptr -> right(), removed);
        }

	}
// Talal El Zeini CIST004B
    template <class Item>
	bool bst_remove(binary_tree_node<Item>*& root_ptr, const Item& target)\
	{
	    binary_tree_node<Item> *oldroot_ptr;

	    if (root_ptr == nullptr)
	    {   
			return false;
	    }

	    if (target < root_ptr->data( ))
	    {  
			return bst_remove(root_ptr->left( ), target);
	    }

	    if (target > root_ptr->data( ))
	    {   
			return bst_remove(root_ptr->right( ), target);
	    }

	    if (root_ptr->left( ) == nullptr)
	    {  
			oldroot_ptr = root_ptr;
			root_ptr = root_ptr->right( );
			delete oldroot_ptr;
			return true;
	    }

	    bst_remove_max(root_ptr->left( ), root_ptr->data( ));
	    return true;
	}

    template <class Item>
	typename bag<Item>::size_type bst_remove_all(binary_tree_node<Item>*& root_ptr, const Item& target)
	{
	    
	    binary_tree_node<Item> *oldroot_ptr;

	    if (root_ptr == nullptr)
	    {  
	        return 0;
	    }

	    if (target < root_ptr->data( ))
	    {   
	        bst_remove(root_ptr -> left(), target);
	    }

	    if (target > root_ptr->data( ))
	    {   
	        bst_remove(root_ptr -> right(), target);
	    }

	    if (root_ptr->left( ) == nullptr)
	    {   
			oldroot_ptr = root_ptr;
			root_ptr = root_ptr->right( );
			delete oldroot_ptr;
			return 1;
	    }
	    bst_remove_max(root_ptr->left(), root_ptr->data());
	    return 1+bst_remove_all(root_ptr, target);
	}

    template <class Item>
	bag<Item>::bag()

	{
	    root_ptr = nullptr;
	}

    template <class Item>
	bag<Item>::bag(const bag<Item>& source)

	{
	    root_ptr = tree_copy(source.root_ptr);
	}

    template <class Item>
	bag<Item>::~bag( )
	{
	    tree_clear(root_ptr);
	}

    template <class Item>
	typename bag<Item>::size_type bag<Item>::size( ) const

	{
	    return tree_size(root_ptr);
	}

   template <class Item>
    void bag<Item>::insert(const Item& entry)

    {
        binary_tree_node<Item> *cursor;

        if (root_ptr == nullptr)
        {  
            root_ptr = new binary_tree_node<Item>(entry);
            return;
        }

        else
        {  
            cursor = root_ptr;
            binary_tree_node<Item> *insert_ptr;
            insert_ptr = new binary_tree_node<Item> (entry);
            bool finished = false;

             while(!finished)
            {
                if (cursor->data() < entry)
                {
                    if (cursor->right() == nullptr)
                    {
                        cursor -> right() = insert_ptr; 
                        finished = true;
                    }

                    cursor = cursor -> right();
                }

                else
                {
                    if (cursor->left() == nullptr)
                    {
                        cursor->left() = insert_ptr;
                        finished = true;
                    }

                    cursor=cursor->left();
                }

            }

        }

    }

    template <class Item>
	typename bag<Item>::size_type bag<Item>::count(const Item& target) const
	{
	    size_type answer = 0;
	    binary_tree_node<Item> *cursor = root_ptr;

	    if(root_ptr == nullptr)
        {
            return 0;
        }
        else
        {
            while(cursor!=nullptr)
            {
                if(cursor ->data() < target)
                {
                    cursor=cursor->right();
                }
                else if(cursor -> data() > target)
                {
                    cursor = cursor->left();
                }
                else if(cursor -> data() == target)
                {
                    answer++;
                    cursor=cursor->left();
                }
            }
        }

	    return answer;
	}
// Talal El Zeini CIST004B
    template <class Item>
	typename bag<Item>::size_type bag<Item>::erase(const Item& target)
	{
	    return bst_remove_all(root_ptr, target);
	}

    template <class Item>
	bool bag<Item>::erase_one(const Item& target)
	{
	    return bst_remove(root_ptr, target);
	}

    template <class Item>
	void bag<Item>::operator =(const bag<Item>& source)

    {
	    if (root_ptr == source.root_ptr)
	        return;
	    tree_clear(root_ptr);
	    root_ptr = tree_copy(source.root_ptr);
	}

    template <class Item>
	void bag<Item>::operator +=(const bag<Item>& addend)
    {
	    if (root_ptr == addend.root_ptr)
	    {
			bag<Item> copy = addend;
			insert_all(copy.root_ptr);
	    }
	    else
	        insert_all(addend.root_ptr);
	}

    template <class Item>
	bag<Item> operator +(const bag<Item>& b1, const bag<Item>& b2)
	{
	    bag<Item> answer = b1;
	    answer += b2;
	    return answer;
	}

    template <class Item>
	void bag<Item>::insert_all(binary_tree_node<Item>* addroot_ptr)
	{
	    if (addroot_ptr != nullptr)
	    {
			insert(addroot_ptr->data( ));
			insert_all(addroot_ptr->left( ));
			insert_all(addroot_ptr->right( ));
	    }
	}
}
// Talal El Zeini CIST004B
// Talal El Zeini CIST004B