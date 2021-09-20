CS101 Project for AA grade
==========================

--------------------------------------------------------------------------------------------------
| Video Link: https://drive.google.com/file/d/1uSstKowdSxNZSMrUS9_bOQuHIFtXXGnC/view?usp=sharing |
__________________________________________________________________________________________________

-----------------------------------------------------
| INCASE OF ANY DOUBTS CALL/WHATSAPP +91 7038108569 |
-----------------------------------------------------

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
| Name   : Ved Mangesh Khandekar |
| LDAP ID: 20d170019             |
| Phone  : 7038108569            |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


TOTAL NUMBER OF LINES ADDED: 391 (Excluding comments)
How to check:
1. Run git log --stat --oneline
2. Add the number of insertions reported for all commits except that of the first one (i.e. ccc6b35)


How To Compile:
---------------
1. On Linux:
   1) Unzip lasso_zip.zip
   2) cd to lasso_zip/lasso/ folder.
   *************************************************************************************************
   * 3) Open the Makefile and modify the path "CC=" to point to the s++ bash script. <-- IMPORTANT *
   *************************************************************************************************
   4) Run "make"
   5) Run the executable by ./lasso


Features Added:
---------------
1. High Score Tracking
   A file called hs.dat stores and updates the high score.
   This is acheived in an OOP manner using the HighScoreDb class in HighScoreDb.cpp.

2. Health System
   The player has three chances to throw the lasso, if the player misses the coin, a life is lost.

3. Poisonous coins
   Collecting red coins leads to decrease in health.
   The program randomly decides using rand() function when to make a coin poisonous.


How to play:
------------
1. Use 't' to throw the lasso.
2. Use 'l' to loop the coin.
3. Use 'y' to pull back the lasso, note that if you collect a poisonous and yank, you WILL lose a life.
4. Use 'q' to quit.
5. ENJOY! ;-)


Other Changes:
--------------
1. The default lasso radius has been increased to make it more easy to play the game.
2. This project uses the git SCM.
3. Using "make" this project can be compiled very easily.
