#pragma once

#include "model.hxx"

class View
{
public:
    using Dimensions = ge211::Dims<int>;

    using Position = ge211::Posn<int>;


    View(Model const&);

    void draw(ge211::Sprite_set& set);

    Position
    board_to_screen(Model::Position board_pos) const;

    Model::Position
    screen_to_board(Position screen_pos) const;

    Dimensions initial_window_dimensions() const;
    std::string initial_window_title() const;
    void update_mouse(Position pos);
    void play_move(Position pos);


private:
    Model model_;
    ge211::Image_sprite car_red_sprite_;
    ge211::Image_sprite horse_red_sprite_;
    ge211::Image_sprite elephant_red_sprite_;
    ge211::Image_sprite advisor_red_sprite_;
    ge211::Image_sprite general_red_sprite_;
    ge211::Image_sprite cannon_red_sprite_;
    ge211::Image_sprite soldier_red_sprite_;
    ge211::Image_sprite car_black_sprite_;
    ge211::Image_sprite horse_black_sprite_;
    ge211::Image_sprite elephant_black_sprite_;
    ge211::Image_sprite advisor_black_sprite_;
    ge211::Image_sprite general_black_sprite_;
    ge211::Image_sprite cannon_black_sprite_;
    ge211::Image_sprite soldier_black_sprite_;
    ge211::Circle_sprite available_moves_sprite_;
    ge211::Image_sprite background_sprite_;
    ge211::Image_sprite board_top_sprite_;
    ge211::Image_sprite board_left_sprite_;
    ge211::Image_sprite board_right_sprite_;
    ge211::Image_sprite board_corner1_sprite_;
    ge211::Image_sprite board_corner2_sprite_;
    ge211::Image_sprite board_corner3_sprite_;
    ge211::Image_sprite board_corner4_sprite_;
    ge211::Image_sprite board_bottom_sprite_;
    ge211::Image_sprite lower_river_sprite_;
    ge211::Image_sprite upper_river_sprite_;
    ge211::sprites::Circle_sprite indicator;
    ge211::sprites::Circle_sprite indicator_red;
    ge211::sprites::Circle_sprite indicator_black;
    ge211::sprites::Text_sprite blackwin;
    ge211::sprites::Text_sprite redwin;
    ge211::sprites::Rectangle_sprite winning_bg;

    ge211::geometry::Posn<int> mouse_p = {0,0};


    void
    add_piece_sprite_(ge211::Sprite_set&, Position)
    const;
};
