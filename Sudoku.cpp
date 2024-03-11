#include<iostream>
#include<fstream>
#include<Windows.h>
#include <string>

using namespace std;

void initializer(int arr[9][9], int narr[9][9], bool yarr[9][9]);
void load(int arr[9][9], int narr[9][9], bool yarr[9][9], int p, char c, int x, int y);
void check(int arr[9][9], int i, int j, int v, int w, int y, int& a);
void save(int arr[9][9], int narr[9][9], bool yarr[9][9]);
void random(int arr[9][9], bool yarr[9][9]);
void print(int arr[9][9], int narr[9][9], bool yarr[9][9]);
void converter(int arr[9][9], int narr[9][9]);
void setCord(int x, int y);
void usesetCord(int x, int y);
void dataentry(int arr[9][9], int narr[9][9], bool yarr[9][9], int x, int y, char c, int p);
void mainmenu(int arr[9][9], int narr[9][9], bool yarr[9][9]);

int main()
{
	srand(time(NULL));
	char c = 'a';
	int p = 88;
	const int a = 9;
	const int b = 9;
	int x = 0;
	int y = 0;
	int arr[a][b];
	int narr[a][b];
	bool yarr[a][b];
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 13);
	cout << "Press S to start the game." << endl;
	SetConsoleTextAttribute(h, 2);
	cout << "Press L to load the game." << endl;
	SetConsoleTextAttribute(h, 3);
	cout << "Press Q to quit the game." << endl;
	cin >> c;
	system("CLS");

	if ((c == 'L') || (c == 'l'))
	{
		initializer(arr, narr, yarr);
		load(arr, narr, yarr, p, c, x, y);
	}
	if ((c == 'Q') || (c == 'q'))
	{
		exit(0);
	}
	if ((c == 'S') || (c == 's'))
	{
		initializer(arr, narr, yarr);
		SetConsoleTextAttribute(h, 3);
		cout << "------------INSTRUCTIONS------------" << endl;
		SetConsoleTextAttribute(h, 4);
		cout << endl;
		cout << "-->You are not able to edit in the filled boxes. " << endl;
		SetConsoleTextAttribute(h, 5);
		cout << "-->The game should not allow the player to repeat any number in any row, column, or square." << endl;
		SetConsoleTextAttribute(h, 6);
		cout << "-->If the player fills all the boxes with correct numbers and without any repetition he wins the game." << endl;
		Sleep(3000);
		system("CLS");
		srand(time(NULL));
		random(arr, yarr);
		converter(arr, narr);
		setCord(x, y);
		print(arr, narr, yarr);
		SetConsoleTextAttribute(h, 13);
		usesetCord(x, y);
		SetConsoleTextAttribute(h, 3);
		dataentry(arr, narr, yarr, x, y, c, p);
		save(arr, narr, yarr);
	}
}
void initializer(int arr[9][9], int narr[9][9], bool yarr[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			arr[i][j] = 0;
			narr[i][j] = 0;
			yarr[i][j] = 0;
		}
	}
}
void random(int arr[9][9], bool yarr[9][9])
{
	int a = 0;
	int y = 0;
	int v = 9;
	int w = 9;
	int k = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i == 8 && j == 8)
			{
				k = 1;
				break;
			}
			if (rand() % 2 == 1)
			{
				{
					y = rand() % 9 + 1;

					for (int e = 0; e < 9; e++)
					{
						check(arr, i, j, v, w, y, a);
						while ((a == 1) || (y == arr[e][j]) || (y == arr[i][e]))
						{
							y = rand() % 9 + 1;
							e = -1;
							check(arr, i, j, v, w, y, a);
						}
					}
					arr[i][j] = y;
					yarr[i][j] = 1;
				}
				if (k == 1)
				{
					break;
				}
			}
			else
			{
				arr[i][j] = 0;
				yarr[i][j] = 0;
			}
		}
	}
}
void print(int arr[9][9], int narr[9][9], bool yarr[9][9])
{
	int m;

	HANDLE j = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int k = 0; k < 34; k++)
	{
		cout << "-";
	}
	cout << endl;
	int count = 0;
	int x = 0;

	for (int h = 0; h < 9; h++)
	{
		for (int i = 0; i < 9; i++)
		{
			if (yarr[h][i])
			{
				SetConsoleTextAttribute(j, 10);
				cout << " " << narr[h][i] << "  ";
			}
			else
			{
				SetConsoleTextAttribute(j, 12);
				cout << " " << arr[h][i] << "  ";
			}

			count++;
			if (count % 9 == 0)
			{
				cout << endl;
			}
			if (count % 27 == 0)
			{
				cout << endl;
			}
		}
	}
}

void setCord(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void usesetCord(int x, int y)
{
	for (y = 4; y < 10; y += 4)
	{
		for (x = 0; x < 34; x++)
		{
			setCord(x, y);
			cout << "_";
		}
	}
	for (x = 11; x < 33; x += 11)
	{
		for (y = 1; y < 12; y++)
		{
			setCord(x, y);
			cout << "|";
		}
	}
	cout << endl;
	for (int k = 0; k < 34; k++)
	{
		cout << "-";
	}
}
void dataentry(int arr[9][9], int narr[9][9], bool yarr[9][9], int x, int y, char c, int p)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	//	load(arr, narr, p, c, x, y);
	char g = 'A';
	bool flag = true;
	while (flag == true)
	{
		int count = 0;
		bool status = false;
		int n;
		int r = -1;
		while (r < 0 || r > 8 || cin.fail())
		{
			SetConsoleTextAttribute(h, 3);
			cout << endl;
			cout << "Enter the row number in which you want to want to enter data : ";
			cin >> r;
			if (r < 0 || r > 8)
			{
				SetConsoleTextAttribute(h, 1);
				cout << endl;
				cout << "Invalid row number...." << endl;
			}
			if (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << endl;
				cout << "please enter a integer" << endl;
				cin >> r;
			}

		}
		int c = -1;
		while (c < 0 || c > 8 || cin.fail())
		{
			SetConsoleTextAttribute(h, 4);
			cout << endl;
			cout << "Enter the column number in which you want to want to enter data : ";
			cin >> c;
			if (c < 0 || c > 8)
			{
				SetConsoleTextAttribute(h, 5);
				cout << endl;
				cout << "Invalid column number...." << endl;
			}
			if (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << endl;
				cout << "please enter a integer" << endl;
				cin >> c;
			}
		}

		int u = 0;
		for (int i = 0; i < 9; i++)
		{
			if (arr[r][c] == i)
			{
				u = 1;
				break;
			}
		}
		if (u == 0)
		{
			arr[r][c] = 0;
		}
		if (yarr[r][c])
		{
			SetConsoleTextAttribute(h, 1);
			cout << "You can't change this number." << endl;
			Sleep(1500);
		}
		else if (status == false)
		{
			SetConsoleTextAttribute(h, 2);
			cout << "Enter the value: " << endl;
			cin >> n;
			while (n > 9 || n < 1 || cin.fail())
			{
				SetConsoleTextAttribute(h, 4);
				if (n > 9 || n < 1)
				{
					cout << "The value entered in not in the range between 1 to 9." << endl;
					cout << "Enter value again.." << endl;
					cin >> n;
				}
				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << endl;
					cout << "please enter a integer" << endl;
					cin >> n;
				}
			}
			int s = 0;
			for (int i = 0; i < 9; i++)
			{
				if (narr[r][i] == n)
				{
					SetConsoleTextAttribute(h, 1);
					cout << "You can't use this number at this coordinate.." << endl;
					Sleep(1500);
					s = 1;
					break;
				}
				if (narr[i][c] == n)
				{
					SetConsoleTextAttribute(h, 2);
					cout << "You can't use this number at this coordinate.." << endl;
					Sleep(1500);
					s = 1;
					break;
				}
				int y = 0;
				int z = 0;
				if (r > -1 && r < 3)
				{
					y = 0;
				}
				if (r > 2 && r < 6)
				{
					y = 3;
				}
				if (r > 5 && r < 9)
				{
					y = 6;
				}
				if (c > -1 && c < 3)
				{
					z = 0;
				}
				if (c > 2 && c < 6)
				{
					z = 3;
				}
				if (c > 5 && c < 9)
				{
					z = 6;
				}
				{
					for (int i = y; i < y + 3; i++)
					{
						for (int j = z; j < z + 3; j++)
						{
							if (narr[i][j] == n)
							{
								cout << "You can't use this number at this coordinate.." << endl;
								Sleep(1500);
								s = 1;
								break;
							}
							if (s == 1)
							{
								break;
							}
						}
						if (s == 1)
						{
							break;
						}
					}
				}

			}
			if (s == 0)
			{
				//narr[r][c] = n;
				arr[r][c] = n;
				mainmenu(arr, narr, yarr);
			}
		}
		for (int x = 0; x < 9; x++)
		{
			for (int y = 0; y < 9; y++)
			{
				if ((arr[x][y] == 0) || (narr[x][y] == 0))
				{
					status = false;
				}
			}
		}
		cout << endl;
		system("CLS");
		print(arr, narr, yarr);
		usesetCord(x, y);
		if (status == true)
		{
			cout << "....YOU HAVE WON THE GAME....";
			exit(0);
		}
	}
}
void converter(int arr[9][9], int narr[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			narr[i][j] = arr[i][j];
		}
	}
}


void check(int arr[9][9], int i, int j, int v, int w, int y, int& a)
{
	a = 0;
	int r = 0;
	int t = 99;
	int b = 99;
	if (i > -1 && i < 3)
	{
		t = 0;
		v = 3;
	}
	if (i > 2 && i < 6)
	{
		t = 3;
		v = 6;
	}
	if (i > 5 && i < 9)
	{
		t = 6;
		v = 9;
	}
	if (j > -1 && j < 3)
	{
		b = 0;
		w = 3;
	}
	if (j > 2 && j < 6)
	{
		b = 3;
		w = 6;
	}
	if (j > 5 && j < 9)
	{
		b = 6;
		w = 9;
	}
	for (int g = t; g < v; g++)
	{
		for (int h = b; h < w; h++)
		{
			if (y == arr[g][h])
			{
				a = 1;
			}
		}
	}
	if (a != 1)
	{
		a = 0;
	}
}

void save(int arr[9][9], int narr[9][9], bool yarr[9][9])
{
	int s = 0;
	char save = 'a';
	cout << "Do you want to save data....if yes Press (Y)....else Press (N) :" << endl;
	cin >> save;
	if ((save == 'N') || (save == 'n'))
	{
		return;
	}
	if ((save == 'Y') || (save == 'y'))
	{
		ofstream fw;
		cout << "Press 1 to save in file one." << endl;
		cout << "Press 2 to save in file two." << endl;
		cout << "Press 3 to save in file three." << endl;
		cin >> s;
		if (s == 1)
		{
			fw.open("file1.txt");
			fstream fw("file1.txt");
			print(arr, narr, yarr);
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (yarr[i][j])
						fw << narr[i][j];
					else
						fw << arr[i][j];
				}
			}
			fw << endl;
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					fw << yarr[i][j];
				}
			}
			fw.close();
		}
		if (s == 2)
		{
			fw.open("file2.txt");
			fstream fw("file2.txt");
			print(arr, narr, yarr);
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (yarr[i][j])
						fw << narr[i][j];
					else
						fw << arr[i][j];
				}
			}
			fw << endl;
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					fw << yarr[i][j];
				}
			}
			fw.close();
		}
		if (s == 3)
		{
			fw.open("file3.txt");
			fstream fw("file3.txt");
			print(arr, narr, yarr);
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (yarr[i][j])
						fw << narr[i][j];
					else
						fw << arr[i][j];
				}
			}
			fw << endl;
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					fw << yarr[i][j];
				}
			}
			fw.close();
		}
	}
}

void load(int arr[9][9], int narr[9][9], bool yarr[9][9], int p, char c, int x, int y)
{

	fstream fw;
	if ((c == 'L') || (c == 'l'))
	{
		cout << "Press 1 for file one." << endl;
		cout << "Press 2 for file two." << endl;
		cout << "Press 3 for file three." << endl;
		cin >> p;
		system("CLS");
		if (p == 1)
		{
			int count = 0;
			fw.open("file1.txt");
			if (fw.is_open())
			{
				string tp;
				while (getline(fw, tp))
				{
					if (count == 0)
					{
						count = 1;
						int v = 0;
						for (int i = 0; i < 9; i++)
						{
							for (int j = 0; j < 9; j++)
							{
								arr[i][j] = int(tp[v]) - 48;
								v++;
							}
						}
					}
					else
					{
						int v = 0;
						for (int i = 0; i < 9; i++)
						{
							for (int j = 0; j < 9; j++)
							{
								yarr[i][j] = int(tp[v]) - 48;
								if (yarr[i][j])
								{
									narr[i][j] = arr[i][j];
									arr[i][j] = 0;
								}
								v++;
							}
						}
					}
				}
			}
			print(arr, narr, yarr);
			usesetCord(x, y);
			dataentry(arr, narr, yarr, x, y, c, p);
			fw.close();
		}
		if (p == 2)
		{
			int count = 0;
			fw.open("file2.txt");
			if (fw.is_open())
			{
				string tp;
				while (getline(fw, tp))
				{
					if (count == 0)
					{
						count = 1;
						int v = 0;
						for (int i = 0; i < 9; i++)
						{
							for (int j = 0; j < 9; j++)
							{
								arr[i][j] = int(tp[v]) - 48;
								v++;
							}
						}
					}
					else
					{
						int v = 0;
						for (int i = 0; i < 9; i++)
						{
							for (int j = 0; j < 9; j++)
							{
								yarr[i][j] = int(tp[v]) - 48;
								if (yarr[i][j])
								{
									narr[i][j] = arr[i][j];
									arr[i][j] = 0;
								}
								v++;
							}
						}
					}
				}
			}
			print(arr, narr, yarr);
			usesetCord(x, y);
			dataentry(arr, narr, yarr, x, y, c, p);
			fw.close();
		}
		if (p == 3)
		{
			int count = 0;
			fw.open("file3.txt");
			if (fw.is_open())
			{
				string tp;
				while (getline(fw, tp))
				{
					if (count == 0)
					{
						count = 1;
						int v = 0;
						for (int i = 0; i < 9; i++)
						{
							for (int j = 0; j < 9; j++)
							{
								arr[i][j] = int(tp[v]) - 48;
								v++;
							}
						}
					}
					else
					{
						int v = 0;
						for (int i = 0; i < 9; i++)
						{
							for (int j = 0; j < 9; j++)
							{
								yarr[i][j] = int(tp[v]) - 48;
								if (yarr[i][j])
								{
									narr[i][j] = arr[i][j];
									arr[i][j] = 0;
								}
								v++;
							}
						}
					}
				}
			}
			print(arr, narr, yarr);
			usesetCord(x, y);
			dataentry(arr, narr, yarr, x, y, c, p);
			fw.close();
		}
	}
}

void mainmenu(int arr[9][9], int narr[9][9], bool yarr[9][9])
{
	char mm;
	system("CLS");
	cout << "Press S to save.." << endl;
	cout << "Press E to exit.." << endl;
	cout << "Press any other key to continue.." << endl;
	cin >> mm;
	if ((mm == 'S') || (mm == 's'))
	{
		save(arr, narr, yarr);
	}
	else if ((mm == 'E') || (mm == 'e'))
	{
		exit(0);
	}
	else
	{
		cin.clear();
		cin.ignore();
	}
}