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
	if (size == 4)
		_lpObj = new LpObject(0, VAR_FOUR);
	else
		_lpObj = new LpObject(0, VAR_NINE);
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

void 			Sudoku::generateGame(){
	this->generateFObj();
	this->generateRowRestrictions();
	this->generateColumnRestrictions();
	this->generateCellRestrictions();
	this->generateBlockRestrictions();
	this->generateRandomRestrictions();
	this->solve();
	//this->printPartialSudoku();
	//this->printSudoku();
}

void 			Sudoku::solve()
{
	_lpObj->solveLp();
	_lpObj->getObjective();
}

void 			Sudoku::generateFObj()
{
	std::cout << "Objective Function" << std::endl;
	_lpObj->setCoeficientsFnObj(1.0, _lpObj->getNColumns());
	_lpObj->setInt(_lpObj->getNColumns());
	_lpObj->setObjFn();
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
	std::cout << std::endl;
}

void			Sudoku::generateRowRestrictions(){
	std::cout << "Row Restrictions" << std::endl;
	_lpObj->setCoeficientsConst(0.0, _size);
	for (int i = 1; i <= _size; i++) 
	{
		std::cout << "Row " << i << std::endl;
		for (int k = 1; k <= _size; k++)
		{
			for (int j = 1; j <= _size; j++)
			{
				_lpObj->setCoeficientConst(1.0,i,j,k);
				std::cout << "x" << i << j << k << "+ ";
			}
			std::cout << "0 = 1;" << std::endl;
			_lpObj->setConstraint( _size, 1);
			_lpObj->setCoeficientsConst(0.0, _size);
		}
	}
	std::cout << std::endl;
}

void			Sudoku::generateColumnRestrictions(){
	std::cout << "Column Restrictions" << std::endl;
	_lpObj->setCoeficientsConst(0.0, _size);
	for (int j = 1; j <= _size; j++)
	{
		std::cout << "Column " << j << std::endl;
		for (int k = 1; k <= _size; k++)
		{
			for (int i = 1; i <= _size; i++) 
			{
				_lpObj->setCoeficientConst(1.0,i,j,k);
				std::cout << "x" << i << j << k << "+ ";
			}
			std::cout << "0 = 1;" << std::endl;
			_lpObj->setConstraint( _size, 1);
			_lpObj->setCoeficientsConst(0.0, _size);
		}
	}
	std::cout << std::endl;
}

void			Sudoku::generateCellRestrictions(){
	std::cout << "Restriction 1 number per cell" << std::endl;
	_lpObj->setCoeficientsConst(0.0, _size);
	for (int i = 1; i <= _size; i++)
	{
		for (int j = 1; j <= _size; j++)
		{
			for (int k = 1; k <= _size; k++)
			{
				_lpObj->setCoeficientConst(1.0,i,j,k);
				std::cout << "x" << i << j << k << "+ ";
			}
			std::cout << "0 = 1;" << std::endl;
			_lpObj->setConstraint( _size, 1);
			_lpObj->setCoeficientsConst(0.0, _size);
		}
	}
	std::cout << std::endl;
}

void			Sudoku::generateBlockRestrictions(){
	std::cout << "Restriction 1 unique number per block" << std::endl;
	_lpObj->setCoeficientsConst(0.0, _size);
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
						_lpObj->setCoeficientConst(1.0,i,j,k);
						std::cout << "x" << i << j << k << " + ";
					}
				}
				std::cout << "0 = 1;" << std::endl;
				_lpObj->setConstraint( _size, 1);
				_lpObj->setCoeficientsConst(0.0, _size);
			}
		}
	}
	std::cout << std::endl;
}

void			Sudoku::generateRandomRestrictions(){
	std::cout << "Restriction 1 random value on a cell to generate a game" << std::endl;
	int i = rand() % _size;
	int j = rand() % _size;
	int k = rand() % _size;
	_lpObj->setCoeficientsConst(0.0, _size);
	_lpObj->setCoeficientConst(1.0,i,j,k);
	_lpObj->setConstraint( _size, 1);
	_lpObj->setCoeficientsConst(0.0, _size);
	std::cout << "x" << i << j << k << " = 1;" << std::endl;
}

void 			Sudoku::displayGame()
{
	int 		blockSize = _size == 4 ? _size/2 : _size/3;

	std::cout << "\033[2J\033[0;0f";
	std::cout << "\033[0;0f";
	for (int i = 0; i < _size; i++)
	{
		std::cout << "|";
		for (int j = 0; j < _size; j++)
		{
			std::cout << "_" << "|";
		}
		std::cout << std::endl;
	}
}
