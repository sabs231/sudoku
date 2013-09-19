#ifndef LP_HH_
#	define LP_HH_

#	include 	<lp_lib.h>

class 			LpObject
{
	protected:
		lprec 	*_lp;
	public:
		LpObject(int rows, int columns);
		~LpOpject();
};

#endif
