#include <cassert>
#include "bst.h"
#include "parser.h"

#define debug false

//!< Some function codes to feed the switch() statement
namespace function{
    enum code{
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
};

//!< Convert the string function to a func_code
function::code hashit( std::string const &str_c ){
    if( str_c == "ENESIMO" )    return function::nth;
    if( str_c == "POSICAO" )    return function::pos;
    if( str_c == "MEDIANA" )    return function::median;
    if( str_c == "CHEIA" )      return function::isfull;
    if( str_c == "COMPLETA" )   return function::iscomp;
    if( str_c == "IMPRIMA" )    return function::print;
    if( str_c == "REMOVA" )     return function::remov;
    if( str_c == "INSIRA" )     return function::insert;

    return function::none;    // none matched, probably a invalid command
}

int main( int argc, char **argv )
{
    std::string tree_filename;  //!< Path to the tree file
    std::string comm_filename;  //!< Path to the commands file
    
    // Check if the arg's are O.K.!
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

    // Parse tree file and store on std::vector<int> values
    std::vector< int > values = parse_from( tree_file );
    if(debug) std::cout << ">>> Values from " << tree_filename << " parsed.\n";

    // Parse commands file and store on a vector of pairs <std::string, int>
    std::vector< std::pair< std::string, int > > commands = parse_commands( comm_file );
    if(debug) std::cout << ">>> Commands from " << comm_filename << " parsed.\n";

    // Close file streams
    tree_file.close();
    comm_file.close();

	bst<int> tree;
    if(debug) std::cout << ">>> Tree declared successfully!\n";

    // populating values to tree
    for( auto &i : values ){
        tree.add(i);
    }

    std::cout << "Tree populated! print by level: ";
    std::cout << "[ " << tree.toString() << "]" << std::endl;

	std::cout << "\n\033[1;32mStarting operations!\033[0m\n";
    std::cout << "----------------------------------------------\n";

    for( auto &i : commands ){
        if(debug) std::cout << "command: [" << i.first 
            << "], arg: [" << i.second << "]" << std::endl;

        switch(hashit(i.first)){
            case function::nth:
                std::cout << "NthElement: " << tree.nthElement( i.second ) << "\n";
                break;
            case function::pos:
                std::cout << "Position: " << tree.position( i.second ) << "\n";
                break;
            case function::median:
                std::cout << "Median element: " << tree.median() << std::endl;
                break;
            case function::isfull:
                if( tree.isFull() )
				{
					std::cout << "Tree is Full?: True\n"; 
				} else {
					std::cout << "Tree is Full?: False\n";
				}
                break;
            case function::iscomp:
				if( tree.isComplete() )
				{
					std::cout << "Tree is Complete?: True\n";
				} else {
					std::cout << "Tree is Complete?: False\n";
				}
                break;
            case function::print:
                std::cout << "Current tree by level: " 
                    << tree.toString() << std::endl;
                break;
            case function::remov:
                std::cout << "Removing " << i.second << std::endl;
                tree.remove( i.second );
                break;
            case function::insert:
                std::cout << "Inserting " << i.second << std::endl;
                tree.add( i.second );
                break;
            case function::none:
                std::cout << "Sorry, command " << i.first
						  << " isn't known!\n Try a valid command.\n";
                return 1;
        }
    }

    std::cout << "----------------------------------------------\n";
	std::cout << "\033[1;32mOperations finished successfully!\033[0m\n\n";

	return 0;
}
