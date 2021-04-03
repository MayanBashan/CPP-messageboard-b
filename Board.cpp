/**
 * Author: Mayan Bashan
 */

#include "Board.hpp"
#include "Direction.hpp"
#include <iostream>
#include <string>
#include <map>
using namespace std;


namespace ariel{

    void ariel::Board::post(const unsigned int row, const unsigned int col, const ariel::Direction dir, const string &str){
        unsigned int str_len = str.length();
        unsigned int row_ind = row;
        unsigned int col_ind = col;
        unsigned int index = 0;

        if (dir == Direction::Horizontal){ // Horizontal - from left to right
            while(str_len != 0){
                board_map[row_ind][col_ind] = str[index];
                col_ind++;
                index++;
                str_len--;
            }
        }

        else{ //Vertical - from top to bottom
            while(str_len != 0){
                board_map[row_ind][col_ind] = str[index];
                    row_ind++;
                    index++;
                    str_len--;
            }
        }
        if (row_ind > max_row){
            max_row = row_ind;
        }
        if (col_ind > max_col){
            max_col = col_ind;
        }
    }

    string ariel::Board::read(const unsigned int row, const unsigned int col, const ariel::Direction dir, const unsigned int len){
        string ans;
        unsigned int row_ind = row;
        unsigned int col_ind = col;
        unsigned int length = len;
        int flag = 0;

        if (dir == Direction::Horizontal){ // Horizontal - from left to right
            while(length != 0){
                flag = 0;
                if(board_map.count(row_ind) != 0){
                    if (board_map[row_ind].count(col_ind) != 0){
                        flag = 1;
                        ans += board_map[row_ind][col_ind];
                    }
                }
                if (flag == 0){
                    ans += "_";
                }
                col_ind++;
                length--;
            }
        }

        else{ //Vertical - from top to bottom
            while(length != 0){
                flag = 0;
                if(board_map.count(row_ind) != 0){
                    if (board_map[row_ind].count(col_ind) != 0){
                        flag = 1;
                        ans += board_map[row_ind][col_ind];
                    }
                }
                if (flag == 0){
                    ans += "_";
                }
                row_ind++;
                length--;
            }
        }
        return ans;
    }

    void ariel::Board::show(){
       unsigned int len = max_col + 1;
       for(unsigned int i=0; i<=max_row; i++){
           cout << read(i,0,Direction::Horizontal, len);
           cout << "\n";
       }
    }
}



    
