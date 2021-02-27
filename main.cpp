#include <simplecpp>
#include <string>
#include "MovingObject.h"
#include "lasso.h"
#include "coin.h"
#include "HighScoreDb.h"

#include <ctime>

using namespace simplecpp;

int main() {
	srand(time(NULL)); // seed the RNG

	initCanvas("Lasso", WINDOW_X, WINDOW_Y);
	int stepCount = 0;
	float stepTime = STEP_TIME;
	float runTime = -1;	// sec; -ve means infinite
	float currTime = 0;

	// Draw lasso at start position
	double release_speed = INIT_RELEASE_SPEED;	// m/s
	double release_angle_deg = INIT_RELEASE_ANGLE_DEG;	// degrees
	double lasso_ax = 0;
	double lasso_ay = LASSO_G;
	bool paused = true;
	bool rtheta = true;

	// The database (i.e. hs.dat file) which stores the highscore
	HighScoreDb hsdb;
	cout << "High Score = " << hsdb.getHighScore() << endl;

	Lasso lasso(release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);

	Line b1(0, PLAY_Y_HEIGHT, WINDOW_X, PLAY_Y_HEIGHT);
	b1.setColor(COLOR("blue"));
	Line b2(PLAY_X_START, 0, PLAY_X_START, WINDOW_Y);
	b2.setColor(COLOR("blue"));

	string msg("Cmd: _");
	Text charPressed(PLAY_X_START + 50, PLAY_Y_HEIGHT + 20, msg);

	string str_lives_left("Lives Left: " + to_string(lasso.getLivesLeft()));
	Text txtLivesLeft(PLAY_X_START + 50, PLAY_Y_HEIGHT + 80, str_lives_left);

	string str_hs("High Score: " + to_string(hsdb.getHighScore()));
	Text txtHighScore(PLAY_X_START + 150, PLAY_Y_HEIGHT + 80, str_hs);

	char coinScoreStr[256];
	sprintf(coinScoreStr, "Coins: %d", lasso.getNumCoins());
	Text coinScore(PLAY_X_START + 50, PLAY_Y_HEIGHT + 50, coinScoreStr);

	paused = true;
	rtheta = true;
	double coin_speed = COIN_SPEED;
	double coin_angle_deg = COIN_ANGLE_DEG;
	double coin_ax = 0;
	double coin_ay = COIN_G;
	Coin coin(coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);

	// After every COIN_GAP sec, make the coin jump
	double last_coin_jump_end = 0;

	// When t is pressed, throw lasso
	// If lasso within range, make coin stick
	// When y is pressed, yank lasso
	// When l is pressed, loop lasso
	// When q is pressed, quit

	while(true) {
		if ((runTime > 0) && (currTime > runTime)) {
			break;
		}

		XEvent e;
		bool pendingEv = checkEvent(e);
		if (pendingEv) {
			char c = charFromEvent(e);
			msg[msg.length() - 1] = c;
			charPressed.setMessage(msg);
			switch (c) {
			case 't':
				lasso.unpause();
				break;
			case 'y':
				lasso.yank();
				break;
			case 'l':
				lasso.loopit();
				lasso.check_for_coin(&coin);
				wait(STEP_TIME * 5);
				break;
			case '[':
				if (lasso.isPaused()) {
					lasso.addAngle(-RELEASE_ANGLE_STEP_DEG);
				}
				break;
			case ']':
				if (lasso.isPaused()) {
					lasso.addAngle(+RELEASE_ANGLE_STEP_DEG);
				}
				break;
			case '-':
				if (lasso.isPaused()) {
					lasso.addSpeed(-RELEASE_SPEED_STEP);
				}
				break;
			case '=':
				if (lasso.isPaused()) {
					lasso.addSpeed(+RELEASE_SPEED_STEP);
				}
				break;
			case 'q':
				exit(0);
			default:
				break;
			}
		}

		lasso.nextStep(stepTime);

		coin.nextStep(stepTime);
		if (coin.isPaused()) {
			if ((currTime - last_coin_jump_end) >= COIN_GAP) {
				coin.unpause();
			}
		}

		if (coin.getYPos() > PLAY_Y_HEIGHT) {
			coin.resetCoin();
			last_coin_jump_end = currTime;
		}

		// Update the hs.dat file
		if (lasso.getNumCoins() > hsdb.getHighScore())
		{
			hsdb.setHighScore(lasso.getNumCoins());
			hsdb.writeToDisk();
			txtHighScore.setMessage("High Score: " + to_string(hsdb.getHighScore()));
		}

		// update number of coins collected
		sprintf(coinScoreStr, "Coins: %d", lasso.getNumCoins());
		coinScore.setMessage(coinScoreStr);

		// update number of lives left
		str_lives_left = "Lives Left: " + to_string(lasso.getLivesLeft());
		txtLivesLeft.setMessage(str_lives_left);

		stepCount++;
		currTime += stepTime;
		wait(stepTime);
	} // end while(true)

	return 0;
}
