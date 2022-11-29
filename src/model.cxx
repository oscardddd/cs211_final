#include "model.hxx"

void
Model::set_first_click(Model::Position pos)
{
    if(turn_ == Player::black && board[pos]/10 == 1){
        Model::first_click = Model::board[pos];
        click_pos = pos;
    }

    if(turn_ == Player::red && board[pos]/10 == 0){
        Model::first_click = Model::board[pos];
        click_pos = pos;
    }
}

Position_set
Model:: find_moves()
{
    Position_set res;

    // red soldier兵
    if(first_click == 1){
        if(click_pos.y <= 4){
            res[{click_pos.x+1,click_pos.y}] = true;
            res[{click_pos.x-1,click_pos.y}] = true;
        }
        res[{click_pos.x,click_pos.y-1}] = true;
        return res;
    }

    // black soldier兵
    else if(first_click == 11){
        if(click_pos.x >= 5){
            res[{click_pos.x+1,click_pos.y}] = true;
            res[{click_pos.x-1,click_pos.y}] = true;
        }
        res[{click_pos.x,click_pos.y+1}] = true;
        return res;
    }
    // red cannon
    else if (first_click == 2) {

    }
    // black cannon
    else if (first_click == 12) {

    }
    //red car
    else if (first_click == 3) {

    }
    // black car
    else if (first_click == 13) {

    }
    else if (first_click == 4) {

    }
}

void
Model::play_move(Model::Position)
{

}

// helper function

// if there is no chess, then the 
bool
Model::check_blocked(Position pos)
{
    return (board[pos] != 0);

}
