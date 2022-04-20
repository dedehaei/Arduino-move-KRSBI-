#include "motor.h"
motor kiri(3, 5);
motor belakang(7, 9);
motor kanan(11, 13);

void diam() {
  kanan.off();
  kiri.off();
  belakang.off();
}
void mundur() {
  kanan.ccw(33.8);
  kiri.cw(30);
  belakang.off();
}
void maju() {
  kanan.cw(33.8);
  kiri.ccw(30);
  belakang.off();
}

void geserkanan() {
  kanan.off();
  kiri.cw(30);
  belakang.ccw(30.5);
}

void geserkiri() {
  kanan.ccw(30);
  kiri.off();
  belakang.cw(30.5);
}

void putarkanan() {
  kanan.cw(30);
  kiri.cw(30);
  belakang.cw(30);
}

void putarkiri() {
  kanan.ccw(30);
  kiri.ccw (30);
  belakang.ccw(30);
}
