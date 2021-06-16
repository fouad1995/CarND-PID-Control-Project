#include "PID.h"
#include <iostream>
/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID():mCteObserver(0.0),mPrevCteObserver(0.0),mOscillationThreshold(2),mCounter(0){}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
	Kp = Kp_;
	Ki = Ki_;
	Kd = Kd_;


	// initialize error to zeros
	p_error = 0.0;
	i_error = 0.0;
	d_error = 0.0;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
	mCteObserver = cte;
	// update the drevative
	d_error = cte - p_error;

	// proportional error is the cte 
	p_error = cte;

	// i error is the accumlated cte 
	i_error += cte;


}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return (-Kp * p_error) - (Ki * i_error) - (Kd * d_error);
  
}