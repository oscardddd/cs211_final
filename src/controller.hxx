#pragma once

#include "model.hxx"
#include "view.hxx"

#include <ge211.hxx>

class Controller : public ge211::Abstract_game
{
public:
    Controller();

protected:
    void draw(ge211::Sprite_set& set) override;
    void on_mouse_up(ge211::events::Mouse_button,ge211::geometry::Posn<int>);
    void on_mouse_move(ge211::geometry::Posn<int>);

    View::Dimensions initial_window_dimensions() const override;
    std::string initial_window_title() const override;


private:
    Model model_;
    View view_;
    ge211::Posn<int> first_click;
    ge211::Posn<int> second_click;
    ge211::Posn<int> mouse;


};
