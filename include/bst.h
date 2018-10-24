#ifndef _BST_H_
#define _BST_H_

#include <iostream>
#include <fstream>
#include <queue>
#include <string>

#define key_type long int
#define log false

template <typename T>
class bst
{
	private:
		struct Node{
			key_type key;	        // Key of the node
			T value;                // Node content (TODO: ask silvia)
			
			Node *l = nullptr;	                    // Left sub-tree.
			Node *r = nullptr;	                    // Right sub-tree.
            Node *f = nullptr;                      // Origin node (or father)

            Node(key_type n_key) : key(n_key){};    // default constructor
            ~Node(){ /* delete l; delete r; delete f; */ };         // default destructor
		};

		size_t m_size;	        // Number of nodes.
		Node * m_root;	        // Tree root node.
        Node * auxiliar_node;   // Auxiliar node, used in some functions

        //!< A function to make the link between father & son nodes
        void add_son( Node *& father, Node *& son );
	
        //!< Insert function
		bool insert( Node*& root, key_type key/* , T value */ );
        bool p_remove( Node *& root );
        Node * find_pred( Node *& actual );
        void makeFather( Node *& father, Node *& l_son, Node *& r_son );

		//!< Private function for find
		Node * busca( Node *&, key_type );

	public:
		//!< Void Constructor
        bst();

		//!< Copy Constructor
        bst( bst<T> &rhs );

		//!< Destructor
        ~bst(){ /* empty */};
        
		//!< Searches for a specific value inside tree.
		Node find( T key ){ return busca(this->m_root, key); }; // need to return index, not node

        //!< Add key to the binary tree
        bool add( key_type key ){ return insert(this->m_root, key); };

        //!< Remove function
		void remove( key_type key );

		//!< Returns nth element, going from 1 with in-order path of bst.
		T nthElement( size_t n );

		//!< Returns position occupied by value, with in-order path.
		int position( T value );

        //!< Returns the median of the Tree
		T median();

		//!< Returns True if the bst is a full tree. False otherwise
		bool isFull();

		//!< Returns True if the bst is a complete tree. False otherwise.
		bool isComplete();

		//!< Returns a string cointaning the bst travelling sequence by level.
		std::string toString();
};

// Source code
#include "bst.inl"

#endif
