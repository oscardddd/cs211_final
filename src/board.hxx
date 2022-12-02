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
    // std::vector<int> matrix;
    // {13, 14, 15, 16, 17, 16, 15, 14, 13},
    // {0,  0,  0,  0,  0,  0,  0,  0,  0},
    // {0,  12, 0,  0,  0,  0,  0,  12, 0},
    // {11, 0,  11, 0,  11, 0,  11, 0,  11},
    // {0,  0,  0,  0,  0,  0,  0,  0,  0},
    // {0,  0,  0,  0,  0,  0,  0,  0,  0},
    // {1,  0,  1,  0,  1,  0,  1,  0,  1},
    // {0,  2,  0,  0,  0,  0,  0,  2,  0},
    // {0,  0,  0,  0,  0,  0,  0,  0,  0},
    // {3,  4,  5,  6,  7,  6,  5,  4,  3}


public:
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
    //
    // HELPFUL TYPE ALIASES
    //

    // Board dimensions will use `int` coordinates.
    using Dimensions = ge211::Dims<int>;

    // Board positions will use `int` coordinates.
    using Position = ge211::Posn<int>;

    // Board rectangles will use `int` coordinates.
    using Rectangle = ge211::Rect<int>;


    // Defined and documented below.
    class reference;


private:
    //
    // PRIVATE HELPER FUNCTION MEMBERS
    //

    int get_(Position where) const;

    void bounds_check_(Position where) const;

public:
    //
    // PUBLIC CONSTRUCTOR & FUNCTION MEMBERS
    //

    /// Constructs a board with the given dimensions.
    Board();

    /// Returns the same `Dimensions` value passed to the
    /// constructor.

    /// Returns whether the given position is in bounds.
    bool good_position(Position) const;

    /// Returns the `Player` stored at `pos`.
    int operator[](Position pos) const;

    void set(Position pos,int piece);
    /// Returns a reference to a `std::vector` containing all eight "unit
    /// direction vectors". In Python notation, these are:
    ///
    /// ```python
    /// { Dims(dx, dy)
    ///       for dx in [-1, 0, 1]
    ///           for dy in [-1, 0, 1]
    ///               if dx or dy }
    /// ```
    void erase(Position pos);

    static std::vector<Dimensions> const& all_directions();

    /// Equality for boards.
    friend bool operator==(Board const&, Board const&);




#ifdef CS211_TESTING
    // When this class is compiled for testing, members of a struct named
    // Test_access will be allowed to access private members of this class.
    friend struct Test_access;
#endif
};


