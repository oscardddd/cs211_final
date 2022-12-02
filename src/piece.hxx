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
