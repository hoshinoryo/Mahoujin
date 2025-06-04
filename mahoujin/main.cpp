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

	int column = start_column; //�������܂鎞�̗�
	int row = 0; //�������܂鎞�̍s
	char c;

	std::cout << "Enter���������Ƃɐ��l�����܂��Ă����܂��B\n";

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
	//��̘g
	std::cout << "������";
	for (int x = 1; x < MAHOUJIN_SIZE; x++) 
	{
		std::cout << "������";
	}
	std::cout << "��" << std::endl;

	//�����̊Ԃŕ����Ă�g
	for (int y = 0; y < MAHOUJIN_SIZE; y++) 
	{
		std::cout << "��";
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
			std::cout << "��";
		}
		std::cout << std::endl;

		if (y == MAHOUJIN_SIZE - 1) 
			break;

		std::cout << "������";
		for (int x = 1; x < MAHOUJIN_SIZE; x++) {
			std::cout << "������";
		}
		std::cout << "��\n";
	}

	//�g�̉�
	std::cout << "������";
	for (int x = 1; x < MAHOUJIN_SIZE; x++) {
		std::cout << "������";
	}
	std::cout << "��" << std::endl;
}