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
    insert,
    none
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

    return none;    // none matched
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

    std::vector< int > values = parse_from( tree_file );
    std::cout << "Values from " << tree_filename << " parsed.\n";
    std::vector< std::pair< std::string, int > > commands = parse_commands( comm_file );
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
				tree.position( i.second );
                break;
            case median:
                std::cout << "Median element: " << tree.median() << std::endl;
                break;
            case isfull:
                // function to be called
                break;
            case iscomp:
                // function to be called
                break;
            case print:
                std::cout << "Current tree by level: " 
                    << tree.toString() << std::endl;
                break;
            case remov:
                std::cout << "Removing " << i.second << std::endl;
                tree.remove( i.second );
                break;
            case insert:
                std::cout << "Inserting " << i.second << std::endl;
                tree.add( i.second );
                break;
            case none:
                std::cout << "Sorry, command " << i.first
						  << " isn't known!\n Try a valid command.\n";
        }
    }

	std::cout << "\n\033[1;32mOperations finished successfully!\033[0m\n";

    std::cout << tree.toString() << std::endl;

    // temporary tests
    int vec[] = { 10, 5, 12, 3, 9, 11, 27 };
    for( auto &i : vec ){
        std::cout << "\n~ Removing " << i << std::endl;
        tree.remove(i);
        std::cout << "Result tree: " << tree.toString() << std::endl;
        std::cout << "Posicao de 27 = " << tree.position(27) << std::endl;

    }

	return 0;
}
