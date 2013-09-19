#include 	<iostream>
#include 	"sudoku.hh"
#include 	"sudokuException.hh"

int 				main(int argc, char **argv)
{
	(void) 		argc;
	(void) 		argv;
	int 			size;

	std::cout << "Welcome to Sudoku, mortal! please select "
						<< "the size of the game that you want:\n"
						<< "4 (4x4) \n9 (9x9)"
						<< std::endl;
	std::cin >> size;
	if (size == 4 || size == 9)
	{
		try
		{
			Sudoku 	game(size);
			if (size == 4)
				LpObject(0, VAR_FOUR);
			else
				LpObject(0, VAR_NINE);
		}
		catch (Exception e)
		{
			e.what();
		}
		game.generateGame();
	}
	else
	{
		std::cerr << "Incorrect number" << std::endl;
		return (-1);
	}
	return (0);
}
