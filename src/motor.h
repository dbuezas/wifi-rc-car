#pragma once
#include <Arduino.h>
#include <LOLIN_I2C_MOTOR.h>

#define MOTOR_FREQ 80000
LOLIN_I2C_MOTOR motor;
struct {
  bool pending = false;
  float x = 0;
  float y = 0;
} _pending_command;

void _move_now(float x, float y) {
  if (x > 0) {
    motor.changeStatus(MOTOR_CH_A, MOTOR_STATUS_CW);
  } else if (x < 0) {
    motor.changeStatus(MOTOR_CH_A, MOTOR_STATUS_CCW);
  } else {
    motor.changeStatus(MOTOR_CH_A, MOTOR_STATUS_SHORT_BRAKE);
  }
  motor.changeDuty(MOTOR_CH_A, abs(x) * 100);

  if (y > 0) {
    motor.changeStatus(MOTOR_CH_B, MOTOR_STATUS_CW);
  } else if (y < 0) {
    motor.changeStatus(MOTOR_CH_B, MOTOR_STATUS_CCW);
  } else {
    motor.changeStatus(MOTOR_CH_B, MOTOR_STATUS_SHORT_BRAKE);
  }

  motor.changeDuty(MOTOR_CH_B, abs(y) * 100);
}

void setup_motor() {
  // while (motor.PRODUCT_ID != PRODUCT_ID_I2C_MOTOR) {
  //   motor.getInfo();
  // }
  motor.reset();
  motor.changeStatus(MOTOR_CH_BOTH, MOTOR_STATUS_STOP);
  motor.changeFreq(MOTOR_CH_BOTH, MOTOR_FREQ);
  motor.changeDuty(MOTOR_CH_BOTH, 0);
}
void loop_motor() {
  if (_pending_command.pending) {
    _pending_command.pending = false;
    _move_now(_pending_command.x, _pending_command.y);
  }
}

void motor_command(float x, float y) {
  _pending_command.x = x;
  _pending_command.y = y;
  _pending_command.pending = true;
}
