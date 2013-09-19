#include 	<iostream>
#include 	"sudoku.hh"
#include 	"sudokuException.hh"

Sudoku::Sudoku(int size)
{
	_size = size;
	_game = new int **[size];
	for (int i = 0; i < size; i++)
	{
		_game[i] = new int*[size];
		for (int j = 0; j < size; j++)
		{
			_game[i][j] = new int[size];
			for (int k = 0; k < size; k++)
				_game[i][j][k] = 0;
		}
	}
	if (_game == NULL)
		throw CreateGameException("Could not create the board\n");
}

Sudoku::~Sudoku()
{
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			delete [] _game[i][j];
		}
		delete [] _game[i];
	}
	delete [] _game;
}

int 			Sudoku::getSize()
{
	return (_size);
}

int 			Sudoku::getValueAt(int i, int j, int k)
{
	return (_game[i][j][k]);
}


void 			Sudoku::generateFObj()
{
	for (int i = 1; i <= _size; i++)
	{
		for (int j = 1; j <= _size; j++)
		{
			for (int k = 1; k <= _size; k++)
			{
				if (i == _size && j == _size && k == _size)
					std::cout << "x" << i << j << k << ";";
				else
					std::cout << "x" << i << j << k << " + ";
			}
			std::cout << std::endl;
		}
	}

}
