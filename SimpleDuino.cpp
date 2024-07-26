// V0.0.0 Stable

#include <Arduino.h>

// SimpleDuino

class TwoMotors {
  public:
    int IN1;
    int IN2;
    int IN3;
    int IN4;
    int SPEED1;
    int SPEED2;
    void forward() {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }
    void backward() {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }
    void left() {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }
    void right() {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }
    void stop() {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }
    void changeSpeed(int speed) {
      analogWrite(SPEED1, speed);
      analogWrite(SPEED2, speed);
    }
    void begin(int IN1_user, int IN2_user, int IN3_user, int IN4_user, int SPEED1_user, int SPEED2_user) {
      IN1 = IN1_user;
      IN2 = IN2_user;
      IN3 = IN3_user;
      IN4 = IN4_user;
      SPEED1 = SPEED1_user;
      SPEED2 = SPEED2_user;
      pinMode(IN1, OUTPUT);
      pinMode(IN2, OUTPUT);
      pinMode(IN3, OUTPUT);
      pinMode(IN4, OUTPUT);
      pinMode(SPEED1, OUTPUT);
      pinMode(SPEED2, OUTPUT);
    }
};
