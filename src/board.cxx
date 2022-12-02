#include "board.hxx"
#include "piece.hxx"
#include <algorithm>

using namespace ge211;

Board::Board()

{}

bool
Board::good_position(Position pos) const
{
    return (0 <= pos.x && pos.x < 10) &&
            (0 <= pos.y && pos.y < 9);
}

//return the number representative at position pos
int
Board::operator[](Position pos) const
{
    bounds_check_(pos);
    return matrix[pos.x][pos.y];
}

void
Board::set(Position pos, int piece)
{
   matrix[pos.x][pos.y] = piece;
}

void Board::erase(Board::Position pos)
{
    matrix[pos.x][pos.y] = -10;
}
void
Board::bounds_check_(Position pos) const
{
    if (!good_position(pos)) {
        throw Client_logic_error("Board: position out of bounds");
    }
}







