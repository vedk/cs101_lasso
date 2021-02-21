CC=~/Downloads/simplecpp/s++

lasso: MovingObject.o coin.o lasso.o main.o HighScoreDb.o
	$(CC) -o lasso main.o lasso.o coin.o MovingObject.o HighScoreDb.o

MovingObject.o: MovingObject.cpp
	$(CC) -c MovingObject.cpp

lasso.o: lasso.cpp
	$(CC) -c lasso.cpp

coin.o: coin.cpp
	$(CC) -c coin.cpp

HighScoreDb.o: HighScoreDb.cpp
	$(CC) -c HighScoreDb.cpp

main.o: main.cpp
	$(CC) -c main.cpp

.PHONY: clean

clean:
	rm *.o lasso
