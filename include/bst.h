#ifndef _BST_H_
#define _BST_H_

#include <iostream>
#include <fstream>
#include <stack>
#include <string>

#define key_type size_t

template< typename T >
class bst
{
	private:
		struct Node{
			key_type key;	// Key of the node
			T value;        // Node content (maybe not necessary? TODO: ask silvia)
			Node *l;	    // Left sub-tree.
			Node *r;	    // Right sub-tree.
            Node *f;        // Origin node (or father)
            Node(key_type n_key) : key(n_key){};    // default constructor
            ~Node(){ delete l; delete r; };         // default destructor
		};

		size_t m_size;	// Number of nodes.
		Node * m_root;	// Tree root node.
        Node * auxiliar_node;

        // auxiliary functions
        void add_son(Node *& father, Node *& son){
            if( son->key > father ){
                father->r = son;
            } else {
                father->l = son;
            }
        }
	
	public:
		//!< Void Constructor
        bst();

		//!< Copy Constructor
		// bst( bst<T> &rhs );

		//!< Destructor
		// ~bst();
        
		//!< Searches for a specific value inside tree.
		Node find( T key, Node pt );

        //!< Insert function
		void insert( Node*& root, key_type key/* , T value */ );

        //!< Remove function
		void remove(/* TODO */);

		//!< Returns nth element, going from 1 with in-order path of bst.
		T nthElement( size_t n );

		//!< Returns position occupied by value, with in-order path.
		int position( T value );

		/*! Returns element containing median of bst.
		 * If bst has a even number of elements, return smallest median.
		 */
		T median();

		//!< Returns True if the bst is a full tree. False otherwise
		bool isFull();

		//!< Returns True if the bst is a complete tree. False otherwise.
		bool isComplete();

		//!< Returns a string cointaning the bst travelling sequence by level.
		std::string toString();
};

// source code
#include "bst.inl"
#endif
