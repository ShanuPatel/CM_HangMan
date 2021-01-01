// CM_HangMan.cpp : Defines the entry point for the application.
//

#include "CM_HangMan.h"
#include "GLFW/glfw3.h"
#include <ctime>
#include <fstream>

void HangMan::Pattern()
{
	char input{};
	int lives = 5;
	std::cout << "_____________________   " << '\n';
	std::cout << "|________}__________|   " << '\n';
	std::cout << "|________O__________|   " << '\n';
	std::cout << "|________|__________|   " << '\n';
	std::cout << "|______/ | \\________|   " << '\n';
	std::cout << "|___ _/  |  \\_ _____|   " << '\n';
	std::cout << "|________|__________|   " << '\n';
	std::cout << "|______/   \\________|   " << '\n';
	std::cout << "|_____/_____\\_ _____|   " << '\n';
	std::cout << "|------HangMan------|   " << '\n';
	std::cout << "|___________________|   " << '\n';

	std::cout << "\nPress any Key to Start" << '\n';

	std::cin >> input;
	Tries(lives);
}

int HangMan::Tries(int lives)
{
	char Guess{};
	const int n(100);
	//RandomWords Generater
	std::string Words;
	std::string WordList[n];
	srand(static_cast<unsigned int>(time(NULL)));//static casting to conver the type to match
	std::ifstream RandWord;
	RandWord.open("WordList.txt");
	for (int i = 0; i < n - 1; i++)
	{
		RandWord >> WordList[i];
		//std::cout << WordList[i] << '\n';
	}
	int Randnum = rand() % 100;
	Words = Randnum[WordList];
	std::cout << Words << '\n';
	RandWord.close();//stops using the files to save Mem

	std::string HiddenWord(Words.length(), '*');
	std::cout << HiddenWord << '\n';
	std::cout << "\033[2J\033[1;1H";

	while (lives >= 0)
	{
		bool bIsGuess = false;
		std::cout << "The Word You have is : \n\n";
		std::cout << HiddenWord << '\n';
		std::cout << "There are [" << HiddenWord.length() << "] In the word!" << '\n';
		std::cout << "\n" << "Lives Left: " << lives - 1 << '\n';
		std::cout << "\nGuess the letter\n";
		std::cin >> Guess;

		for (size_t i = 0; i < HiddenWord.length(); i++)
		{
			if (Words[i] == Guess)
			{
				HiddenWord[i] = Guess;
				std::cout << "\033[2J\033[1;1H";
				std::cout << "\nYou Found a the letter:\n" << Guess << '\n';
				bIsGuess = true;
			}
		}
		if (Words == HiddenWord)
		{
			std::cout << "\nCongratulation You Found the Word" << '\n';
			break;
		}
		if (bIsGuess == false)
		{
			lives--;
			std::cout << "\033[2J\033[1;1H";
			std::cout << "\nsorry " << Guess << " Is not In the word" << '\n';
		}

		switch (lives)
		{
		case 5:
		{
			std::cout << "_____________________   " << '\n';
			std::cout << "|________}__________|   " << '\n';
			std::cout << "|________O__________|   " << '\n';
			std::cout << "|________|__________|   " << '\n';
			std::cout << "|______/ | \\________|   " << '\n';
			std::cout << "|___ _/  |  \\_ _____|   " << '\n';
			std::cout << "|________|__________|   " << '\n';
			std::cout << "|______/   \\________|   " << '\n';
			std::cout << "|_____/_____\\_ _____|   " << '\n';
			std::cout << "|-------------------|   " << '\n';
			std::cout << "|___________________|   " << '\n';

			break;
		}
		case 4:
		{
			std::cout << "_____________________   " << '\n';
			std::cout << "|________}__________|   " << '\n';
			std::cout << "|________O__________|   " << '\n';
			std::cout << "|________|__________|   " << '\n';
			std::cout << "|______/ | \\________|   " << '\n';
			std::cout << "|___ _/  |  \\_ _____|   " << '\n';
			std::cout << "|________|__________|   " << '\n';
			std::cout << "|______/   \\________|   " << '\n';
			std::cout << "|    _/_____\\_______|   " << '\n';
			std::cout << "|-------------------|   " << '\n';
			std::cout << "|___________________|    " << '\n';

			break;
		}
		case 3:
		{
			std::cout << "_____________________   " << '\n';
			std::cout << "|________}__________|   " << '\n';
			std::cout << "|________}__________|   " << '\n';
			std::cout << "|________O__________|   " << '\n';
			std::cout << "|________|__________|   " << '\n';
			std::cout << "|______/ | \\________|   " << '\n';
			std::cout << "|___ _/  |  \\_ _____|   " << '\n';
			std::cout << "|________|__________|   " << '\n';
			std::cout << "|______/   \\________|   " << '\n';
			std::cout << "|    _/     \\_______|   " << '\n';
			std::cout << "|-------------------|   " << '\n';
			std::cout << "|___________________|   " << '\n';

			break;
		}
		case 2:
		{
			std::cout << "_____________________   " << '\n';
			std::cout << "|________}__________|   " << '\n';
			std::cout << "|________}__________|   " << '\n';
			std::cout << "|________O__________|   " << '\n';
			std::cout << "|________|__________|   " << '\n';
			std::cout << "|______/ | \\________|   " << '\n';
			std::cout << "|___ _/  |  \\_ _____|   " << '\n';
			std::cout << "|________|__________|   " << '\n';
			std::cout << "|______/   \\________|   " << '\n';
			std::cout << "|    _/     \\_      |   " << '\n';
			std::cout << "|----Last Life------|   " << '\n';
			std::cout << "|___________________|   " << '\n';
			break;
		}
		case 1:
		{
			std::cout << "_____________________   " << '\n';
			std::cout << "|________}__________|   " << '\n';
			std::cout << "|________}__________|   " << '\n';
			std::cout << "|________}__________|   " << '\n';
			std::cout << "|________/O_________|   " << '\n';
			std::cout << "|________|__________|   " << '\n';
			std::cout << "|______/ | \\_______ |   " << '\n';
			std::cout << "|___ _/  |  \\_ ____ |   " << '\n';
			std::cout << "|________|__________|   " << '\n';
			std::cout << "|______/   \\_______ |   " << '\n';
			std::cout << "|   __/     \\__     |   " << '\n';
			std::cout << "|___________________|  " << '\n';
			std::cout << "|____Game Over______|   " << '\n';
			lives = -1;
			break;
		}
		default:
			std::cout << "|     Game Over     |   " << '\n';
			break;
		}
	}
	return lives;
}