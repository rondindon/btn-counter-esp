#include "Display.h"
#include <driver/gpio.h>

const uint8_t segmentPins[] = {GPIO_NUM_5, GPIO_NUM_18, GPIO_NUM_19, GPIO_NUM_21, GPIO_NUM_22, GPIO_NUM_23, GPIO_NUM_25};

const unsigned char numbers[10][7] = {
    {1, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 0, 0, 1},
    {0, 1, 1, 0, 0, 1, 1},
    {1, 0, 1, 1, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1}
};

Display::Display() {
    for (int i = 0; i < 7; i++) {
        gpio_set_direction(segmentPins[i], GPIO_MODE_OUTPUT);
    }
}

void Display::showNumber(int number) {
    if (number >= 0 && number <= 9) {
        showSegment(numbers[number]);
    } else {
        // Ak číslo nie je v rozsahu 0 až 9, zobrazte výchozí hodnotu (napr. 0).
        showSegment(numbers[0]);
    }
}

void Display::showSegment(const unsigned char segments[7]) {
    for (int i = 0; i < 7; i++) {
        gpio_set_level(segmentPins[i], segments[i]);
    }
}