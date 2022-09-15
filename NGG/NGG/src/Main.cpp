#include "Include.h"
#include "Game.h"


int main()
{
	
	while (game::round == 1)
	{
		std::cout << "Write a number into the console";
		std::srand(time(0));
		game::random = std::rand() % 101;

		while (game::start == 1)
		{

			std::cin >> game::answer;
			if (game::answer == game::random)
			{
				std::cout << "Well done! \n";
				if (game::lives > game::highscore)
				{
					game::highscore = game::lives;
				}
				std::cout << "Your highscore is: " << game::lives << "\n";
				break;
			}
			else if (game::answer < game::random)
			{
				std::cout << "Guess higher \n";
				game::start = 0;
			}
			else if (game::answer > game::random)
			{
				std::cout << "Guess lower \n";
				game::start = 0;
			}
			else
			{
				std::cout << "Wrong \n";
				game::start = 0;
			}

			game::start = 0;

			while (game::start == 0)
			{
				if (game::lives < 1)
				{
					std::cout << "You died\n";
					return 0;
				}
				else
				{
					game::lives--;
					std::cout << "Lives remaining: " << game::lives << "\n";
					game::start = 1;
				}
			}

		}
	}
}