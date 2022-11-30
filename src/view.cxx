#include "view.hxx"
#include "ge211.hxx"
static int const grid_size = 40;
static ge211:: Color const available_color {50, 100, 50};

View::View(Model const& model)
        : model_(model),
          car_red_sprite_("Car_red_pic.png"),
          horse_red_sprite_("Horse_red_pic.png"),
          elephant_red_sprite_("Elephant_red_pic.png"),
          advisor_red_sprite_("Advisor_red_pic.png"),
          general_red_sprite_("General_red_pic.png"),
          cannon_red_sprite_("Cannon_red_pic.png"),
          soldier_red_sprite_("Soldier_red_pic.png"),
          car_black_sprite_("Car_black_pic.png"),
          horse_black_sprite_("Horse_black_pic.png"),
          elephant_black_sprite_("Elephant_black_pic.png"),
          advisor_black_sprite_("Advisor_black_pic.png"),
          general_black_sprite_("General_black_pic.png"),
          cannon_black_sprite_("Cannon_black_pic.png"),
          soldier_black_sprite_("Soldier_black_pic.png"),
          available_moves_sprite_(grid_size, available_color),
          background_sprite_("Board_background_pic.png"),
          board_top_sprite_("Board_top_pic.jpg"),
          board_left_sprite_("Board_left_pic.jpg"),
          board_right_sprite_("Board_right_pic.jpg"),
          board_corner1_sprite_("Corner1.jpg"),
          board_corner2_sprite_("Corner2.jpg")
{}

void
View::draw(ge211::Sprite_set& set)
{
    for (int j = 0; j < 9; j++) {
        for (int i = 0; i < 10; i++) {
            ge211::Posn<int> grid_pos = {grid_size * j,
                                         grid_size * i};
            if (i == 0 && j == 0) {
                set.add_sprite(board_corner1_sprite_, grid_pos, 1,
                               ge211::Transform().set_scale(0.45));
            } else if (i == 0 && j == 8){
                set.add_sprite(board_corner2_sprite_, grid_pos, 1,
                               ge211::Transform().set_scale(0.45));
            } else if (j == 0) {
                set.add_sprite(board_left_sprite_, grid_pos, 1,
                               ge211::Transform().set_scale(0.45));
            } else if (j == 8) {
                set.add_sprite(board_right_sprite_, grid_pos, 1,
                               ge211::Transform().set_scale(0.45));
            } else if (i == 0) {
                set.add_sprite(board_top_sprite_, grid_pos, 1,
                               ge211::Transform().set_scale(0.45));
            } else {
                set.add_sprite(background_sprite_, grid_pos, 1,
                               ge211::Transform().set_scale(0.2));
            }
            add_piece_sprite_(set, {j,i});
        }
    }
}

View::Position
View::board_to_screen(Model::Position pos) const
{
    return {9 * pos.x, 8 * pos.y};
}

Model::Position
View::screen_to_board(View::Position pos) const
{
    return {pos.x / 9, pos.y / 8};
}

View::Dimensions
View::initial_window_dimensions() const
{
    // You can change this if you want:
    Dimensions board_dim = {9,10};
    return grid_size * board_dim;
}

std::string View::initial_window_title() const
{
    return "Chinese Chess";
}

void
View::add_piece_sprite_(ge211::Sprite_set& set, Position posn2) const
{
    Position pos = {grid_size * posn2.x ,grid_size * posn2.y };
    Position posn = {posn2.y,posn2.x};
    if (model_[posn] == 1) {
        set.add_sprite(soldier_red_sprite_, pos, 3,
                       ge211::Transform().set_scale(0.25));
    } else if (model_[posn] == 2) {
        set.add_sprite(cannon_red_sprite_, pos, 3,
                       ge211::Transform().set_scale(0.25));
    } else if (model_[posn] == 3) {
        set.add_sprite(car_red_sprite_, pos, 3,
                       ge211::Transform().set_scale(0.25));
    } else if (model_[posn] == 4) {
        set.add_sprite(horse_red_sprite_, pos, 3,
                       ge211::Transform().set_scale(0.25));
    } else if (model_[posn] == 5) {
        set.add_sprite(elephant_red_sprite_, pos, 3,
                       ge211::Transform().set_scale(0.25));
    } else if (model_[posn] == 6) {
        set.add_sprite(advisor_red_sprite_, pos, 3,
                       ge211::Transform().set_scale(0.25));
    } else if (model_[posn] == 7) {
        set.add_sprite(general_red_sprite_, pos, 3,
                       ge211::Transform().set_scale(0.25));
    } else if (model_[posn] == 11) {
        set.add_sprite(soldier_black_sprite_, pos, 3,
                       ge211::Transform().set_scale(0.25));
    } else if (model_[posn] == 12) {
        set.add_sprite(cannon_black_sprite_, pos, 3,
                       ge211::Transform().set_scale(0.25));
    } else if (model_[posn] == 13) {
        set.add_sprite(car_black_sprite_, pos, 3,
                       ge211::Transform().set_scale(0.25));
    } else if (model_[posn] == 14) {
        set.add_sprite(horse_black_sprite_, pos, 2,
                       ge211::Transform().set_scale(0.25));
    } else if (model_[posn] == 15) {
        set.add_sprite(elephant_black_sprite_, pos, 2,
                       ge211::Transform().set_scale(0.25));
    } else if (model_[posn] == 16) {
        set.add_sprite(advisor_black_sprite_, pos, 2,
                       ge211::Transform().set_scale(0.25));
    } else if (model_[posn] == 17) {
        set.add_sprite(general_black_sprite_, pos, 2,
                       ge211::Transform().set_scale(0.25));
    }
}
