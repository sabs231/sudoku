#include 	<iostream>
#include 	"sudoku.hh"
#include 	"lp.hh"
#include 	"sudokuException.hh"

LpObject::LpObject(int rows, int columns)
{
	_lp = make_lp(rows, columns);
	if (columns == VAR_FOUR)
		_coeficientsFnObj 	= new REAL[1 + VAR_FOUR];
	else
		_coeficientsFnObj 	= new REAL[1 + VAR_NINE];
	_coeficientsConst = new REAL **[columns];
	for (int i = 0; i < columns; i++)
	{
		_coeficientsConst[i] = new REAL*[columns];
		for (int j = 0; j < columns; j++)
		{
			_coeficientsConst[i][j] = new REAL[columns];
			for (int k = 0; k < columns; k++)
				_coeficientsConst[i][j][k] = 0;
		}
	}
	if (_lp == NULL)
		throw MakeLpException("make_lp: Unable to create LP model");
}

LpObject::~LpObject()
{
	delete_lp(_lp);
}
/*
* Declara la funcion objetivo
*/
bool 		LpObject::setObjFn()
{
	if (set_obj_fn(this->_lp, this->_coeficientsFnObj) == 1){
		return (true);
	}
	return (false);
}
/*
* Inicia la matriz de Coeficientes de la Función Objetivo a un valor dado
*/
void 		LpObject::setCoeficientsFnObj(float value, int size)
{
	for (int i = 1; i < size; i++)
		_coeficientsFnObj[i] = value;
}
/*
* Inicia la matriz de Coeficientes a un valor dado
*/
void 		LpObject::setCoeficientsConst(float value, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++)
			{
				_coeficientsConst[i][j][k] = value;
			}
		}
	}
}
/*
* Pone el valor en el arreglo de Coeficientes
*/
void 		LpObject::setCoeficientConst(float value, int i, int j, int k)
{
		_coeficientsConst[i-1][j-1][k-1] = value;
}

/*
* Agrega una constraint con el arreglo actual de Restricciones
*/
bool		LpObject::setConstraint(int size, REAL equals){
	REAL *_coeficientsContraint;
	if (size == VAR_FOUR)
		_coeficientsContraint = new REAL[1 + VAR_FOUR];
	else
		_coeficientsContraint = new REAL[1 + VAR_NINE];
	int cci = 1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++){
				_coeficientsContraint[cci] = _coeficientsConst[i][j][k];
				cci++;
			}
		}
	}
	for(int k = 1; k <= cci; k++){
		std::cout << _coeficientsContraint[k] << " ";
	}
	std::cout << std::endl;
	if (add_constraint(this->_lp, _coeficientsContraint, 3, equals) == 1){
		return (true);	
	}
	return (false);
}

/*
* Define que las variables son enteras
*/
void 		LpObject::setInt(int size)
{
	for (int i = 1; i < size; i++)
		set_int(this->_lp, i, TRUE);
}
/*
* Regresa el Numero de Variables
*/
int 		LpObject::getNColumns() 
{
	return (get_Ncolumns(this->_lp));
}

bool		LpObject::solveLp(){
	return solve(this->_lp);
}

unsigned char LpObject::getVariables(REAL **ptr_var)
{
	return get_ptr_variables(this->_lp, ptr_var);
}

REAL		LpObject::getObjective(){
	print_solution(this->_lp,this->getNColumns());
	//print_constraints(this->_lp,this->getNColumns());
	//print_tableau(this->_lp);
	return 0.0;
}



