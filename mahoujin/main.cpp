#include <iostream>
#include <iomanip>

constexpr int MAHOUJIN_SIZE = 5;
constexpr int MAHOUJIN_NUM_COUNT = MAHOUJIN_SIZE * MAHOUJIN_SIZE;

void DispMahoujin(int Mahoujin[MAHOUJIN_SIZE][MAHOUJIN_SIZE]);


int main()
{
	int Mahoujin[MAHOUJIN_SIZE][MAHOUJIN_SIZE] = {};
	int* pMahoujin = &Mahoujin[0][0];

	int start_column = MAHOUJIN_SIZE / 2;

	int column = start_column; //êîÇ™ñÑÇ‹ÇÈéûÇÃóÒ
	int row = 0; //êîÇ™ñÑÇ‹ÇÈéûÇÃçs
	char c;

	std::cout << "EnterÇâüÇ∑Ç≤Ç∆Ç…êîílÇ™ñÑÇ‹Ç¡ÇƒÇ¢Ç´Ç‹Ç∑ÅB\n";

	Mahoujin[row][column] = 1;

	for (int n = 2; n <= MAHOUJIN_NUM_COUNT; n++)
	{
		DispMahoujin(Mahoujin);

		row--, column++;
		if (row >= 0 && row <= MAHOUJIN_SIZE - 1 && column >= 0 && column <= MAHOUJIN_SIZE - 1)
		{
			if (Mahoujin[row][column] != 0)
			{
				row += 2, column--;
			}
		}
		else if (row < 0 || column > MAHOUJIN_SIZE - 1)
		{
			if (row < 0 && column <= MAHOUJIN_SIZE - 1)
			{
				row += MAHOUJIN_SIZE;
			}
			else if (row >= 0 && column > MAHOUJIN_SIZE - 1)
			{
				column -= MAHOUJIN_SIZE;
			}
			else if (row < 0 && column > MAHOUJIN_SIZE - 1)
			{
				row += 2, column--;
			}
		}
		Mahoujin[row][column] = n;

		std::cin.get(c);
		if (c == '\n')
		{
			continue;
		}
	}

	DispMahoujin(Mahoujin);

	return 0;
}

void DispMahoujin(int Mahoujin[MAHOUJIN_SIZE][MAHOUJIN_SIZE])
{
	//è„ÇÃòg
	std::cout << "Ñ°ÑüÑü";
	for (int x = 1; x < MAHOUJIN_SIZE; x++) 
	{
		std::cout << "Ñ¶ÑüÑü";
	}
	std::cout << "Ñ¢" << std::endl;

	//êîéöÇÃä‘Ç≈ï™ÇØÇƒÇÈòg
	for (int y = 0; y < MAHOUJIN_SIZE; y++) 
	{
		std::cout << "Ñ†";
		for (int x = 0; x < MAHOUJIN_SIZE; x++) 
		{
			std::cout << std::setw(2);
			if (Mahoujin[y][x]) 
			{
				std::cout << Mahoujin[y][x];
			}
			else 
			{
				std::cout << " ";
			}
			std::cout << "Ñ†";
		}
		std::cout << std::endl;

		if (y == MAHOUJIN_SIZE - 1) 
			break;

		std::cout << "Ñ•ÑüÑü";
		for (int x = 1; x < MAHOUJIN_SIZE; x++) {
			std::cout << "Ñ©ÑüÑü";
		}
		std::cout << "Ñß\n";
	}

	//ògÇÃâ∫
	std::cout << "Ñ§ÑüÑü";
	for (int x = 1; x < MAHOUJIN_SIZE; x++) {
		std::cout << "Ñ®ÑüÑü";
	}
	std::cout << "Ñ£" << std::endl;
}