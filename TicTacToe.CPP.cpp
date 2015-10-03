#include <iostream>

using namespace std;

void print_table();
void check_win();
void start();

char*  _table = new char[9];
int    _player;

const char PLAYER_CHAR[2] = { 'X', 'O' };
const int WIN_IDX[9][3] = { { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 }, { 0, 3, 6 }, { 1, 4, 7 }, { 2, 5, 8 }, { 2, 4, 6 }, { 0, 4, 8 } };

int main(int argc, char *argv[])
{
	start();

	do
	{
		print_table();
		cout << endl << "Vez do jogador " << (_player + 1) << " [" << PLAYER_CHAR[_player] << "] ";
		cout << endl << "Digite uma posicao de 1 a 9: ";

		int in;
		bool inv;

		do
		{
			cin >> in;
			inv = (in > 9 || in < 1) || _table[in - 1] != ' ';
			if (inv) cout << "Posicao ocupada ou invalida! Digite outra." << endl;
		} while (inv);

		_table[in - 1] = PLAYER_CHAR[_player];
		_player = _player == 1 ? 0 : 1;

		check_win();
	} while (true);

	delete[] _table;
	return 0;
}

void check_win()
{
	for (int i = 0; i < 8; i++)
	{
		for (int p = 0; p <= 1; p++)
		{
			int p1 = WIN_IDX[i][0], p2 = WIN_IDX[i][1], p3 = WIN_IDX[i][2];

			if (_table[p1] == PLAYER_CHAR[p] && _table[p2] == PLAYER_CHAR[p] && _table[p3] == PLAYER_CHAR[p])
			{
				for (int j = 0; j < 9; j++)
				{
					char c = (j == p1 || j == p2 || j == p3) ? PLAYER_CHAR[p] : ' ';
					*(_table + j) = c;
				}

				print_table();

				cout << endl << "Jogador " << (p + 1) << " [" << PLAYER_CHAR[p] << "] " << "venceu!!!" << endl << endl;
				cout << "Deseja reiniciar? S ou N." << endl;

				char ans;
				cin >> ans;

				if (toupper(ans) == 'S')
				{
					start();
					main(0, 0);
				}
				else
				{
					exit(0);
				}
			}
		}
	}
}

void start()
{
	_player = 0;
	for (int i = 0; i < 9; i++)
	{
		*(_table + i) = ' ';
	}
}

void print_table()
{
	system("cls");
	cout << "Joguin da velha by leozin" << endl << endl;

	for (int i = 0; i < 9; i++)
	{
		const char* s = i % 3 == 2 ? "\n" : "";

		cout << "[" << _table[i] << "]" << s;
	}
}
