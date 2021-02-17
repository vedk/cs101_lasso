#ifndef __COIN_H__
#define __COIN_H__

#include "MovingObject.h"
#include <cstdlib>

class Coin : public MovingObject {
	double coin_start_x;
	double coin_start_y;
	double release_speed;
	double release_angle_deg;
	double coin_ax;
	double coin_ay;

	bool is_poison;

	// Moving parts
	Circle coin_circle;

 public:
	 Coin(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta):MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta) {
		release_speed = speed;
		release_angle_deg = angle_deg;
		coin_ax = argax;
		coin_ay = argay;
		if (rand() % 2)
			is_poison = true;
		else
			is_poison = false;
		initCoin();
	}
	
	void initCoin();
	void resetCoin();

	bool isPoison();
}; // End class Coin

#endif
