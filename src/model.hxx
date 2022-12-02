#pragma once
#include "piece.hxx"


// red side: 1 is 兵, 2 is 炮, 3 is 车, 4 is 马, 5 is 相, 6 is 士, 7 is 帅
// black side: 11 is 兵, 12 is 炮, 13 is 车, 14 is 马, 15 is 相, 16 is 士, 17 is 帅

#include <ge211.hxx>
#include "board.hxx"

class Model
{
public:
    using Position = ge211::Posn<int>;

protected:
    int first_click;
    Position click_pos = {0, 0};


private:
    Player winner_ = Player::neither;
    // the piece user selects

    //the position the user selects
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




public:
    Model();
    void set_pos(Position, int);
    Player turn_ = Player::red;

    int operator[](Position) const;

    Position_set find_moves();

    void play_move(Position);

    bool is_game_over();
    Player get_winner();






};




