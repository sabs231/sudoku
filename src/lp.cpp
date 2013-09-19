#include 	"sudoku.hh"
#include 	"lp.hh"
#include 	"sudokuException.hh"

LpObject::LpObject(int rows, int columns)
{
	_lp = make_lp(rows, columns);
	if (columns == VAR_FOUR)
		_coeficientsFnObj = new REAL[1 + VAR_FOUR];
	else
		_coeficientsFnObj = new REAL[1 + VAR_NINE];
	if (_lp == NULL)
		throw MakeLpException("make_lp: Unable to create LP model");
}

LpObject::~LpObject()
{
	delete_lp(_lp);
}

bool 		LpObject::setObjFn()
{
	if (set_obj_fn(this->_lp, this->_coeficientsFnObj) == 1)
		return (true);
	return (false);
}

void 		LpObject::setCoeficientsFnObj(float value, int size)
{
	for (int i = 1; i < size; i++)
		_coeficientsFnObj[i] = value;
}

void 		LpObject::setInt(int size)
{
	for (int i = 1; i < size; i++)
		set_int(this->_lp, i, TRUE);
}

int 		LpObject::getNColumns()
{
	return (get_Ncolumns(this->_lp));
}
