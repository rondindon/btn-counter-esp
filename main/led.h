#define LED_H

#include "driver/gpio.h"

class Led {
public:
    Led(gpio_num_t pin);
    void on();
    void off();

private:
    gpio_num_t pin;
};