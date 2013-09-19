#ifndef SUDOKU_HH_
#	define SUDOKU_HH_

#	define NUM_VALUE 	9
# define VAR_FOUR 	64
# define VAR_NINE 	729

class 							Sudoku
{
	protected:
		int 						***_game;
		int 						_size;
		void 						generateFObj();
		void 						generateRowRestrictions();
		void 						generateColumnRestrictions();
		void 						generateCellRestrictions();
		void 						generateBlockRestrictions();
		void 						generateRandomRestrictions();
	public:
		Sudoku(int size);
		~Sudoku();
		int 						getSize();
		int 						getValueAt(int i, int j, int k);
		void 						generateGame();
};

#endif
