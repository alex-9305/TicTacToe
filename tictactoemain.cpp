#include "tictactoemain.h"

using namespace std;

int main()
{
	//Variablen
	char firstLine[3] = {'N', 'N', 'N'};	//Zeile1
	char secondLine[3] = {'N', 'N', 'N'};	//Zeile2
	char thirdLine[3] = {'N', 'N', 'N'};	//Zeile3
	bool endCondition = false;	//Weist auf Ende des Spiels hin
	unsigned int playerTurn = 0;	//Welcher Spieler ist dran?
	unsigned int countToEnd = 0;	//Spiel beenden, wenn alle Felder belegt sind
	int endProgram = 0;	//Programm ganz schließen.

	while ((endCondition == false) && (countToEnd < 9)){
		createField(firstLine, secondLine, thirdLine);
		changeField(playerTurn, firstLine, secondLine, thirdLine);
		endCondition = checkEnd(playerTurn, firstLine, secondLine, thirdLine);
		playerTurn = togglePlayer(playerTurn);
		countToEnd = countToEnd + 1;
	}
	createField(firstLine, secondLine, thirdLine);
	if (endCondition == false){
		cout << "Leider beide verloren ;((" << endl;
	}
	else{
		playerTurn = togglePlayer(playerTurn);
		cout << "Glückwunsch Spieler " << (playerTurn + 1) << ", du bist ein wahrer Gewinner :)" << endl;
	}
	
	return 0;
}