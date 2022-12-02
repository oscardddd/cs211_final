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
    Position_set p2 = {{4,2}};
    CHECK(m.find_moves() == p2);
    m.play_move({2,4});


    //check it moves correctly after crossing the river
    m.set_pos({4,0},1);
    m.set_pos({5,0},-10);
    m.play_move({0,4});
    Position_set p3= {{3,0},{4,1}};
    CHECK(m.find_moves() == p3);



}

// this test case tests if our model computes the possible of a cannon
// correctly, and tests if it successfully captures a piece.

TEST_CASE("check_cannon_move_and_capture")
{
    Model m;
    CHECK(m[{7,1}] == 2);

    m.play_move({1,7});
    Position_set p1 = {{0, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}, {7, 0}, {7, 2},
                       {7, 3}, {7, 4}, {7, 5}, {7, 6}, {8, 1}};
    CHECK(m.find_moves() == p1);
    m.play_move({1,3});

    m.play_move({7,2});
    m.play_move({4,2});

    m.play_move({1,3});
    m.play_move({1,0});

    //check if the spot still has the captured piece
    CHECK(m.turn_ == Player::black);
    m.play_move({1,0});
    Position_set p2 = {};
    CHECK(m.find_moves() == p2);

}


//check if the horse moves correctly when and when there is not a special case.
TEST_CASE("check_horse_move_limitation")
{
    Model m;
    m.play_move({1,9});
    Position_set p1 = {{7,0},{7,2}};
    CHECK(m.find_moves() == p1);
    m.play_move({2,7});

    m.play_move({1,0});
    m.play_move({0,2});

    m.play_move({2,7});
    //check the possible moves when special case happens.
    Position_set p2 = {{8, 4}, {9, 1}};
    CHECK(m.find_moves() == p2);


}

// this test case tests the limitation of the elephants movements
// elephant cannot move if there are pieces blocking diagonal attacking or
// movement
TEST_CASE("check_elephant_move_limitation")
{
    Model m;

    //check initial elephant positions
    CHECK(m[{0, 2}] == 15);
    CHECK(m[{9,2}] == 5);

    //red elephant's first move
    m.play_move({2,9});
    Position_set move1 = {{7,0},{7,4}};
    CHECK(m.find_moves() == move1);
    m.play_move({4, 7});

    //black cannon's first move
    m.play_move({1, 2});
    m.play_move({3,2});

    //red elephant's second move
    m.play_move({4, 7});
    m.play_move({2, 9});

    //black cannon's second move and blocks red elephant's move back to
    //{4,7}
    m.play_move({3, 2});
    m.play_move({3, 8});

    //red elephant's third move and cannot move to {4,7}
    m.play_move({2, 9});
    Position_set move2 = {{7,0}};
    CHECK(m.find_moves() == move2);
}


// this test case runs the entire game by moving horses, soldiers, and cannons
// eventually the black general will be captured by the cannon.
TEST_CASE("run_the_entire_game")
{
    Model m;

    //red cannon's first move to the middle
    m.play_move({1, 7});
    m.play_move({4, 7});

    //black elephant's first move
    m.play_move({2,0});
    m.play_move({4, 2});

    //red cannon's capture of soldier in the middle
    m.play_move({4, 7});
    m.play_move({4,3});

    //black horse move
    m.play_move({1,0});
    m.play_move({2,2});

    //red cannon's capture of the black general
    m.play_move({4,3});
    m.play_move({4,0});

    CHECK(m.is_game_over());
}

