#include <Arduino.h>

#ifndef MOTOR_CLASS
#define MOTOR_CLASS

class Motor
{
  public:
    Motor(int in1, int in2, int power)
    {
        this->in1 = in1;
        this->in2 = in2;
        this->power = power;
        this->speed = 100;

        pinMode(this->in1, OUTPUT);
        pinMode(this->in2, OUTPUT);
    }

    void foward()
    {
        analogWrite(this->power, this->speed);
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

    void faster()
    {
        if (this->speed < 245)
            this->speed += 10;
        else
            this->speed = 255;
    }

    uint8_t getSpeed()
    {
        return speed;
    }

    void setSpeed(uint8_t speed)
    {
        this->speed = speed;
    }

  private:
    uint8_t in1, in2, power;
    uint8_t speed;
};

#endif