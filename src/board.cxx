#include "board.hxx"
#include "piece.hxx"
#include <algorithm>

using namespace ge211;

Board::Board():
    matrix()
{
}

bool
Board::good_position(Position pos) const
{
    return 0 <= pos.x && pos.x < 9 &&
           0 <= pos.y && pos.y < 10;
}

//return the number representative at position pos
int
Board::operator[](Position pos) const
{
    bounds_check_(pos);
    return matrix[pos.x][pos.y];
}


// static std::vector<Board::Dimensions>
// build_directions()
// {
//     std::vector<Board::Dimensions> result;
//
//     for (int dx = -1; dx <= 1; ++dx) {
//         for (int dy = -1; dy <= 1; ++dy) {
//             if (dx || dy) {
//                 result.push_back({dx, dy});
//             }
//         }
//     }
//
//     return result;
// }

// std::vector<Board::Dimensions> const&
// Board::all_directions()
// {
//     static std::vector<Dimensions> result = build_directions();
//     return result;
// }

// int
// Board::get_(Position pos) const
// {
//     return matrix[pos.x][pos.y];
// }

void
Board::set(Position pos, int piece)
{
   matrix[pos.x][pos.y] = piece;
}

void
Board::bounds_check_(Position pos) const
{
    if (!good_position(pos)) {
        throw Client_logic_error("Board: position out of bounds");
    }
}







