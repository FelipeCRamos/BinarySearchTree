#include <iostream>
#include <fstream>
#include <vector>

#include "bst.h"
#include "parser.h"

enum func_code{
    nth,
    pos,
    median,
    isfull,
    iscomp,
    print,
    remov,
    insert
};

func_code hashit( std::string const &str_c ){
    if( str_c == "ENESIMO" ) return nth;
    if( str_c == "POSICAO" ) return pos;
    if( str_c == "MEDIANA" ) return median;
    if( str_c == "CHEIA" ) return isfull;
    if( str_c == "COMPLETA" ) return iscomp;
    if( str_c == "IMPRIMA" ) return print;
    if( str_c == "REMOVA" ) return remov;
    if( str_c == "INSIRA" ) return insert;
}

int main( int argc, char **argv )
{
    std::string tree_filename;
    std::string comm_filename;
    // Args treating
    if( argc > 2 ){
        tree_filename = argv[1];
        comm_filename = argv[2];

    } else {
        std::cerr << "ERROR[03]: Number of arguments is incorrect, "
            << "please read the documentation!\n";
        return 1;
    }

    std::ifstream tree_file( tree_filename );
    std::ifstream comm_file( comm_filename );

    std::vector<int> values = parse_from(tree_file);
    std::cout << "Values from " << tree_filename << " parsed.\n";
    std::vector<std::pair<std::string, int> > commands = parse_commands(comm_file);
    std::cout << "Commands from " << comm_filename << " parsed.\n";

    tree_file.close();
    comm_file.close();

	bst<int> tree;
    std::cout << "-> Tree declared successfully\n";

    std::cout << "Add: ";
    for( auto &i : values ){
        tree.add(i);
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    std::cout << "Tree by level: ";
    std::cout << "[ " << tree.toString() << "]" << std::endl;

    for( auto &i : commands ){
        std::cout << "command: [" << i.first << "], arg: [" << i.second << "]" << std::endl;
        switch(hashit(i.first)){
            case nth:
                // not working yet
                // tree.nthElement( i.second );    // example
                break;
            case pos:
                // function to be called
                break;
            case median:
                // function to be called
                break;
            case isfull:
                // function to be called
                break;
            case iscomp:
                // function to be called
                break;
            case print:
                // function to be called
                std::cout << tree.toString() << std::endl;
                break;
            case remov:
                // function to be called
                break;
            case insert:
                tree.add( i.second );
                break;
            default:
                std::cout << "Sorry, any matched!\n";
        }
    }


    

	return 0;
}
