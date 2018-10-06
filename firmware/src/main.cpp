#include <Arduino.h>
#include "Motor.cpp"

#define BUTTON_1 11
#define BUTTON_2 10
#define BUTTON_3 12

#define NONE 0
#define FOWARD 1
#define RIGHT 2
#define LEFT 3
#define BACK 4

int direction = NONE;

Motor motorDerecho(2, 3);
Motor motorIzquierdo(5, 4);

#define MODE_NONE 0
#define MODE_PROG 1
#define MODE_RUN 2
#define MODE_TEST 3

int mode = MODE_NONE;

#define COMMANDS_SIZE 4
int commands[COMMANDS_SIZE];
int current = 0;

void blink(int speed = 500)
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(speed / 2);
    digitalWrite(LED_BUILTIN, LOW);
    delay(speed / 2);
}

void setMode(int value)
{
    mode = value;
    current = 0;

    if (mode == MODE_PROG)
    {
        // blink(200);
        // blink(200);
        // blink(200);
    }
    else if (mode == MODE_RUN)
    {
        blink(500);
        blink(400);
        blink(300);
        blink(200);
        blink(100);
    }
}

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);

    pinMode(BUTTON_1, INPUT_PULLUP);
    pinMode(BUTTON_2, INPUT_PULLUP);
    pinMode(BUTTON_3, INPUT_PULLUP);

    //test();

    setMode(MODE_PROG);
}

void tester()
{
    motorDerecho.stop();
    motorIzquierdo.stop();

    delay(1000);
    motorIzquierdo.foward();
    delay(1000);
    motorIzquierdo.stop();

    delay(1000);
    motorIzquierdo.back();
    delay(1000);
    motorIzquierdo.stop();

    delay(1000);
    motorDerecho.foward();
    delay(1000);
    motorDerecho.stop();

    delay(1000);
    motorDerecho.back();
    delay(1000);
    motorDerecho.stop();
}

void programmer()
{
    if (digitalRead(BUTTON_1) == LOW)
    {
        commands[current] = FOWARD;
        current++;
        blink();
    }
    else if (digitalRead(BUTTON_2) == LOW)
    {
        commands[current] = LEFT;
        current++;
        blink();
    }
    else if (digitalRead(BUTTON_3) == LOW)
    {
        commands[current] = RIGHT;
        current++;
        blink();
    }

    if (current == COMMANDS_SIZE)
    {
        setMode(MODE_RUN);
    }
}

void runner()
{
    byte command = commands[current++];

    switch (command)
    {
    case FOWARD:
        motorDerecho.foward();
        motorIzquierdo.foward();
        break;
    case LEFT:
        motorIzquierdo.stop();
        motorDerecho.foward();
        break;
    case RIGHT:
        motorDerecho.stop();
        motorIzquierdo.foward();
        break;
    case BACK:
        motorDerecho.back();
        motorIzquierdo.back();
        break;
    }

    if (current == COMMANDS_SIZE)
    {
        current = 0;
        setMode(MODE_PROG);

        motorDerecho.stop();
        motorIzquierdo.stop();
    }
    else
    {
        delay(1000);
    }
}

void loop()
{
    if (mode == MODE_PROG)
    {
        programmer();
    }
    else if (mode == MODE_RUN)
    {
        runner();
    }
    else if (mode == MODE_TEST)
    {
        tester();
    }
    return;
}
