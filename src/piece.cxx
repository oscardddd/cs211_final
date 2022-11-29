/*******************************************/
/*** DO NOT CHANGE ANYTHING IN THIS FILE ***/
/*******************************************/

#include "piece.hxx"

Player
other_player(Player player)
{
    switch (player) {
    case Player::black:
        return Player::red;
    case Player::red:
        return Player::black;
    default:
        return player;
    }
}

//constructor
Piece::Piece(std::string type, Piece::Position pos, Player side)
    :
    type(type),
    pos(pos),
    side(side)
{}


Piece::Position
Piece::piece_pos() {
    return pos;
}

Player
Piece::cur_side()
{
    return side;
}

std::string
Piece:: cur_type()
{
    return type;
}

// std::ostream&
// operator<<(std::ostream& os, Player p)
// {
//     switch (p) {
//     case Player::red:
//         return os << "L";
//     case Player::black:
//         return os << "D";
//     default:
//         return os << "_";
//     }
// }

