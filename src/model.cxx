#include "model.hxx"

Model::Model():
    first_click(-1),
    second_click(-1),
    board()
{}


int
Model::operator[](Position pos) const
{
    return board[pos];
}


// return the possible moves gained by moving at click_pos
Position_set
Model::find_moves()
{
    res.clear();
    // red soldier兵
    if (first_click == 1) {

        if (click_pos.x <= 4) {
            check_red({click_pos.x, click_pos.y + 1});
            check_red({click_pos.x, click_pos.y - 1});
        }
        // check_red({click_pos.x - 1, click_pos.y});
        if(good_position({click_pos.x - 1, click_pos.y})){
            {
                check_red({click_pos.x - 1, click_pos.y});

            }

        }


    }

    // black soldier兵
    else if (first_click == 11) {
        if (click_pos.x >= 5) {
            check_black({click_pos.x, click_pos.y + 1});
            check_black({click_pos.x, click_pos.y - 1});
        }
        check_black({click_pos.x + 1, click_pos.y});
    }

    // red cannon
    else if (first_click == 2) {
        cannon_check_horizontally(Player::red);
        cannon_check_vertically(Player::red);
    }
    // black cannon
    else if (first_click == 12) {
        cannon_check_horizontally(Player::black);
        cannon_check_vertically(Player::black);
    }
    //red car
    else if (first_click == 3) {
        //check up
        vertical_check(Player::red,click_pos);
        horizontal_check(Player::red,click_pos);
    }
    // black car
    else if (first_click == 13) {
        vertical_check(Player::black,click_pos);
        horizontal_check(Player::black,click_pos);
    }

    // red horse马
    else if (first_click == 4) {
        // check if there is any limitation of the eight potential moves
        if (good_position({click_pos.x, click_pos.y +1 }) &&
        board[{click_pos.x,click_pos.y + 1}] == -10) {
            check_red({click_pos.x - 1, click_pos.y + 2});
            check_red({click_pos.x + 1, click_pos.y + 2});
        }

        if (good_position({click_pos.x, click_pos.y - 1})
        && board[{click_pos.x, click_pos.y - 1}] == -10) {
            check_red({click_pos.x + 1, click_pos.y - 2});
            check_red({click_pos.x - 1, click_pos.y - 2});
        }
        if (good_position({click_pos.x-1, click_pos.y})
        && board[{click_pos.x - 1, click_pos.y}] == -10) {
            check_red({click_pos.x - 2, click_pos.y + 1});
            check_red({click_pos.x - 2, click_pos.y - 1});
        }
        if (good_position({click_pos.x+1, click_pos.y})
        && board[{click_pos.x + 1, click_pos.y}] == -10) {
            check_red({click_pos.x + 2, click_pos.y + 1});
            check_red({click_pos.x + 2, click_pos.y - 1});
        }
    }

    // black horse马
    else if (first_click == 14) {
        // check if there is any limitation of the eight potential moves
        if (good_position({click_pos.x, click_pos.y + 1}) &&
        board[{click_pos.x, click_pos.y + 1}] == -10) {
            check_black({click_pos.x - 1, click_pos.y + 2});
            check_black({click_pos.x + 1, click_pos.y + 2});
        }
        if (good_position({click_pos.x, click_pos.y - 1}) &&
        board[{click_pos.x, click_pos.y - 1}] == -10) {
            check_black({click_pos.x + 1, click_pos.y - 2});
            check_black({click_pos.x - 1, click_pos.y - 2});
        }
        if (good_position({click_pos.x - 1, click_pos.y}) &&
        board[{click_pos.x - 1, click_pos.y}] == -10) {
            check_black({click_pos.x - 2, click_pos.y + 1});
            check_black({click_pos.x - 2, click_pos.y - 1});
        }
        if (good_position({click_pos.x + 1, click_pos.y}) &&
        board[{click_pos.x + 1, click_pos.y}] == -10) {
            check_black({click_pos.x + 2, click_pos.y + 1});
            check_black({click_pos.x + 2, click_pos.y - 1});
        }
    }

    // black elephant象
    else if (first_click == 15)
    {
        // see if the elephant crosses the river
        if (click_pos.x + 2 <= 4) {
            if (good_position({click_pos.x - 1, click_pos.y - 1}) &&
                board[{click_pos.x - 1, click_pos.y - 1}] == -10) {
                check_black({click_pos.x - 2, click_pos.y - 2});
            }
            if (good_position({click_pos.x - 1, click_pos.y + 1}) &&
                board[{click_pos.x - 1, click_pos.y + 1}] == -10) {
                check_black({click_pos.x - 2, click_pos.y + 2});
            }

            if (good_position({click_pos.x + 1, click_pos.y - 1}) &&
                board[{click_pos.x + 1, click_pos.y - 1}] == -10) {
                check_black({click_pos.x + 2, click_pos.y - 2});
            }
            if (good_position({click_pos.x + 1, click_pos.y + 1}) &&
                board[{click_pos.x + 1, click_pos.y + 1}] == -10) {
                check_black({click_pos.x + 2, click_pos.y + 2});
            }

        }
        else
        {
            if (good_position({click_pos.x - 1, click_pos.y - 1}) &&
                board[{click_pos.x - 1, click_pos.y - 1}] == -10) {
                check_black({click_pos.x - 2, click_pos.y - 2});
            }
            if (good_position({click_pos.x - 1, click_pos.y + 1}) &&
                board[{click_pos.x - 1, click_pos.y + 1}] == -10) {
                check_black({click_pos.x - 2, click_pos.y + 2});
            }
        }
    }

    //red elephant象
    else if (first_click == 5) {
        // see if the elephant crosses the river
        if (click_pos.x - 2 >= 5) {
            if (good_position({click_pos.x - 1, click_pos.y - 1}) &&
                board[{click_pos.x - 1, click_pos.y - 1}] == -10) {
                check_red({click_pos.x - 2, click_pos.y - 2});
            }
            if (good_position({click_pos.x - 1, click_pos.y + 1}) &&
                board[{click_pos.x - 1, click_pos.y + 1}] == -10) {
                check_red({click_pos.x - 2, click_pos.y + 2});
            }
            if (good_position({click_pos.x + 1, click_pos.y - 1}) &&
                board[{click_pos.x + 1, click_pos.y - 1}] == -10) {
                check_red({click_pos.x + 2, click_pos.y - 2});
            }
            if (good_position({click_pos.x + 1, click_pos.y + 1}) &&
                board[{click_pos.x + 1, click_pos.y + 1}] == -10) {
                check_red({click_pos.x + 2, click_pos.y + 2});
            }
        }
        else{
            if (good_position({click_pos.x + 1, click_pos.y - 1}) &&
                board[{click_pos.x + 1, click_pos.y - 1}] == -10) {
                check_red({click_pos.x + 2, click_pos.y - 2});
            }
            if (good_position({click_pos.x + 1, click_pos.y + 1}) &&
                board[{click_pos.x + 1, click_pos.y + 1}] == -10) {
                check_red({click_pos.x + 2, click_pos.y + 2});
            }
        }
    }

    // red advisor士
    else if (first_click == 6) {
        // check if the general is in 宫 before check if anything is on the way
        if ((click_pos.y - 1 >= 3) && (click_pos.x - 1 >= 7)) {
            check_red({click_pos.x - 1, click_pos.y - 1});
        }
        if ((click_pos.y - 1 >= 3) && (click_pos.x + 1 <= 9)) {
            check_red({click_pos.x + 1, click_pos.y - 1});
        }
        if ((click_pos.y + 1 <= 5) && (click_pos.x - 1 >= 7)) {
            check_red({click_pos.x - 1, click_pos.y + 1});
        }
        if ((click_pos.y + 1 <= 5) && (click_pos.x + 1 <= 9)) {
            check_red({click_pos.x + 1, click_pos.y + 1});
        }
    }

    // black advisor士
    else if (first_click == 16) {
        // check if the general is in 宫 before check if anything is on the way
        if ((click_pos.y - 1 >= 3) && (click_pos.x - 1 >= 0)) {
            check_black({click_pos.x - 1, click_pos.y - 1});
        }
        if ((click_pos.y - 1 >= 3) && (click_pos.x + 1 <= 2)) {
            check_black({click_pos.x + 1, click_pos.y - 1});
        }
        if ((click_pos.y + 1 <= 5) && (click_pos.x - 1 >= 0)) {
            check_black({click_pos.x - 1, click_pos.y + 1});
        }
        if ((click_pos.y + 1 <= 5) && (click_pos.x + 1 <= 2)) {
            check_black({click_pos.x + 1, click_pos.y + 1});
        }
    }

    // red general帅
    else if (first_click == 7) {
        // check if the general is in 宫 before check if anything is on the way
        if (click_pos.y + 1 <= 5) {
            check_red({click_pos.x, click_pos.y + 1});
        }
        if (click_pos.y - 1 >= 3) {
            check_red({click_pos.x, click_pos.y - 1});
        }
        if (click_pos.x + 1 <= 9) {
            check_red({click_pos.x + 1, click_pos.y});
        }
        if (click_pos.x - 1 >= 7) {
            check_red({click_pos.x - 1, click_pos.y});
        }

    }

    // black general将
    else if (first_click == 17) {
        // check if the general is in 宫 before check if anything is on the way
        if (click_pos.y + 1 <= 5) {
            check_black({click_pos.x, click_pos.y + 1});
        }
        if (click_pos.y - 1 >= 3) {
            check_black({click_pos.x, click_pos.y - 1});
        }
        if (click_pos.x + 1 <= 2) {
            check_black({click_pos.x + 1, click_pos.y});
        }
        if (click_pos.x - 1 >= 0) {
            check_black({click_pos.x - 1, click_pos.y});
        }
    }

    return res;
}


//
// HELPER FUNCTION
//
bool Model::good_position(Model::Position pos)
{
    if(pos.x > 9 || pos.x < 0 ||pos.y > 8 || pos.y < 0){
        return false;
    }
    return true;
}

bool
//if the given position does not lies a red piece, make that position true in
// res, return whether or not the position has a red piece.
Model::check_red(Position pos)
{
    if(good_position(pos)){
        if (board[pos] / 10 != 0) {
            res[pos] = true;
        }
        return (board[pos] / 10 == 0);
    }
    return false;
}

bool
Model::check_black(Position pos)
{
    if(good_position(pos)){
        if (board[pos] / 10 != 1) {
            res[pos] = true;
        }
        return (board[pos] / 10 == 1);
    }
    return false;

}

//check vertically to find out the possible moves (for car)
void
Model::horizontal_check(Player side, Position pos)
{
    if (side == Player::black) {
        for (int i = 1; pos.y + i < 9; i++) {
            if (check_black({pos.x, pos.y + i})) {
                break;
            }
            if (board[{pos.x, pos.y + i}] / 10 == 0) {
                res[{pos.x, pos.y + i}] = true;
                break;
            }
        }
        for (int i = 1; pos.y - i >= 0; i++) {
            if (check_black({pos.x, pos.y - i})) {
                break;
            }
            if (board[{pos.x, pos.y - i}] / 10 == 0) {
                res[{pos.x, pos.y - i}] = true;
                break;
            }
        }
    } else if (side == Player::red) {
        for (int i = 1; pos.y + i < 9; i++) {
            if (check_red({pos.x, pos.y + i})) {
                break;
            }
            if (board[{pos.x, pos.y + i}] / 10 == 1) {
                res[{pos.x, pos.y + i}] = true;
                break;
            }
        }
        for (int i = 1; pos.y - i >= 0; i++) {
            if (check_red({pos.x, pos.y - i})) {
                break;
            }
            if (board[{pos.x, pos.y - i}] / 10 == 1) {
                res[{pos.x, pos.y - i}] = true;
                break;
            }
        }
    }
}


void
Model::vertical_check(Player side, Position pos)
{
    if (side == Player::black) {
        //check move right
        for (int i = 1; pos.x + i < 10; i++) {
            if (check_black({pos.x + i, pos.y})) {
                break;
            }
            if (board[{pos.x + i, pos.y}] / 10 == 0) {
                res[{pos.x + i, pos.y}] = true;
                break;
            }
        }
        //check move upward
        for (int i = 1; pos.x - i >= 0; i++) {
            if (check_black({pos.x - i, pos.y})) {
                break;
            }
            if (board[{pos.x - i, pos.y}] / 10 == 0) {
                res[{pos.x - i, pos.y}] = true;
                break;
            }
        }
    }
    else if (side == Player::red) {
        //check move right
        for (int i = 1; pos.x + i < 10; i++) {
            if (check_red({pos.x + i, pos.y})) {
                break;
            }
            if (board[{pos.x + i, pos.y}] / 10 == 1) {
                res[{pos.x + i, pos.y}] = true;
                break;
            }
        }
        //check move left
        for (int i = 1; pos.x - i >= 0; i++) {
            if (check_red({pos.x - i, pos.y})) {
                break;
            }
            if (board[{pos.x - i, pos.y}] / 10 == 1) {
                res[{pos.x - i, pos.y}] = true;
                break;
            }
        }
    }
}

// check possible moves of a cannon horizontally

void Model::cannon_check_horizontally(Player side)
{
    int same_side = 20;

    if (side == Player::red){
        same_side = 0;
    }
    else if (side == Player::black){
        same_side = 1;}

    int mark = 20;
    int mark_two = -20;

    //check rightward
    for (int i = 1; click_pos.y + i < 9; i++) {
        if (board[{click_pos.x, click_pos.y + i}] == -10) {
            res[{click_pos.x,click_pos.y + i}] = true;
        }
        else {
            mark = click_pos.y + i;
            break;
        }
    }
    for (int m = mark + 1; m < 9; m++){
        if (board[{click_pos.x, m}]/ 10 == same_side){
            break;
        }
        else if (board[{click_pos.x, m}]/ 10 == 1 - same_side){
            res[{click_pos.x,m}] = true;
            break;
        }
    }


    //check leftward
    for (int i = 1; click_pos.y - i >= 0; i++) {

        if (board[{click_pos.x,click_pos.y -i}] == -10) {
            res[{click_pos.x,click_pos.y-i}] = true;
        }
        else{
            mark_two = click_pos.y-i;
            break;
        }
    }
    for(int m = mark_two -1;m >= 0; m--){
        if(board[{click_pos.x, m}] / 10 == same_side){
            break;
        }
        else if(board[{click_pos.x, m}] / 10 == 1 - same_side){
            res[{click_pos.x,m}] = true;
            break;
        }
    }
}



void Model::cannon_check_vertically(Player side)
{
    int same_side = 20;

    if (side == Player::red){
        same_side = 0;
    }
    else if (side == Player::black){
        same_side = 1;}

    int mark = 20;


    //check downward
    for (int j = 1; click_pos.x + j < 10; j++) {
        if (board[{click_pos.x + j, click_pos.y}] == -10) {
            res[{click_pos.x + j, click_pos.y}] = true;
        }
        else {
            mark = click_pos.x + j;
            break;
        }
    }
    //downward checks
    for (int m = mark+1; m < 10; m++){
        if (board[{m, click_pos.y}]/ 10 == same_side){
            break;
        }
        else if (board[{m, click_pos.y}]/ 10 == 1 - same_side){
            res[{m, click_pos.y}] = true;
            break;
        }
    }


    //上面的炮架
    int mark_two = -20;

    //check upward
    for (int j = 1; click_pos.x - j >= 0; j++) {

        if (board[{click_pos.x - j, click_pos.y}]== -10) {
            res[{click_pos.x - j,click_pos.y}] = true;
        }
        else{
            mark_two = click_pos.x - j;
            break;
        }
    }

    for(int m = mark_two -1; m >= 0; m--){
        if(board[{m, click_pos.y}] / 10 == same_side){
            break;
        }
        else if(board[{m, click_pos.y}] / 10 == 1 - same_side){
            res[{m, click_pos.y}] = true;
            break;
        }
    }
}

void
Model::play_move(Model::Position pos)
{
        if (((turn_ == Player::red && board[{pos.y,pos.x}]/10 == 0)||
        (turn_==Player::black && board[{pos.y,pos.x}]/10 == 1)))
        {
            click_pos = {pos.y, pos.x};
            first_click = board[click_pos];
            find_moves();
        } else if (find_moves()[{pos.y, pos.x}]) {
            // std::cout << "second click: " << std::endl;
            second_pos = {pos.y, pos.x};
            second_click = board[second_pos];

            board.set(second_pos, first_click);
            board.erase(click_pos);
            first_click = -1;
            if(!set_winner()){
                advance_turn();
            }

        }
}


bool Model::set_winner()
{
    if(second_click == 7){
        winner_ = Player::black;
        turn_ = Player::neither;
        return true;
    }
    else if (second_click == 17){
        winner_ = Player::red;
        turn_ = Player::neither;
        return true;
    }
    return false;
}

void Model::advance_turn()
{
    turn_ = other_player(turn_);

}



bool Model::is_game_over()
{
    if(winner_!=Player::neither){
        return true;
    }
    return false;
}
Player Model::get_winner(){
    return winner_;
}

void Model::set_pos(Model::Position pos,int piece)
{
    board.set(pos,piece);
}

