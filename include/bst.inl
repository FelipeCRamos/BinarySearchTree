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
typename bst<T>::Node * bst<T>::busca( Node *& root, key_type key )
{
	if( this->m_size == 0 or root == nullptr ){
		std::cerr << "ERROR[010]: Key not present in tree! Try another key.\n";
		return nullptr;
    } else if( root->key < key ) {      // key is bigger than
		return busca(root->r, key);		
	} else if( root->key > key ) {      // key is smaller than
		return busca(root->l, key);
	} else if( root->key == key ) {     // key found
		return root;
	} else {
		std::cerr << "ERROR[011]: Not predicted this case, please report!\n";
		return nullptr;
	}
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
void bst<T>::makeFather( Node *& father, Node *& l_son, Node *& r_son ){
    if( l_son != nullptr ){
        l_son->f = father;
    }
    if( r_son != nullptr ){
        r_son->f = father;
    }
    father->r = r_son;
    father->l = l_son;
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
void bst<T>::exclude( Node*& root, key_type key)   // TODO: Make arrangments if the node == m_root
{
	if(this->m_size == 0 or root == nullptr )
	{
		std::cerr << "ERROR[010]: Key not present in tree! Try another key.\n";
		return;
	}
	if(root->key < key )
	{
		if(root->r != nullptr)
		{
			exclude(root->r, key);
		}
		std::cerr << "ERROR[010]: Key not present in tree! Try another key.\n";
		return;
	}
	else if(root->key > key)
	{
		if(root->l != nullptr)
		{
			exclude(root->l, key);
		}
		std::cerr << "ERROR[010]: Key not present in tree! Try another key.\n";
		return;
	}
	else
	{
		// Reached node to remove. Now we have 3 cases.
		if( root->l == nullptr )
		{
			if(root->r == nullptr )
			{
				// Removable key has no children.
				// Now see if removable is a left or right.
				if(root->f->r == root)
				{
					root->f->r = nullptr;
					return;
				}
				root->f->l = nullptr;
				return;
			}
			// Removable key has only a right children
			// Now see if removable is a left or right child.
			if(root->f->r == root)
			{
				root->f->r = root->r;
				return;
			}
			root->f->l = root->r;
			return;
		}
		else if( root->r == nullptr )
		{
			// Removable key has only a left children
			// Now see if removable is a left or right child.
			if(root->f->r == root)
			{
				root->f->r = root->l;
				return;
			}
			root->f->l = root->l;
			return;
		}
		else
		{
			// Removable has both right and left children.
			// In this case, we need to find the right value for exchange.
			auto pred = find_pred(root);
			root->key = pred->key;
			pred->f->r = nullptr;
			return;
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
    if(this->m_root == nullptr){
        return buf;
    }

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
