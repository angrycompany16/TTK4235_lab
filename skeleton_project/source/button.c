#include "button.h"

Button* init_button() {
    return &(Button) {false, false, false};
}

void button_update(Button* button, bool value) {
    button->is_pressed = value;

    if (button->is_pressed && !button->was_pressed) {
        button->was_just_pressed = true;
    } else if (!button->is_pressed && button->was_pressed) {
        button->was_just_released = true;
    } else {
        button->was_just_pressed = false;
        button->was_just_released = false;
    }

    button->was_pressed = button->is_pressed;
}




