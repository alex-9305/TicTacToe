#ifndef spielablauf_h
#define spielablauf_h

//includes
#include <iostream>
#include <string>

//Deklarationen
void createField(char firstLine[3], char secondLine[3], char thirdLine[3]);
void changeField(unsigned int playerTurn, char firstLine[3], char secondLine[3], char thirdLine[3]);
unsigned int togglePlayer(unsigned int playerTurn);
int checkInput(int row, int column);
bool checkEnd(unsigned int playerTurn, char firstLine[3], char secondLine[3], char thirdLine[3]);
int checkOverwrite(int row, int column, char firstLine[3], char secondLine[3], char thirdLine[3]);

#endif 

