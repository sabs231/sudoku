#ifndef LP_HH_
#	define LP_HH_

# include 	<string>
#	include 	<lp_lib.h>

class 			LpObject
{
	protected:
		lprec 	*_lp;
		REAL 		*_coeficientsFnObj;
	public:
		LpObject(int rows, int columns);
		~LpObject();
		bool 		setObjFn();
		void 		setCoeficientsFnObj(float value, int size);
		void 		setInt(int size);
		int 		getNColumns();
};

#endif
