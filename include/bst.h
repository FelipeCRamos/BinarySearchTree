#ifndef _BST_H_
#define _BST_H_

#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <cmath>

#define key_type long int

template <typename T>
class bst
{
	private:
	/* Private members{{{*/
		struct Node{
			key_type key;	        // Key of the node
			
			Node *l = nullptr;		// Left sub-tree.
			Node *r = nullptr;		// Right sub-tree.
            Node *f = nullptr;		// Origin node (or father)

			size_t sub_l = 0;			// Number os nodes in the left sub-tree
			size_t sub_r = 0;			// Number of nodes in the right sub-tree

            Node(key_type n_key) : key(n_key){ /* empty */ };
		};

		//!< Enum for tree updates purposes.
		enum code_t {
            INSERT=0,
            REMOVE
		};
		
        // Control variables
		size_t m_size;	        // Number of nodes.
		Node * m_root;	        // Tree root node.

        // Auxiliar variable
        Node * auxiliar_node;   // Auxiliar node, used in some functions
	/*}}}*/
	public:
	/* Public methods{{{*/
		//!< Void Constructor
        bst( void );

		//!< Destructor
        ~bst( void );

		//!< Searches for a specific value inside tree./
		Node find( T key ){ return i_find(this->m_root, key); };

        //!< Add key to the binary tree
        bool add( key_type key ){ return insert(this->m_root, key); };

        //!< Remove function
		void remove( key_type key ){ return exclude(this->m_root, key); };

		//!< Returns nth element, going from 1 with in-order path of bst.
		key_type nthElement( size_t n ){return i_nth( n, this->m_root);};

		//!< Returns position occupied by key, with in-order path.
		int position( key_type key ){return i_pos(key, this->m_root, 0);};

        //!< Returns the median of the Tree
		key_type median();

		//!< Returns True if the bst is a full tree. False otherwise
		bool isFull();

		//!< Returns True if the bst is a complete tree. False otherwise.
		bool isComplete();

		//!< Returns a string cointaning the bst travelling sequence by level.
		std::string toString();

        //!< Returns the number of elements that the tree has
        size_t size();
	/*}}}*/
    private:
	/* Private methods(){{{*/
		//!< Returns height of given (sub)tree.
		size_t maxHeight( Node * root );

        //!< A function to make the link between father & son nodes
        void add_son( Node *& father, Node *& son );
        
        //!< Set on both l_son->f and r_son->f = father.
        void set_father( Node *& father, Node *& l_son, Node *& r_son );

        //!< Function to find the predecessor of a given node
        Node * find_pred( Node *& actual );

		//!< Auxiliary function for updating tree informations.
		void update(Node *&, code_t);

        //!< An internal find function, to find an key on a given subtree
		Node * i_find( Node *&, key_type );	//!< For find

        //!< An internal insert function, to recursively insert after a node
		bool insert( Node*&, key_type );

        //!< An internal remove function, to remove a given node
		void exclude( Node*&, key_type );

        //!< An internal nthElement function, to return node's key given it's position.
		key_type i_nth( size_t, Node* );

        //!< An internal position function, to return position of a given key of a node.
		int i_pos( key_type, Node*, size_t );

	/*}}}*/
};

// Source code
#include "bst.inl"

#endif
