//#include <Arduino.h>
class motor {
    int RPWM;
    int LPWM;
  public:
    motor(byte rpwm, byte lpwm) {
      RPWM = rpwm;
      LPWM = lpwm;
      pinMode(RPWM, OUTPUT);
      pinMode(LPWM, OUTPUT);
    }
    void cw(float x) {
      analogWrite(RPWM, 0);
      analogWrite(LPWM, x);
    }
    void ccw(float x) {
      analogWrite(RPWM, x);
      analogWrite(LPWM, 0);
    }
    void off() {
      analogWrite(RPWM, 0);
      analogWrite(LPWM, 0);
    }
};
