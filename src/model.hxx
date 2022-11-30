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
    Position click_pos = {0, 0};
    // 0 indicates we are currently clicks



    int second_click;
    Position second_pos = {0, 0};

    Board board;

    //the empty position set used to store the possibles moves after
    // the click
    Position_set res;


    //helper function
    //check the position and add it into res if it is not red
    bool check_red(Position);

    // same but black
    bool check_black(Position);

    bool good_position(Position);
    void vertical_check(Player,Position);

    void horizontal_check(Player,Position);
    void cannon_check_horizontally(Player);
    void cannon_check_vertically(Player);

    //if the game ends, set winner and return true.
    bool set_winner();
    void advance_turn();
    void really_play_move();



public:
    Model();
    void set_first_click(Position);

    void set_second_click(Position);

    Position_set find_moves();

    bool check_click();

    void play_move(Position);





};




