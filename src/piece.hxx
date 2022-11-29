#pragma once

#include <iostream>
#include "position_set.hxx"
#include "ge211.hxx"

// A player or lack thereof.

enum class Player
{
    black,
    red,
    neither,
};

// Returns the other player.
Player other_player(Player);

// Prints a player in a manner suitable for debugging.
std::ostream& operator<<(std::ostream&, Player);


class Piece {
public:
    using Position = ge211::Posn<int>;

private:
    Player side;
    Position pos;
    std::string type;



public:
    //constructor
    Piece(std::string type, Position pos,Player side);
    // return the pos of the piece
    Position piece_pos();
    // return the side of the piece
    Player cur_side();
    // return the type of the string.
    std::string cur_type();

};