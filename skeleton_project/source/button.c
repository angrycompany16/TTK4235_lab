#include "button.h"

Button* button_init() {
    Button* p_button = (Button*)malloc(sizeof(Button));
    if (p_button != NULL) {
        p_button->pressed = false;
        p_button->was_just_pressed = true;
        p_button->was_just_released = false;
    }

    return p_button;
}

void button_deinit(Button* button) {
    free(button);
}

void button_update(Button* button, bool value) {
    if (!button->pressed && value) {
        button->was_just_pressed = true;
    } else if (button->pressed && !value) {
        button->was_just_released = true;
    } else {
        button->was_just_pressed = false;
        button->was_just_released = false;
    }

    button->pressed = value;
}




