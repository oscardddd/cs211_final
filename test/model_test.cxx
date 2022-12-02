#include "model.hxx"
#include <catch.hxx>
#include <sstream>
using namespace ge211;

// TEST_CASE("check_initialize")
// {
//     Model m;
//     CHECK_FALSE(m.is_game_over());
//     CHECK(m.turn_ == Player::red);
//     CHECK(m.get_winner() == Player::neither);
//     CHECK(m[{0,0}] == 13);
//     CHECK(m[{9,0}] == 3);
//
// }

//check if the soldier moves correctly before and after crossing the river.
//specifically, it could only move forwards before crossing and is able to
//move left and right after crossing.
TEST_CASE("check_soldier_cross_river")
{
    Model m;
    //check incorrect first click
    m.play_move({0,0});
    CHECK(m.find_moves().empty());

    m.play_move({0,6});

    Position_set h1 = m.find_moves();
    //check if we correctly compute the possible moves of a soldier before
    //crossing the river.
    Position_set p1 = {{5,0}};
    CHECK( h1 == p1);


    m.play_move({0, 5});
    //after second click, check if the find_moves is reset to empty
    CHECK(m.find_moves().empty());

    //check black piece
    m.play_move({2,3});
    Position_set p2 = {{3,2}};
    m.play_move({2,4});
    CHECK(m.find_moves() == p2);

    //check it moves correctly after crossing the river
    m.set_pos({4,0},1);
    m.set_pos({5,0},0);
    m.play_move({0,4});
    Position_set p3= {{3,0},{4,1}};
    CHECK(m.find_moves() == p3);

}

// this test case tests if our model computes the possible of a cannon
// correctly, and tests if it successfully captures a piece.

TEST_CASE("check_cannon_move_and_capture")
{
    Model m;
    CHECK(m[{1,7}] == 2);

    m.play_move({1,7});
    Position_set p1 = {{}};
    CHECK(m.find_moves() == p1);
    m.play_move({1,3});


}

TEST_CASE("check_horse_move_limitation")
{

}

TEST_CASE("check_elephant_move_limitation")
{

}

TEST_CASE("run_the_entire_game")
{

}

