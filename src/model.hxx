#pragma once
#include "piece.hxx"


// red side: 1 is 兵, 2 is 炮, 3 is 车, 4 is 马, 5 is 相, 6 is 士, 7 is 帅
// black side: 11 is 兵, 12 is 炮, 13 is 车, 14 is 马, 15 is 相, 16 is 士, 17 is 帅

#include <ge211.hxx>
#include "board.hxx"

class Model
{
    using Position = ge211::Posn<int>;

private:
    Player turn_ = Player::red;
    Player winner_ = Player::neither;
    // the piece user selects
    int first_click;
    //the position the user selects
    Position click_pos;


    Position second_click;
    Board board;

    //the empty position set used to store the possibles moves after
    // the click
    Position_set res;


    //helper function
    bool check_blocked(Position);


public:
    Model();
    void set_first_click(Position);
    Position_set find_moves();

    void play_move(Position);




    Position_set horizontal_and_vertical();
};




