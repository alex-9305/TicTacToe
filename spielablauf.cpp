#include "spielablauf.h"

using namespace std;

//Erstellt das Spielfeld zu Beginn und nach jedem Zug
void createField(char firstLine[3], char secondLine[3], char thirdLine[3]){
	cout << endl;
	cout << "---|-----" << firstLine[0] << "---|-----" << firstLine[1] << "---|-----" << firstLine[2]  << "-----|--" << endl;
	cout << "---|-----" << secondLine[0] << "---|-----" << secondLine[1] << "---|-----" << secondLine[2]  << "-----|--" << endl;
	cout << "---|-----" << thirdLine[0] << "---|-----" << thirdLine[1] << "---|-----" << thirdLine[2]  << "-----|--" << endl;
}

//Verändert nach jedem Zug das Spielfeld. Spieler 1 = X, Spieler 2 = O
void changeField(unsigned int playerTurn, char firstLine[3], char secondLine[3], char thirdLine[3]){
	int row = 0;		//Speichern der Zeile
	int column = 0;	//Speichern der Spalte
	int error = 0;		//Weist auf fehlerhafte Eingabe hin
	int overwrite = 0;	//Weist auf Overwrite hin
	char symbol = 'N';	//Symbol des aktuellen Spielers

	if (playerTurn == 0){
		cout << endl;
		cout << "Spieler 1 ist an der Reihe" << endl;
		symbol = 'X';
	}
	else{
		cout << endl;
		cout << "Spieler 2 ist an der Reihe" << endl;
		symbol = 'O';
	}
	//Ausgabe und Einlesen für Spielablauf
	cout << "Reihe: ";
	cin >> row;
	cout << endl;
	cout << "Spalte: ";
	cin >> column;
	cout << endl;

	//Fehlerhafte Eingabe prüfen
	error = checkInput(row, column);
	while(error == 1){
		cout << "Eingabe ungültig. Bitte wiederholen, du Idiot." << endl;
		cout << "Reihe: ";
		cin >> row;
		cout << endl;
		cout << "Spalte: ";
		cin >> column;
		cout << endl;
		error = checkInput(row, column);
	}
	
	//Überschreiben überprüfen
	overwrite = checkOverwrite(row, column, firstLine, secondLine, thirdLine);
	while(overwrite == 1){
		cout << "Feld ist schon belegt. Eingabe wiederholen." << endl;
		cout << "Reihe: ";
		cin >> row;
		cout << endl;
		cout << "Spalte: ";
		cin >> column;
		cout << endl;
		overwrite = checkOverwrite(row, column, firstLine, secondLine, thirdLine);
	}
	//Spielzug einfügen
	switch (row)
	{
		case 1:
			firstLine[(column - 1)] = symbol;
			break;
		case 2:
			secondLine[(column - 1)] = symbol;
			break;
		case 3:
			thirdLine[(column - 1)] = symbol;
			break;
		default:
			error = 1;
		break;			
	}
		
}

//Toggelt nach jedem Zug den Spieler
unsigned int togglePlayer(unsigned int playerTurn){
	if (playerTurn == 0){
		return 1;
	}
	else{
		return 0;
	}
}

//Checkt falsche Eingaben und schon bespielte Felder und Spielende
//Output: 0 = kein Error, 1 = Eingabe wiederholen
int checkInput(int row, int column){
	int checkForError = 0;	//Falsche Eingabe prüfen
	if( ((row >= 1) && (row <= 3)) && ((column >= 1) && (column <= 3)) ){
		return 0;
	}
	else{
		return 1;
	}
}

//Enthält Spiellogik
bool checkEnd(unsigned int playerTurn, char firstLine[3], char secondLine[3], char thirdLine[3]){
	//Zeilensiege
	//Zeile 1 (geprüft)
	if ((firstLine[0] == firstLine[1]) && (firstLine[0] == firstLine[2]) && (firstLine[0] != 'N')){
		return true;
	}
	//Zeile 2 (geprüft)
	else if((secondLine[0] == secondLine[1]) && (secondLine[0] == secondLine[2]) && (secondLine[0] != 'N')){
		return true;
	}
	//Zeile 3 (geprüft)
	else if((thirdLine[0] == thirdLine[1]) && (thirdLine[0] == thirdLine[2]) && (thirdLine[0] != 'N')){
		return true;
	}

	//Spaltensiege
	//Spalte 1 (geprüft)
	else if((firstLine[0] == secondLine[0]) && (firstLine[0] == thirdLine[0]) && (firstLine[0] != 'N')){
		return true;
	}
	//Spalte 2 (geprüft)
	else if((firstLine[1] == secondLine[1]) && (firstLine[1] == thirdLine[1]) && (firstLine[1] != 'N')){
		return true;
	}
	//Spalte 3 (geprüft)
	else if((firstLine[2] == secondLine[2]) && (firstLine[2] == thirdLine[2]) && (firstLine[2] != 'N')){
		return true;
	}

	//Diagonalsiege
	//Oben links nach unten rechts (geprüft)
	else if((firstLine[0] == secondLine[1]) && (firstLine[0] == thirdLine[2]) && (firstLine[0] != 'N')){
		return true;
	}
	//Oben rechts nach unten links (geprüft)
		else if((firstLine[2] == secondLine[1]) && (firstLine[2] == thirdLine[0]) && (firstLine[2] != 'N')){
		return true;
	}
	
	else{
		return false;
	}
}

//Verhindert überschreiben. 1 = Fehler
int checkOverwrite(int row, int column, char firstLine[3], char secondLine[3], char thirdLine[3]){
	switch (row)
	{
		case 1:
			if (firstLine[(column - 1)] != 'N'){
				return 1;
			}	
			else{
				return 0;
			}
			break;
		case 2:
			if (secondLine[(column - 1)] != 'N'){
				return 1;
			}	
			else{
				return 0;
			}
			break;
		case 3:
			if (thirdLine[(column - 1)] != 'N'){
				return 1;
			}	
			else{
				return 0;
			}
			break;
		default:
			return 1;
			break;			
	}
}



