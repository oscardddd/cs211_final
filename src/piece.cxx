/*******************************************/
/*** DO NOT CHANGE ANYTHING IN THIS FILE ***/
/*******************************************/

#include "piece.hxx"

Player
other_player(Player player)
{
    // switch (player) {
    // case Player::black:
    //     return Player::red;
    // case Player::red:
    //     return Player::black;
    // default:
    //     return player;
    // }
    if(player == Player::red){
        return Player::black;
    }
    else if(player == Player::black){
        return Player::red;
    }
    else{
        return Player::neither;
    }
}
std::ostream&
operator<<(std::ostream& os, Player p)
{
    switch (p) {
    case Player::red:
        return os << "R";
    case Player::black:
        return os << "B";
    default:
        return os << "_";
    }
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

