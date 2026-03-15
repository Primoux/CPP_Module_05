#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat;

class Form
{
	private:
	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_execGrade;
	Form();

	public:
	// CONSTRUCTORS
	~Form();
	Form(Form const &original);
	Form(std::string const &name, int signGrade, int execGrade);

	// OPERATOR
	Form &operator=(Form const &other);

	// GETTERS
	const std::string	getName(void) const;
	bool				getIsSigned(void) const;
	int					getSignGrade(void) const;
	int					getExecGrade(void) const;

	// MEMBER FUNCTIONS
	void beSigned(Bureaucrat const &b);

	// EXCEPTIONS
	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Form const &obj);

#endif // !FORM_HPP
