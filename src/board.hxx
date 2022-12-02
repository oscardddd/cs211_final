#include <ge211.hxx>

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "position_set.hxx"
#include "piece.hxx"

class Board
{
private:
    int matrix[10][9] = {
            {13, 14, 15, 16, 17, 16, 15, 14, 13},
            {-10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10},
            {-10,  12, -10,  -10,  -10,  -10,  -10,  12, -10},
            {11, -10,  11, -10,  11, -10,  11, -10,  11},
            {-10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10},
            {-10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10},
            {1,  -10,  1,  -10,  1,  -10,  1,  -10,  1},
            {-10,  2,  -10,  -10,  -10,  -10,  -10,  2,  -10},
            {-10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10},
            {3,  4,  5,  6,  7,  6,  5,  4,  3}
    };

public:
    //
    // HELPFUL TYPE ALIASES
    //

    // Board dimensions will use `int` coordinates.
    using Dimensions = ge211::Dims<int>;

    // Board positions will use `int` coordinates.
    using Position = ge211::Posn<int>;

private:
    //
    // PRIVATE HELPER FUNCTION MEMBERS
    //
    void bounds_check_(Position where) const;

public:
    //
    // PUBLIC CONSTRUCTOR & FUNCTION MEMBERS
    //

    Board();

    bool good_position(Position) const;

    int operator[](Position pos) const;

    void set(Position pos,int piece);

    void erase(Position pos);

    friend bool operator==(Board const&, Board const&);




#ifdef CS211_TESTING
    // When this class is compiled for testing, members of a struct named
    // Test_access will be allowed to access private members of this class.
    friend struct Test_access;
#endif
};


