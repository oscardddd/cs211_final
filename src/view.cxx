#include "view.hxx"
#include "ge211.hxx"
static int const grid_size = 40;
static ge211:: Color const available_color {50, 100, 50};

View::View(Model const& model)
        : model_(model)
{ }

void
View::draw(ge211::Sprite_set& set)
{
    // This needs to do something!


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
View::add_piece_sprite_(ge211::Sprite_set& set, Position posn) const
{
    Position pos = {grid_size*posn.x,grid_size*posn.y};
    if (model_[posn] == 1) {
        set.add_sprite(soldier_red_sprite_, pos, 2);
    } else if (model_[posn] == 2) {
        set.add_sprite(cannon_red_sprite_, pos, 2);
    } else if (model_[posn] == 3) {
        set.add_sprite(car_red_sprite_, pos, 2);
    } else if (model_[posn] == 4) {
        set.add_sprite(horse_red_sprite_, pos, 2);
    } else if (model_[posn] == 5) {
        set.add_sprite(elephant_red_sprite_, pos, 2);
    } else if (model_[posn] == 6) {
        set.add_sprite(advisor_red_sprite_, pos, 2);
    } else if (model_[posn] == 7) {
        set.add_sprite(general_red_sprite_, pos, 2);
    } else if (model_[posn] == 11) {
        set.add_sprite(soldier_black_sprite_, pos, 2);
    } else if (model_[posn] == 12) {
        set.add_sprite(cannon_black_sprite_, pos, 2);
    } else if (model_[posn] == 13) {
        set.add_sprite(car_black_sprite_, pos, 2);
    } else if (model_[posn] == 14) {
        set.add_sprite(horse_black_sprite_, pos, 2);
    } else if (model_[posn] == 15) {
        set.add_sprite(elephant_black_sprite_, pos, 2);
    } else if (model_[posn] == 16) {
        set.add_sprite(advisor_black_sprite_, pos, 2);
    } else if (model_[posn] == 17) {
        set.add_sprite(general_black_sprite_, pos, 2);
    }
}
