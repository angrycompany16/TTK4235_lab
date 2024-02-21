#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    bool pressed;
    bool was_just_pressed;
    bool was_just_released;
} Button;

Button* button_init();

void button_deinit(Button* button);

void button_update(Button* button, bool value);