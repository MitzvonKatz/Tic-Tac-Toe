#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>


// globale Variable, auserhalb von funktion. Feld definieren

char field[10];

void multiplayer();
void help();
bool checkFull(char);
bool checkWin(char);
char keyinput(bool X);


//hilfsfunktion, konsole bereinigen
void clearConsole()
{
	system("cls");
}
//feld in grundyustand bringen

void resetField()
{
	for (int i = 0; i < 10; i++)
	{
	field[i] = ' ';
	}
}


void menu() 
{
	while (true)
	{
		resetField();
		char inputmenu;
		printf("\n\n");
		printf("MENU\n\n");
		printf("1: Multiplayer\n");
		printf("2: Help\n");
		printf("3:Quit\n\n\n");
		printf("Input: ");
		printf(inputmenu);

		
		if (inputmenu == '1')multiplayer();
		else if (inputmenu == '2')help();
		else if (inputmenu == '3' || inputmenu == 'q')return;
		else { clearConsole();  printf("\nInvalid Input"); }
	}
}


void Field();
{
	clearConsole();
	scanf("\n\n\n");
	scanf("	  " << field[1] << " | " << field[2] << " | " << field[3] << endl);
	scanf("	 ---|---|---" << endl);
	scanf("     " << field[4] << " | " << field[5] << " | " << field[6] << endl);
	scanf("	 ---|---|---" << endl);
	scanf("     " << field[7] << " | " << field[8] << " | " << field[9] << endl);
}

//funktionen
void multiplayer()
{
	char input = ' ';
	bool player1Turn = true; //player1 beginnt, deshalb true
	while (true)
	{
		Field();
		if (checkWin('X'))
		{
			scanf("\nPlayer1 has won\n\n");
			return;
		}
		else if (checkWin('O'))
		{
			scanf("\n Player2 has won\n\n");
			return;
		}
		if (checkFull())
		{
			scanf("Tie\n\n");
		}
		input = keyInput(player1Turn);
		if (input == 'q')
		{
			return;
		}
		player1Turn = !player1Turn;
	}
}

void help()
{
	clearConsole();
	scanf_s("\n\n\nHELP\n\nSingleplayer:\nIn Singleplayermode you play against the Computer\n\nMultiplayer:\nIn Multiplayermode you play against a second player. Input switches between X and O. You can also play this mode if you want to test new tactics or just want to play against yourself.\n\nControls:\nTo choose a field you must enter a number between 1 and 9. The first field is in the top left. the second right next to it etc.\n\n");
	return;
}


char keyinput(bool X)
{
	while (true)
	{
		scanf_s("\n\nInput:");
		char input = ' ';
		printf(input);
		int inputNumber = input - '0';//zu int konvertieren
		if (inputNumber > 9 || input < 1)
		{
			if (input == 'q')
				return input;
			else
				scanf_s("\nInvalid Input!");
		}
		else if (field[inputNumber] != ' ')
		{
			scanf_s("\nThis field is already used");
		}
		else
		{
			if (X)
				field[inputNumber] = 'X';
			else 
				field[inputNumber] = 'O';
				return input;
		}
	}
}

bool checkWin(char sign)
{
	if (field[1] == sign && field[2] == sign && field[3] == sign || field[1] == sign && field[4] == sign && field[7] == sign || field[1] == sign && field[5] == sign && field[9] == sign || field[2] == sign && field[5] == sign && field[8] == sign || field[3] == sign && field[6] == sign && field[9] == sign || field[3] == sign && field[5] == sign && field[7] == sign || field[4] == sign && field[5] == sign && field[6] == sign || field[7] == sign && field[8] == sign && field[9] == sign)
	{
		return true;
	}
	return false;
}
	

bool checkFull()
{
	for (int i = 1; i <= 9; i++)
	{
		if (field[i] == ' ')
		{
			return false;
		}
	}
	return true;
}

int main() {
	
	menu();


	return 0;

}


