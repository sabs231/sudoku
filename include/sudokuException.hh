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

class 									MakeLpException : public SudokuException
{
	public:
		MakeLpException(const std::string & msg) throw();
		~MakeLpException() throw();
};

#endif
