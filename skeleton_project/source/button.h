#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Button {
    bool is_pressed;
    bool was_pressed;
    bool was_just_pressed;
    bool was_just_released;
} Button;

Button* init_button();

void button_update(Button* button, bool value);