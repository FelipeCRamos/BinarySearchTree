#include "parser.h"

std::vector< int > parse_from( std::ifstream &ifs ){
    std::vector< int > values_list;
    std::string acc;
    while( ifs.good() ){
        char c = (char)ifs.get();
        if(c != ' ' and c != '\0' and c != '\n'){
            acc += c;
        } else {
            // std::cout << "num: " << acc << std::endl;
            values_list.push_back( stoi(acc) );
            acc = "";
        }
        // values_list.push_back(stoi(acc));
    }
    return values_list;
}

std::vector<std::pair<std::string, int> > parse_commands( std::ifstream &ifs ){
    std::vector< std::pair< std::string, int > > v; 
    std::string buf;
    std::string word;
    std::string number;

    while( ifs.good() ){
        std::getline(ifs, buf);

        // Begin to proccess line
        bool word_complete = false;
        if( !buf.empty() ){
            // std::cout << "buffer: " << buf << " - " << buf.empty() <<std::endl;
            for( auto &i : buf ){
                if( i == ' ' ){
                    word_complete = true; 
                } else {
                    if( !word_complete ){
                        word += i;
                    } else {
                        number += i; 
                    }
                }
            }
            int n;
            try{
                n = stoi(number);
            } catch( const std::invalid_argument &ia ){
                n = 0; 
            }

            v.push_back( std::make_pair(word, n) );
        }

        // reset the buffers
        buf = "";       
        word = "";
        number = "";
    }
    return v;
}
