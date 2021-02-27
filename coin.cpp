#include "coin.h"
#include "lasso.h"

void Coin::initCoin()
{
	coin_start_x = (PLAY_X_START + WINDOW_X) / 2;
	coin_start_y = PLAY_Y_HEIGHT;
	coin_circle.reset(coin_start_x, coin_start_y, COIN_SIZE);
	if (is_poison)
		coin_circle.setColor(COLOR("red"));
	else 
		coin_circle.setColor(COLOR("gold"));
	coin_circle.setFill(true);
	addPart(&coin_circle);
}

bool Coin::isPoison() {
	return is_poison;
}

void Coin::resetCoin()
{
	double coin_speed = COIN_SPEED;
	double coin_angle_deg = COIN_ANGLE_DEG;
	coin_ax = 0;
	coin_ay = COIN_G;
	bool paused = true, rtheta = true;

	// decide the colour of coin at random
	if (rand() % 2)
		is_poison = true;
	else
		is_poison = false;

	if (is_poison)
		coin_circle.setColor(COLOR("red"));
	else
		coin_circle.setColor(COLOR("gold"));

	reset_all(coin_start_x, coin_start_y, coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
}
