
#include <iostream>
using namespace std;
// X O Game


void DrwaBoard(char board[3][3])
{
	int hieght = 4;
	int width = 12;

	for (int i = 0; i < hieght; i++)
	{
		int x = i - 1;
		int y = -1;
		for (int j = 0; j <= width; j++)
		{
			if (i == 0)
				cout << "_";
			else
			{
				if (j % 4 == 0)
				{
					cout << "|";
					y++;
				}
				else if (board[x][y] != ' ' && (j == 2 || j == 6 || j == 10))
					cout << board[x][y];
				else
					cout << "_";
			}
		}
		cout << endl;
	}
}
void ClearBoard(char board[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}
}
char CheckWinner(char board[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])   //check rwos
			return board[i][0];

		if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])    // chech cols
			return board[0][i];
	}
	if ((board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
		(board[0][2] != ' ' && board[2][0] == board[1][1] && board[1][1] == board[0][2]))
		return  board[1][1];
	return ' ';
}
bool WhoIsWinner(char board[3][3])
{
	char Winner = CheckWinner(board);
	if (Winner == 'X')
	{
		cout << "\n\t\tX is winner \n";
		system("color 2F");
		return true;
	}
	else if (Winner == 'O')
	{
		cout << "\n\t\tO is winner \n";
		system("color 2F");
		return true;
	}
	return false;
}
void Game()
{
	char board[3][3];
	ClearBoard(board);
	DrwaBoard(board);
	int Choices = 0;
	bool IsX = true;
	while (Choices < 9)
	{
		int x, y;
		cout << "Please enter X and Y for your location: ";
		cin >> x >> y;
		while (board[x][y] != ' ')
		{
			cout << "Location is not empty! Please try to input again: ";
			cin >> x >> y;
		}
		if (IsX)
			board[x][y] = 'X';
		else
			board[x][y] = 'O';
		IsX = !IsX;
		DrwaBoard(board);
		if (WhoIsWinner(board))
			return;
		Choices++;
	}
	cout << "\n\n\t\tGame Over!" << endl;
	system("color 4F");
	cout << "\a";
}



int main()
{
	Game();
	return 0;
}



