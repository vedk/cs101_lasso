#include <iostream>
using namespace std;

#include "HighScoreDb.h"

/**
 * Logic taken from https://stackoverflow.com/questions/12774207/fastest-way-to-check-if-a-file-exist-using-standard-c-c11-c
 * This function checks if a file named hs.dat exists or not
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
		fp = fopen("hs.dat", "w+"); // create hs.dat if it doesn't exist
		fprintf(fp, "0");
	}
	else
	{
		fp = fopen("hs.dat", "r+");
		fscanf(fp, "%d", &highscore); // read the highscore from the file
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

/**
 * Write the highscore to hs.dat file
 */
void HighScoreDb::writeToDisk()
{
	rewind(fp); // move to the start of the file
	fprintf(fp, "%d", highscore);
}

/**
 * Close the file pointer
 */
HighScoreDb::~HighScoreDb()
{
	fclose(fp);
}