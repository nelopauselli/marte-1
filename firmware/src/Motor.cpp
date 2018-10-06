#include <Arduino.h>

#ifndef MOTOR_CLASS
#define MOTOR_CLASS

class Motor
{
  public:
    Motor(int in1, int in2)
    {
        this->in1 = in1;
        this->in2 = in2;

        pinMode(this->in1, OUTPUT);
        pinMode(this->in2, OUTPUT);
    }

    void foward()
    {
        digitalWrite(this->in2, LOW);
        digitalWrite(this->in1, HIGH);
    }

    void back()
    {
        digitalWrite(this->in1, LOW);
        digitalWrite(this->in2, HIGH);
    }

    void stop()
    {
        digitalWrite(this->in1, LOW);
        digitalWrite(this->in2, LOW);
    }

  private:
    int in1, in2;
};

#endif