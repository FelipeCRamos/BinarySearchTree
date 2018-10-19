#ifndef _BST_H_
#define _BST_H_

#include <iostream>
#include <fstream>
#include <stack>
#include <string>

template< typename T >
class bst
{
	private:
		struct Node{
		/* Essa parte de value e key n sei se precisa diferenciar
		 * ou usar só conteúdo msm ta ligado. RAMOS
		 */
			T value;
			T key;		
			Node* l;	// Left sub-tree.
			Node* r;	// Right sub-tree.
		};

		size_t m_size;	// Number of nodes.
		Node* m_root;	// Tree root node.
	
	public:
		/* Constructors and Destructors{{{*/
		//!< Void Constructor
		bst(){}

		//!< Copy Constructor
		bst( bst<T> &rhs )
		{
		}

		//!< Destructor
		~bst(){/*empty*/}
		/*}}}*/
		/* Standard methods{{{*/
		//!< Searches for a specific value inside tree.
		Node busca( T key, Node pt );

		void insert( Node*& root, T key, T value );

		void remove(/* TODO */);
		/*}}}*/
		/* Additional Methods{{{*/

		//!< Returns nent element, going from 1 with in-order path of bst.
		T enesimoElemento( int n );

		//!< Returns position occupied by value, with in-order path.
		int pos( T value );

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
		/*}}}*/

};

#endif
