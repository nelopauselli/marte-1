#include <Arduino.h>
#include "Motor.cpp"

#define FOWARD 1
#define RIGHT 2
#define BACK 3
#define LEFT 4
int direction = FOWARD;

Motor motorDerecho(5, 4, 3, 2);
Motor motorIzquierdo(9, 8, 7, 6);

void setup()
{
    Serial.begin(115200);
    // delay(1000);

    Serial.println("Motores Inicializados");
}

int steps = 0;
void loop()
{
    switch (direction)
    {
    case FOWARD:
        motorDerecho.foward();
        motorIzquierdo.foward();
        break;
    case LEFT:
        motorDerecho.foward();
        motorIzquierdo.back();
        break;
    case BACK:
        motorDerecho.back();
        motorIzquierdo.back();
        break;
    case RIGHT:
        motorDerecho.back();
        motorIzquierdo.foward();
        break;
    }

    delay(3);

    steps++;
    if (steps > 2048)
    {
        steps = 0;
        switch (direction)
        {
        case FOWARD:
            direction = BACK;
            Serial.println("Back");
            break;
        case BACK:
            direction = LEFT;
            Serial.println("Left");
            break;
        case LEFT:
            direction = RIGHT;
            Serial.println("Right");
            break;
        case RIGHT:
            direction = FOWARD;
            Serial.println("Foward");
            break;
        }
    }
}
