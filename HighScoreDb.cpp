#include <iostream>
using namespace std;

#include "HighScoreDb.h"

/**
 * Logic taken from https://stackoverflow.com/questions/12774207/fastest-way-to-check-if-a-file-exist-using-standard-c-c11-c
 */
bool HighScoreDb::highScoreDbExists()
{
	if (FILE *file = fopen("hs.dat", "r"))
	{
		fclose(file);
		return true;
	}
	else
		return false;
}

HighScoreDb::HighScoreDb()
{

	if (!highScoreDbExists())
	{
		highscore = 0;
		fp = fopen("hs.dat", "w+");
		fprintf(fp, "0");
	}
	else
	{
		fp = fopen("hs.dat", "r+");
		fscanf(fp, "%d", &highscore);
	}
}

int HighScoreDb::getHighScore()
{
	return highscore;
}

void HighScoreDb::setHighScore(int hs)
{
	highscore = hs;
}

void HighScoreDb::writeToDisk()
{
	rewind(fp);
	fprintf(fp, "%d", highscore);
}

HighScoreDb::~HighScoreDb()
{
	fclose(fp);
}