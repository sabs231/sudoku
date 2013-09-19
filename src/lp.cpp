#include 	"lp.hh"

LpObject::LpObject(int rows, int columns)
{
	_lp = make_lp(rows, columns);
	if (_lp == NULL)
		throw MakeLpException("make_lp: Unable to create LP model");
}

LpObject::~LpOpject()
{
	delete_lp(_lp);
}
