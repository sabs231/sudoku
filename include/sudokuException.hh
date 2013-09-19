#ifndef SUDOKUEXCEPTION_HH_
#	define SUDOKUEXCEPTION_HH_

#	include 							<string>
# include 							<exception>

class 									SudokuException : public std::exception
{
	protected:
		std::string					message;
	public:
		SudokuException(const std::string & msg) throw();
		virtual const char 	*what() const throw();
		~SudokuException() throw();
};

class 									CreateGameException : public SudokuException
{
	public:
		CreateGameException(const std::string & msg) throw();
		~CreateGameException() throw();
};

#endif
