#include <cmath>
#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  PID::Kp = Kp;
  PID::Ki = Ki;
  PID::Kd = Kd;

  p_error = i_error = d_error = prev_error = 0.0;

  abs_i_error = 0.0;
  cnt = 0;
}

void PID::UpdateError(double cte) {

  p_error = cte;
  i_error += cte;
  d_error = cte - prev_error;
  prev_error = cte;

  abs_i_error += fabs(cte);
  cnt++;
}

double PID::TotalError() {
  return p_error * Kp + i_error * Ki + d_error * Kd;
}


