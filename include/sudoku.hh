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
	public:
		Sudoku(int size);
		~Sudoku();
		int 						getSize();
		int 						getValueAt(int i, int j, int k);
		void 						generateFObj();
};

#endif
