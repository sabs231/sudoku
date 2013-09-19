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
	std::cout << "Objective Function" << std::endl;
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
	std::cout << "0;" << std::endl;
}

void			Sudoku::generateRestrictions(){
	std::cout << "Row Restrictions" << std::endl;
	for (int i = 1; i <= _size; i++) 
	{
		std::cout << "Row " << i << std::endl;
		for (int k = 1; k <= _size; k++)
		{
			for (int j = 1; j <= _size; j++)
			{
				std::cout << "x" << i << j << k << "+ ";
			}
			std::cout << "0 = 1;" << std::endl;
		}
	}
	std::cout << "Column Restrictions" << std::endl;
	for (int j = 1; j <= _size; j++)
	{
		std::cout << "Column " << j << std::endl;
		for (int k = 1; k <= _size; k++)
		{
			for (int i = 1; i <= _size; i++) 
			{
				std::cout << "x" << i << j << k << "+ ";
			}
			std::cout << "0 = 1;" << std::endl;
		}
	}
	std::cout << "Restriction 1 number per cell" << std::endl;
	for (int i = 1; i <= _size; i++)
	{
		for (int j = 1; j <= _size; j++)
		{
			for (int k = 1; k <= _size; k++)
			{
				std::cout << "x" << i << j << k << "+ ";
			}
			std::cout << "0 = 1;" << std::endl;
		}
	}
	std::cout << "Restriction 1 unique number per block" << std::endl;
	int blockSize = _size == 4 ? _size/2 : _size/3;
	for(int block = 1; block <= blockSize; block++)
	{
		for(int block2 = 1; block2 <= blockSize; block2++)
		{
			for (int k = 1; k <= _size; k++)
			{
				for (int i = ((blockSize*(block-1))+1); i <= block*blockSize; i++)
				{
					for (int j = ((blockSize*(block2-1))+1); j <= block2*blockSize; j++){
						std::cout << "x" << i << j << k << " + ";
					}
				}
				std::cout << "0 = 1;" << std::endl;
			}
		}
	}
}
