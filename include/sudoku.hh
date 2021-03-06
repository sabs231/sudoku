#ifndef SUDOKU_HH_
#	define SUDOKU_HH_

#include "lp.hh"

#	define NUM_VALUE 	9
# define VAR_FOUR 	64
# define VAR_NINE 	729

class 							Sudoku
{
	protected:
		int 					***_game;
		int 					_size;
		LpObject 			*_lpObj;
	public:
		Sudoku(int size);
		~Sudoku();
		int 						getSize();
		int 						getValueAt(int i, int j, int k);
		void 						generateFObj();
		void 						generateGame();
		void 						generateRowRestrictions();
		void 						generateColumnRestrictions();
		void 						generateCellRestrictions();
		void 						generateBlockRestrictions();
		void 						generateRandomRestrictions();
		void						displayGame();
		void 						solve();
		void 						fillSolution();
		void 						displayNotSolution();
};

#endif
