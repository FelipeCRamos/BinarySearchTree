#include "bst.h"

#define log false   // Log for debug

//============================================================= PUBLIC FUNCTIONS 

//!< Void constructor
template <typename T>
bst<T>::bst( void ){
/*{{{*/
    this->m_root = nullptr;
    this->m_size = 0;
}
/*}}}*/

template <typename T>
bst<T>::~bst( void ){
/*{{{*/
    if( this->m_root != nullptr ){
        delete this->m_root;
    }
}
/*}}}*/

//!< Returns the middle element based at a in-order enumeration.
template< typename T >
key_type bst<T>::median() {
/*{{{*/
	if( m_size % 2 == 0 )
	{
		key_type a = nthElement(m_size/2);
		key_type b = nthElement(m_size/2 + 1);
		return (a < b) ? a : b;
	}
	return nthElement( (m_size+1)/2 );
   }
/*}}}*/

//!< Returns True if the bst is a full tree. False otherwise
template< typename T >
bool bst<T>::isFull() {
/*{{{*/
	size_t height = this->maxHeight(this->m_root);
    return pow(2, height)-1 == m_size;   // stub
}
/*}}}*/

//!< Returns True if the bst is a complete tree. False otherwise.
template< typename T >
bool bst<T>::isComplete() {
/*{{{*/

	size_t treeHeight = this->maxHeight(this->m_root);
	if( pow(2, treeHeight)-1 == m_size ) return true;

    std::queue<Node *> to_print;
	std::queue<key_type> lastLevel;
	bool alpha = false;

    if(this->m_root == nullptr || this->m_size == 0){
        return false;
    }

    to_print.push(this->m_root);
	std::cout << "\nPenultimos: ";
    while(!to_print.empty())
    {
        Node *actual = to_print.front();
        to_print.pop();
	
		if( treeHeight - this->distRoot(actual) == 2 )
		{
			alpha = true;
		}

		else{ alpha = false; }

        if(actual->l != nullptr){

			if(alpha){ lastLevel.push(actual->l->key);}
            to_print.push(actual->l);
        }
        if(actual->r != nullptr){
			if(alpha){ lastLevel.push(actual->r->key);}
            to_print.push(actual->r);
        }

		if(alpha) std::cout << actual->key << " ";
    }
	std::cout << "\n";

	size_t nos = this->m_size - lastLevel.size();

	std::cout << "\n LastLevel = " << lastLevel.size() << ", Nos = " << nos << "\n";
	return pow(2, this->maxHeight(this->m_root) - 1)-1 == nos;
}
/*}}}*/

//!< Returns a string cointaning the bst travelling sequence by level.
template< typename T >
std::string bst<T>::toString(){
/*{{{*/
    std::string buf;
    std::queue<Node *> to_print;
    if(this->m_root == nullptr || this->m_size == 0){
        return buf;
    }

    to_print.push(this->m_root);
    while(!to_print.empty())
    {
        Node *actual = to_print.front();
        to_print.pop();

        buf += std::to_string(actual->key) + " ";

        if(actual->l != nullptr){
            to_print.push(actual->l);
        }
        if(actual->r != nullptr){
            to_print.push(actual->r);
        }
    }    

    return buf;
}
/*}}}*/

template <typename T>
size_t bst<T>::size(){
/*{{{*/
    return this->m_size;
}
/*}}}*/

//============================================================ PRIVATE FUNCTIONS 

/*Auxiliary ones{{{*/
template <typename T>
size_t bst<T>::maxHeight( Node* root ){
/*{{{*/
	if( root == nullptr || this->m_size == 0 ) return 0;
	else
	{
		size_t lHeight = this->maxHeight(root->l);
		size_t rHeight = this->maxHeight(root->r);

		// Returns the larger one.
		if( lHeight > rHeight ) return lHeight+1;
		else return rHeight+1;
	}
}
/*}}}*/

template <typename T>
size_t bst<T>::distRoot( Node* root ){
/*{{{*/
	if( root == nullptr || this->m_size == 0 ) return -1;
	size_t dist = 0;

	while( root != this->m_root )
	{
		dist++;
		root = root->f;
	}
	
	return dist;
}
/*}}}*/

template <typename T>
void bst<T>::add_son( Node *& father, Node *& son ){
/*{{{*/
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
/*}}}*/

template <typename T>
void bst<T>::set_father( Node *& father, Node *& l_son, Node *& r_son ){
/*{{{*/
    if( l_son != nullptr ){
        l_son->f = father;
    }
    if( r_son != nullptr ){
        r_son->f = father;
    }
    father->r = r_son;
    father->l = l_son;
}
/*}}}*/

template <typename T>
void bst<T>::update( Node*& actual, code_t type ){
/*{{{*/
	Node *it = actual;
	while( it->f != nullptr ){
//		std::cout << it->key << std::endl;
		if(it->f->r == it){
            if(type == INSERT){
                it->f->sub_r += 1;

            } else if(type == REMOVE){
                it->f->sub_r -= 1;

            } else{
				std::cerr << "ERROR: [D01]\n";
			}
		}
		else if(it->f->l == it){
            if(type == INSERT){
                it->f->sub_l += 1;

            } else if(type == REMOVE){
                it->f->sub_l -= 1;

            } else {
				std::cerr << "ERROR: [D02]\n";
			}

		} else {
            std::cerr << "ERROR: [D03]\n";
		}

		it = it->f;
	}
}
/*}}}*/

template <typename T>
typename bst<T>::Node * bst<T>::find_pred( Node *& actual ){
/*{{{*/
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
/*}}}*/
/*}}}*/
/*Internal versions{{{*/
template< typename T >
typename bst<T>::Node* bst<T>::i_find( Node *& root, key_type key ){
/*{{{*/
	if( this->m_size == 0 or root == nullptr ){
		std::cerr << "ERROR[010]: Key not present in tree! Try another key.\n";
		return nullptr;
    } else if( root->key < key ) {      // key is bigger than
		return i_find(root->r, key);		
	} else if( root->key > key ) {      // key is smaller than
		return i_find(root->l, key);
	} else if( root->key == key ) {     // key found
		return root;
	} else {
		std::cerr << "ERROR[011]: Not predicted this case, please report!\n";
		return nullptr;
	}
}
/*}}}*/

template< typename T >
bool bst<T>::insert( Node *& root, key_type key ){
/*{{{*/
    if( this->m_size == 0 ){        // it's an empty tree
        this->m_root = new Node(key);
        this->auxiliar_node = this->m_root;
        this->m_size++;
        return true;
    } else {
        if( root == nullptr ){
            root = new Node(key);   // links atual node for new-node
            this->m_size++;			// increment the quantity of nodes

            add_son(auxiliar_node, root); // link father & son
	
            if(log)
            {
                std::cout << "STATUS: ";
                std::cout << "Node added! Info:" << std::endl;
                std::cout << "\tFather: " << root->f << std::endl;
                std::cout << "\tLeft son: " << root->l << std::endl;
                std::cout << "\tRight son: " << root->r << std::endl;
            }
			update(root, code_t::INSERT);
            return true;
            
        } else if ( root->key < key ){
            this->auxiliar_node = root;
            return insert( root->r, key);  // key is bigger than

        } else if ( root->key > key ){
            this->auxiliar_node = root;
            return insert( root->l, key);  // key is smaller than

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
/*}}}*/

template< typename T >
void bst<T>::exclude( Node*& root, key_type key ){
/*{{{*/
    // find the node that has the key
    Node *key_holder = root;    // initial key_holder

    while( key_holder != nullptr && key_holder->key != key ){
        if( key_holder->key < key ){
            key_holder = key_holder->r;
        } else if ( key_holder->key > key ){
            key_holder = key_holder->l;
        } else {
            std::cerr << "ERROR[22]: Not predicted (on iteractive remove)\n";
        }
    }

    if( key_holder == nullptr ){
        std::cerr << "ERROR[15]: Key not found! Not removing" << std::endl;
        return;
    }

    if( key_holder->l == nullptr && key_holder->r == nullptr ){
        // just remove-it
        Node * father = key_holder->f;

        // this if-else is to remove the link from father->son
        if( father != nullptr && father->r == key_holder ){
            // it's the right son!
            father->r = nullptr;    // remove link from father
        } else if( father != nullptr && father->l == key_holder ){
            // it's the left son!
            father->l = nullptr;    // remove link from father
        } else if( father == nullptr ){
            // no nothing (it's already the root)
        } else {
            std::cerr << "ERROR[05]: Not predicted this one! Please report!\n";
            return;
        }

        // now, let's remove the son!
        update(key_holder, REMOVE);
        delete key_holder;
        this->m_size--;
    }
    else if( (key_holder->l == nullptr) ^ (key_holder->r == nullptr) ){
        // either r or l are null, not both
        if( key_holder->l == nullptr ){
            // right node will substitute his father
            key_holder->key = key_holder->r->key;
            Node * to_be_deleted = key_holder->r;

            // simple mapping
            Node * right_son = key_holder->r->r;
            Node * left_son = key_holder->r->l;

            // link the key_holder as father for both son's 
            set_father(key_holder, left_son, right_son);

            // now make both son's of father (key_holder)
            key_holder->r = right_son;
            key_holder->l = left_son;

            delete to_be_deleted;
            this->m_size--;
            update(key_holder, REMOVE);
        } else {
            // left node will substitute his father 
            key_holder->key = key_holder->l->key;
            Node * to_be_deleted = key_holder->l;

            // simple mapping
            Node * right_son = key_holder->l->r;
            Node * left_son = key_holder->l->l;

            // link the key_holder as father for both son's
            set_father(key_holder, left_son, right_son);

            // now make both son's of father (key_holder)
            key_holder->r = right_son;
            key_holder->l = left_son;

            delete to_be_deleted;
            this->m_size--;
            update(key_holder, REMOVE);
        }
    } else {
        // the node we want to remove has both sons
        // find predecessor
        Node * pred = find_pred(key_holder);

        // change current node with predecessor
        key_holder->key = pred->key;

        // remove predecessor
        Node * father_pred = pred->f;

        update(pred, REMOVE);
        if( father_pred->r == pred ){
            // pred is the right son of father_pred
            father_pred->r = nullptr;
            delete pred;
        } else if ( father_pred->l == pred ){
            // pred is the left son of father_pred
            father_pred->l = nullptr;
            delete pred;
        }
        this->m_size--;
    }
}
/*}}}*/

template< typename T >
key_type bst<T>::i_nth( size_t n, Node* root )
/*{{{*/
{
	/* Based on in-order path, we are able to use
	   this idea of left and right Nodes amount.
	 */
	if( root == nullptr or this->m_size == 0) return -1;
	size_t nth = root->sub_l + 1;

	if( nth > n) return i_nth(n, root->l);
	else if( nth < n ) return i_nth(n-nth, root->r);

	return root->key;
}
/*}}}*/

//!< Returns position occupied by value, with in-order path.
template< typename T >
int bst<T>::i_pos( key_type key, Node* root, size_t pos )
/*{{{*/
{
	if( root == nullptr ) return -1;
	int current = pos + root->sub_l + 1;

	if( key < root->key) return i_pos(key, root->l, pos);
	else if( key > root->key ) return i_pos(key, root->r, current);

	return current;
}
/*}}}*/
/*}}}*/
