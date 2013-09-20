#ifndef LP_HH_
#	define LP_HH_

# include 	<string>
#	include 	<lp_lib.h>

class 			LpObject
{
	protected:
		lprec 		*_lp;
		REAL 		*_coeficientsFnObj;
		REAL 		***_coeficientsConst;
	public:
		LpObject(int rows, int columns);
		~LpObject();
		bool 		setObjFn();
		void 		setInt(int size);
		bool		setConstraint(int size, REAL equals);
		bool		solveLp();
		unsigned char getVariables(REAL **ptr_var);
		REAL		getObjective();
		int 		getNColumns();
		void 		setCoeficientsFnObj(float value, int size);
		void		setCoeficientsConst(float value, int size);
		void		setCoeficientConst(float value, int i, int j, int k);
		
};

#endif
