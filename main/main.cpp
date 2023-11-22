#include "Led.h"
#include "Button.h"
#include "Display.h"
#include "stdio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

extern "C" 

void app_main() {
    Led led(GPIO_NUM_2);
    Button button(GPIO_NUM_4);
    Display display;

    int number = 0;

    while (1) {
        if (button.isPressed()) {
            number = (number + 1) % 10;
            led.on();
            display.showNumber(number);
            while (button.isPressed())
            {
                vTaskDelay(1);
            }
            
        } else {
            led.off();
        }

        vTaskDelay(50 / portTICK_PERIOD_MS);
    }
}