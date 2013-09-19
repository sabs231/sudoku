#include 	"sudoku.hh"
#include 	"sudokuException.hh"

int 			main(int argc, char **argv)
{
	Sudoku 	game(4);

	game.generateFObj();
	return (0);
}
