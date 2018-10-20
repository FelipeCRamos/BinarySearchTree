#include <iostream>

#include "bst.h"

#define log true

//!< Void constructor
template <typename T>
bst<T>::bst(void){
    // initialize with empty tree
    this->m_root = nullptr;
    this->m_size = 0;
}

//!< Searches for a specific value inside tree.
template< typename T >
typename bst<T>::Node bst<T>::find( T key, Node pt )
{
    // TODO
}

template< typename T >
void bst<T>::insert( Node *& root, key_type key/* , T value */ )
{
    if( this->m_size == 0 ){        // it's an empty tree
        this->m_root = root;
        this->m_size++;
    } else {
        if( root == nullptr ){
            root = new Node(key);   // links atual node for new-node
            this->m_size++;         // increment the quantity of nodes
            add_son(auxiliar_node, root); // link him to the father node
            if(log)
            {
                std::cout << "STATUS: ";
                std::cout << "Node added! Info:" << std::endl;
                std::cout << "\tFather: " << root->f << std::endl;
                std::cout << "\tLeft son: " << root->l << std::endl;
                std::cout << "\tRight son: " << root->l << std::endl;
            }
            
            
        } else if ( root->key > key ){
            this->auxiliar_node = root;
            insert( root->r, key);  // key is bigger than

        } else if ( root->key < key ){
            this->auxiliar_node = root;
            insert( root->l, key);  // key is smaller than

        } else if ( root->key == key ){
            std::cerr << "ERROR[00]: Key already exists, not inserting.\n";
            return;                 // key already exists
        } else {
            std::cerr << "ERROR[01]: Not predicted this case, please report!\n";
        }
    }
}
/*

template< typename T >
void bst<T>::remove()
{
}

//!< Returns nent element, going from 1 with in-order path of bst.
template< typename T >
T bst<T>::nthElement( size_t n )
{
}

//!< Returns position occupied by value, with in-order path.
template< typename T >
int bst<T>::position( T value )
{

}

template< typename T >
T bst<T>::median()
{
}

//!< Returns True if the bst is a full tree. False otherwise
template< typename T >
bool bst<T>::isFull()
{
}

//!< Returns True if the bst is a complete tree. False otherwise.
template< typename T >
bool bst<T>::isComplete()
{
}

//!< Returns a string cointaning the bst travelling sequence by level.
template< typename T >
std::string bst<T>::toString()
{
}
*/
