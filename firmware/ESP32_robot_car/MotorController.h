#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include <Arduino.h>

// --- PENGATURAN PIN MOTOR ---
#define ENA 14
#define IN1 27
#define IN2 26
#define ENB 32
#define IN3 25
#define IN4 33

class MotorController {
private:
    int motorSpeed;

public:
    MotorController();
    void begin();
    void setSpeed(int speed);
    int getSpeed() const;
    void stop();
    void moveForward();
    void moveBackward();
    void turnLeft();
    void turnRight();
};

#endif
