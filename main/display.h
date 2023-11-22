#define DISPLAY_H

#include <driver/gpio.h>

class Display {
public:
    Display();
    void showNumber(int number);

private:
    const gpio_num_t segmentPins[7] = {GPIO_NUM_5, GPIO_NUM_18, GPIO_NUM_19, GPIO_NUM_21, GPIO_NUM_22, GPIO_NUM_23, GPIO_NUM_25};

    void showSegment(const unsigned char segments[7]);
};