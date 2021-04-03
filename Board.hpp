/**
 * Author: Mayan Bashan
 */

#pragma once
#include <string>
#include <map>

using namespace std;
#include "Direction.hpp"

namespace ariel{
    
    class Board{
        std::map<unsigned int, std::map<unsigned int, char> > board_map; //left int refers to rows, right int refers to columns
        unsigned int max_row = 0;
        unsigned int max_col = 0;
        public:
            void post(const unsigned int row, const unsigned int col, ariel::Direction dir, const string &str);
            string read(const unsigned int row, const unsigned int col,ariel::Direction dir, const unsigned int len);
            void show();
    };
}