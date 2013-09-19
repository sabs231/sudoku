#ifndef SUDOKU_HH_
#	define SUDOKU_HH_

#	define NUM_VALUE 	9

class 							Sudoku
{
	protected:
		int 						***_game;
		int 						_size;
	public:
		Sudoku(int size);
		~Sudoku();
		int 						getSize();
		int 						getValueAt(int i, int j, int k);
		void 						generateFObj();
		void 						generateRestrictions();
};

#endif
