#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <ostream>
#include <string>

class Form;

class Bureaucrat
{
	private:
	const std::string	_name;
	int 		_grade;
	void checkGrade(void);

	public:
	// CONSTRUCTORS
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(Bureaucrat const &original);
	Bureaucrat(std::string const &name, int grade);

	// OPERATOR
	Bureaucrat &operator=(Bureaucrat const &other);

	// MEMBER FUNCTIONS
	const std::string	getName(void) const;
	int 				getGrade(void) const;
	void 				incrementGrade(void);
	void 				decrementGrade(void);
	void 				signForm(Form &form);


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

std::ostream &operator<<(std::ostream &o, Bureaucrat const &obj);

#endif // !BUREAUCRAT_HPP