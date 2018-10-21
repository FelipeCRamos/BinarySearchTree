#include "bst.h"

int main( int argc, char **argv )
{
	bst<int> arvore;
    std::cout << "-> Tree declared successfully\n";

    arvore.add(10);
    arvore.add(12);
    arvore.add(9);
    arvore.add(7);
    arvore.add(11);
    arvore.add(21);

    std::cout << "tree print:\n";
    std::string print_arv = arvore.toString();

    std::cout << "[ " << print_arv << "]" << std::endl;

	return 0;
}
