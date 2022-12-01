#include "controller.hxx"

Controller::Controller()
        :
        model_(),
        view_(model_),
        mouse{0,0}
{ }

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.update_mouse(mouse);
    view_.draw(set);
}

void Controller::on_mouse_up(
        ge211::events::Mouse_button,
        ge211::geometry::Posn<int> pos)
{
    ge211::geometry::Posn<int> real_pos = view_.screen_to_board(pos);
    // real_pos = {real_pos.y,real_pos.x};

    model_.play_move(real_pos);

}

View::Dimensions Controller::initial_window_dimensions() const
{
    return view_.initial_window_dimensions();
}

std::string Controller::initial_window_title() const
{
    return view_.initial_window_title();
}

void Controller::on_mouse_move(ge211::geometry::Posn<int> pos)
{
    mouse = pos;
}
