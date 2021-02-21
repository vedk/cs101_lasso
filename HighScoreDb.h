#ifndef HIGHSCOREDB_H
#define HIGHSCOREDB_H

#include <cstdio>

class HighScoreDb
{
private:
	int highscore;
	FILE *fp;

public:
	HighScoreDb();
	~HighScoreDb();

	int getHighScore();
	void setHighScore(int hs);

	void writeToDisk();
	//void readFromDisk();

	bool highScoreDbExists();
};

#endif /*HIGHSCOREDB_H*/