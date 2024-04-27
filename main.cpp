#include "mbed.h"

DigitalOut greenLED1(p11);
DigitalOut greenLED2(p12);
DigitalOut greenLED3(p13);

DigitalOut redLED1(p30);
DigitalOut redLED2(p29);
DigitalOut redLED3(p28);

DigitalIn switch1(p19);
DigitalIn switch2(p20);

DigitalIn switch3(p21);

int main() {
    switch1.mode(PullUp);
    switch2.mode(PullUp);

    greenLED1 = 0;
    greenLED2 = 0;
    greenLED3 = 0;

    redLED1 = 1;
    redLED2 = 1;
    redLED3 = 1;
    while(1) {

        if (switch1 == 0){ //Turns on Red LEDs
            wait_ms(25);
            
            if (redLED1 == 1){
                redLED1 = 0;
            }
            else if(redLED2 == 1){
                redLED2 = 0;
            }
            else if (redLED3 == 1){
                redLED3 = 0;
            }

            wait(0.4);
        }

        if (switch2 == 0){ //Turns on Green LEDs
            wait_ms(25);

            if (greenLED1 == 0){
                greenLED1 = 1;
            }
            else if(greenLED2 == 0){
                greenLED2 = 1;
            }
            else if (greenLED3 == 0){
                greenLED3 = 1;
            }

            wait(0.4);
        }

        if (switch3 == 1){ //Swaps LED's
            wait_ms(25);

            bool temp1;
            bool temp2;
            bool temp3;

            temp1 = redLED1;
            temp2 = redLED2;
            temp3 = redLED3;

            redLED1 = !greenLED1;
            redLED2 = !greenLED2;
            redLED3 = !greenLED3;

            greenLED1 = !temp1;
            greenLED2 = !temp2;
            greenLED3 = !temp3;

            wait(0.4);
        }
        
       

    }
}
