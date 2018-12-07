#include "PID.h"

#include <cmath>
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    PID::Kp = Kp;
    PID::Kd = Kd;
    PID::Ki = Ki;

    p_error = d_error = i_error = 0.0;

    // Previous cte.
    prev_cte = 0.0;

    // Variables to calculate max, avg and min error.
    PID::num_data = 0.0;
    cteSum = 0.0;
    minError = std::numeric_limits<double>::max();
    maxError = std::numeric_limits<double>::min();
}

void PID::UpdateError(double cte) {
  // Proportional error.
  p_error = cte;

  // Integral error.
  i_error += cte;

  // Diferential error.
  d_error = cte - prev_cte;

  // Setting current cte as previous.
  prev_cte = cte;

  cteSum += cte;
  num_data++;

  if ( cte > maxError ) {
    maxError = cte;
  }
  if ( cte < minError ) {
    minError = cte;
  }

}

double PID::TotalError() {
  return p_error * Kp + i_error * Ki + d_error * Kd;
}

double PID::AverageError() {
  return cteSum/num_data;
}

double PID::MinError() {
  return minError;
}

double PID::MaxError() {
  return maxError;
}

