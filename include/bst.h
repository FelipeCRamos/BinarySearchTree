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
			
			Node *l = nullptr;		// Left sub-tree.
			Node *r = nullptr;		// Right sub-tree.
            Node *f = nullptr;		// Origin node (or father)

			size_t sub_l;			// Number os nodes in the left sub-tree
			size_t sub_r;			// Number of nodes in the right sub_tree

            Node(key_type n_key) : key(n_key){};    // default constructor
            ~Node(){ /* delete l; delete r; delete f; */ };         // default destructor
		};

		enum code_t {
				INSERT=0,
				REMOVE
		};
		

		size_t m_size;	        // Number of nodes.
		Node * m_root;	        // Tree root node.
        Node * auxiliar_node;   // Auxiliar node, used in some functions

        //!< A function to make the link between father & son nodes
        void add_son( Node *& father, Node *& son );
	
        //!< Insert function
        bool p_remove( Node *& root );
        Node * find_pred( Node *& actual );
        void makeFather( Node *& father, Node *& l_son, Node *& r_son );
		/* Private functions{{{*/
		Node * busca( Node *&, key_type );	//!< For find
		bool insert( Node*&, key_type );	//!< For add
		void exclude( Node*&, key_type );	//!< For remove
		/*}}}*/
	public:
		//!< Void Constructor
        bst();

		//!< Copy Constructor
        bst( bst<T> &rhs );

		//!< Destructor
        ~bst(){ /* empty */};
		/* Standard methods{{{*/
		//!< Searches for a specific value inside tree./
		Node find( T key ){ return busca(this->m_root, key); };

        //!< Add key to the binary tree
        bool add( key_type key ){ return insert(this->m_root, key); };

        //!< Remove function
		void remove( key_type key ){ return exclude(this->m_root, key); };
		/*}}}*/

		//!< Returns nth element, going from 1 with in-order path of bst.
		key_type nthElement( size_t n );

		//!< Returns position occupied by key, with in-order path.
		int position( key_type key );

        //!< Returns the median of the Tree
		key_type median();

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
