#include <iostream>
#include "bst.h"


/* Standard methods{{{*/
//!< Searches for a specific value inside tree.
template< typename T >
Node busca( T key, Node pt )
{
}

template< typename T >
void insert( Node*& root, T key, T value )
{
}

template< typename T >
void remove(/* TODO */)
{
}
/*}}}*/
/* Additional Methods{{{*/

//!< Returns nent element, going from 1 with in-order path of bst.
template< typename T >
T enesimoElemento( int n )
{
}

//!< Returns position occupied by value, with in-order path.
template< typename T >
int pos( T value )
{
}

/*! Returns element containing median of bst.
 * If bst has a even number of elements, return smallest median.
*/
template< typename T >
T median()
{
}

//!< Returns True if the bst is a full tree. False otherwise
template< typename T >
bool isFull()
{
}

//!< Returns True if the bst is a complete tree. False otherwise.
template< typename T >
bool isComplete()
{
}

//!< Returns a string cointaning the bst travelling sequence by level.
template< typename T >
std::string toString()
{
}
/*}}}*/


