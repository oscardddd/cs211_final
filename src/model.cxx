#include "model.hxx"

void
Model::set_first_click(Model::Position pos)
{
    if (turn_ == Player::black && board[pos] / 10 == 1) {
        Model::first_click = Model::board[pos];
        click_pos = pos;
    }

    if (turn_ == Player::red && board[pos] / 10 == 0) {
        Model::first_click = Model::board[pos];
        click_pos = pos;
    }
}

// return the possible moves gained by moving at click_pos
Position_set
Model::find_moves()
{
    res.clear();
    // red soldier兵
    if (first_click == 1) {
        if (click_pos.y <= 4) {
            check_red({click_pos.x + 1, click_pos.y});
            check_red({click_pos.x - 1, click_pos.y});
        }
        check_red({click_pos.x, click_pos.y - 1});

        return res;
    }

        // black soldier兵
    else if (first_click == 11) {
        if (click_pos.y >= 5) {
            check_black({click_pos.x + 1, click_pos.y});
            check_black({click_pos.x - 1, click_pos.y});
        }
        check_black({click_pos.x, click_pos.y + 1});

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
        //check up
        vertical_check(Player::red,click_pos);
        horizontal_check(Player::red,click_pos);
        return res;
    }
        // black car
    else if (first_click == 13) {

    } else if (first_click == 4) {

    }
    return res;
}

void
Model::play_move(Model::Position)
{

}


bool
Model::check_red(Position pos)
{
    return (board[pos] != 0);

}

bool
Model::check_black(Position pos)
{
    if (board[pos] / 10 != 1) {
        res[pos] = true;
    }
    return (board[pos] / 10 == 1);
}


//check vertically to find out the possible moves (for car and cannon)
void
Model::vertical_check(Player side, Position pos)
{
    if (side == Player::black) {
        for (int i = 1; pos.y + i < 10; i++) {
            if (check_black({pos.x, pos.y + i})) {
                break;
            }
            if (board[{pos.x, pos.y + i}] / 10 == 0) {
                res[{pos.x, pos.y + i}] = true;
                break;
            }
        }
        for (int i = 1; pos.y - i >= 0; i--) {
            if (check_black({pos.x, pos.y - i})) {
                break;
            }
            if (board[{pos.x, pos.y - i}] / 10 == 0) {
                res[{pos.x, pos.y - i}] = true;
                break;
            }
        }
    } else if (side == Player::red) {
        for (int i = 1; pos.y + i < 10; i++) {
            if (check_red({pos.x, pos.y + i})) {

                break;
            }
            if (board[{pos.x, pos.y + i}] / 10 == 1) {
                res[{pos.x, pos.y + i}] = true;
                break;
            }
        }
        for (int i = 1; pos.y - i >= 0; i--) {
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
Model::horizontal_check(Player side, Position pos)
{
    if (side == Player::black) {
        //check move right
        for (int i = 1; pos.x + i < 9; i++) {
            if (check_black({pos.x + i, pos.y})) {
                break;
            }
            if (board[{pos.x + i, pos.y}] / 10 == 0) {
                res[{pos.x + i, pos.y}] = true;
                break;
            }
        }
        //check move left
        for (int i = 1; pos.x - i >= 0; i--) {
            if (check_black({pos.x - i, pos.y})) {
                break;
            }
            if (board[{pos.x - i, pos.y}] / 10 == 0) {
                res[{pos.x - i, pos.y}] = true;
                break;
            }
        }
    } else if (side == Player::red) {
        //check move right
        for (int i = 1; pos.x + i < 9; i++) {
            if (check_red({pos.x + i, pos.y})) {
                break;
            }
            if (board[{pos.x + i, pos.y}] / 10 == 1) {
                res[{pos.x + i, pos.y}] = true;
                break;
            }
        }
        //check move left
        for (int i = 1; pos.x - i >= 0; i--) {
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
