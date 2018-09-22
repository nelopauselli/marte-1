#include <Arduino.h>

#ifndef MOTOR_CLASS
#define MOTOR_CLASS

#define MAX_STEPS 4

class Motor
{
  public:
    Motor(int in1, int in2, int in3, int in4)
    {
        this->in1 = in1;
        this->in2 = in2;
        this->in3 = in3;
        this->in4 = in4;

        pinMode(this->in1, OUTPUT);
        pinMode(this->in2, OUTPUT);
        pinMode(this->in3, OUTPUT);
        pinMode(this->in4, OUTPUT);

        step = 0;
    }

    void foward()
    {
        step++;
        if (step > MAX_STEPS - 1)
            step = 0;
            move();
    }

    void back()
    {
        step--;
        if (step < 0)
            step = MAX_STEPS - 1;
        move();
    }

  private:
    short steps[MAX_STEPS] = {0b00000001, 0b00000010, 0b00000100, 0b00001000};
    int in1, in2, in3, in4;
    int step;

    void move()
    {
        const short &current = steps[step % MAX_STEPS];
        digitalWrite(in1, current & 0b00000001);
        digitalWrite(in2, current & 0b00000010);
        digitalWrite(in3, current & 0b00000100);
        digitalWrite(in4, current & 0b00001000);

        Serial.print(current & 0b00000001 ? '1' : '0');
        Serial.print(current & 0b00000010 ? '1' : '0');
        Serial.print(current & 0b00000100 ? '1' : '0');
        Serial.print(current & 0b00001000 ? '1' : '0');
        Serial.println();
    }
};

#endif