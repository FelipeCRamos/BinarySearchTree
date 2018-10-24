#include <iostream>

#include "bst.h"

#define log false   // Log for debug

template <typename T>
void bst<T>::add_son( Node *& father, Node *& son ){
    if(log){
        std::cout << "[add_son] -> father = " << father->key 
        << " - " << father << std::endl;
        std::cout << "[add_son] -> son = " << son->key 
        << " - " << son << std::endl;
    }
    son->f = father;
    if( son->key > father->key ){
        father->r = son;
        if(log){
            std::cout << "[add_son] -> success: father->r = son\n";
            std::cout << "[add_son] -> father->r = " << father->r << "\n";
        }
        } else {
            father->l = son;
            if(log){
                std::cout << "[add_son] -> success: father->l = son\n";
                std::cout << "[add_son] -> father->l = " << father->l << "\n";
            }
    }
}

//!< Void constructor
template <typename T>
bst<T>::bst(void){
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
bool bst<T>::insert( Node *& root, key_type key/* , T value */ )
{
    if( this->m_size == 0 ){        // it's an empty tree
        this->m_root = new Node(key);
        this->m_size++;
        return true;
    } else {
        if( root == nullptr ){
            root = new Node(key);   // links atual node for new-node
            this->m_size++;         // increment the quantity of nodes

            add_son(auxiliar_node, root); // link father & son

            if(log)
            {
                std::cout << "STATUS: ";
                std::cout << "Node added! Info:" << std::endl;
                std::cout << "\tFather: " << root->f << std::endl;
                std::cout << "\tLeft son: " << root->l << std::endl;
                std::cout << "\tRight son: " << root->r << std::endl;
            }
            return true;
            
        } else if ( root->key < key ){
            this->auxiliar_node = root;
            insert( root->r, key);  // key is bigger than

        } else if ( root->key > key ){
            this->auxiliar_node = root;
            insert( root->l, key);  // key is smaller than

        } else if ( root != nullptr && root->key == key ){
            std::cerr << "ERROR[00]: Key already exists, not inserting.\n";
            return false;
        } else {
            std::cerr << "ERROR[01]: Not predicted this case, please report!\n";
            return false;
        }
    }
    return false;
}

template <typename T>
typename bst<T>::Node * bst<T>::find_pred( Node *& actual ){
    Node *it = actual;
    if( actual->l != nullptr ){
        it = actual->l;
    } else {
        return actual;
    }
    while( it->r != nullptr ){
        it = it->r;
    }
    return it;
}

template< typename T >
void bst<T>::remove(key_type key)   // TODO: Make arrangments if the node == m_root
{
    // find the node that has the key
    Node * key_holder /*= find(key)*/;
    // call for private recurssive function

    if( key_holder->l == nullptr && key_holder->r == nullptr ){
        // just remove-it
        Node * father = key_holder->f;

        // this if-else is to remove the link from father->son
        if( father->r == key_holder ){
            // it's the right son!
            father->r = nullptr;    // remove link from father
        } else if( father->l == key_holder ){
            // it's the left son!
            father->l = nullptr;    // remove link from father
        } else {
            std::cerr << "ERROR[05]: Not predicted this one! Please report!\n";
            return;
        }

        // now, let's remove the son!
        delete key_holder;
    }
    else if( key_holder->l == nullptr ^ key_holder->r == nullptr ){
        // either r or l are null, not both
        if( key_holder->l == nullptr ){
            // right node will substitute his father
            key_holder->key = key_holder->r;
            // and then: remove link & delete node
            delete key_holder->r;
            key_holder->r = nullptr;

        } else {
            // left node will substitute his father 
            key_holder->key = key_holder->l;

            // and then: remove link & delete node
            delete key_holder->l;
            key_holder->l = nullptr;
        }
    } else {
        // the node we want to remove has both sons, TODO
        // find predecessor
        Node * pred = find_pred(key_holder);
        // change current node with predecessor
        key_holder->key = pred->key;
        // remove predecessor
        Node * father_pred = pred->f;
        if( father_pred->r == pred ){
            // pred is the right son of father_pred
            father_pred->r = nullptr;
            delete pred;
        } else if ( father_pred->l == pred ){
            // pred is the left son of father_pred
            father_pred->l = nullptr;
            delete pred;
        }
    }
}

//!< Returns nent element, going from 1 with in-order path of bst.
template< typename T >
T bst<T>::nthElement( size_t n )
{
    // TODO
}

//!< Returns position occupied by value, with in-order path.
template< typename T >
int bst<T>::position( T value )
{
    // TODO
}

template< typename T >
T bst<T>::median()
{
    // TODO
}

//!< Returns True if the bst is a full tree. False otherwise
template< typename T >
bool bst<T>::isFull()
{
    // TODO
}

//!< Returns True if the bst is a complete tree. False otherwise.
template< typename T >
bool bst<T>::isComplete()
{
    // TODO
}

//!< Returns a string cointaning the bst travelling sequence by level.
template< typename T >
std::string bst<T>::toString()
{
    std::string buf;
    std::queue<Node *> to_print;

    to_print.push(this->m_root);
    while(!to_print.empty())
    {
        Node *actual = to_print.front();
        to_print.pop();

        buf += std::to_string(actual->key) + " ";
        // buf += " ";

        if(actual->l != nullptr){
            to_print.push(actual->l);
        }
        if(actual->r != nullptr){
            to_print.push(actual->r);
        }
    }    

    return buf;
}
