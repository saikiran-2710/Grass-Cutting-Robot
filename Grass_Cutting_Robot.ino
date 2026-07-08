/*
--------------------------------------------------
Grass Cutting Robot using Arduino UNO

Author : Sai Kiran

Features:
- Autonomous Navigation
- Obstacle Detection
- Obstacle Avoidance
- Servo based Ultrasonic Scanning

Components:
- Arduino UNO
- L293D Motor Driver Shield
- HC-SR04 Ultrasonic Sensor
- Servo Motor
- 4 DC Motors
- LiPo Battery
--------------------------------------------------
*/

#include <AFMotor.h>
#include <Servo.h>
#include <NewPing.h>

// Motors on M1, M2, M3, M4
AF_DCMotor motor1(1);   // Front Left
AF_DCMotor motor2(2);   // Front Right
AF_DCMotor motor3(3);   // Rear Left
AF_DCMotor motor4(4);   // Rear Right

// Ultrasonic Sensor
#define trig_pin A0
#define echo_pin A1
#define maximum_distance 200

NewPing sonar(trig_pin, echo_pin, maximum_distance);

// Servo Motor
Servo myservo;

int distance = 0;

void setup()
{
    myservo.attach(10);
    myservo.write(90);
    delay(1000);

    motor1.setSpeed(200);
    motor2.setSpeed(200);
    motor3.setSpeed(200);
    motor4.setSpeed(200);

    Serial.begin(9600);
}

void loop()
{
    distance = readPing();

    Serial.print("Distance: ");
    Serial.println(distance);

    if(distance <= 20)
    {
        stopMove();
        delay(300);

        moveBackward();
        delay(400);

        stopMove();
        delay(300);

        int rightDistance = lookRight();
        delay(300);

        int leftDistance = lookLeft();
        delay(300);

        if(rightDistance >= leftDistance)
        {
            turnRight();
            delay(500);
        }
        else
        {
            turnLeft();
            delay(500);
        }

        stopMove();
    }
    else
    {
        moveForward();
    }
}

// ----------------------------
// Movement Functions
// ----------------------------

void moveForward()
{
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
}

void moveBackward()
{
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
}

void turnRight()
{
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
}

void turnLeft()
{
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
}

void stopMove()
{
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
}

// ----------------------------
// Ultrasonic Functions
// ----------------------------

int readPing()
{
    delay(50);

    int cm = sonar.ping_cm();

    if(cm == 0)
        cm = 250;

    return cm;
}

int lookRight()
{
    myservo.write(20);
    delay(500);

    int distance = readPing();

    delay(100);

    myservo.write(90);
    delay(300);

    return distance;
}

int lookLeft()
{
    myservo.write(160);
    delay(500);

    int distance = readPing();

    delay(100);

    myservo.write(90);
    delay(300);

    return distance;
}
