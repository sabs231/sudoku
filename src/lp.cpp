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

bool 		LpObject::setStrObjFn(LpObj *lp, std::string row_string)
{
	if (str_set_obj_fn(lp->_lp, row_string.c_str() == 1))
		return (true);
	return (false);
}
