#include 	"sudokuException.hh"

SudokuException::SudokuException(const std::string & msg) throw()
	: message(msg)
{
}

const char 	*SudokuException::what() const throw()
{
	return (this->message.data());
}

SudokuException::~SudokuException() throw()
{
}

CreateGameException::CreateGameException(const std::string & msg) throw()
	: SudokuException(std::string("Create Game Exception") + msg)
{
}

CreateGameException::~CreateGameException() throw()
{
}
