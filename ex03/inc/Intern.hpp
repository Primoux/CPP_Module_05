#ifndef INTERN_HPP
#define INTERN_HPP

#include <ostream>

class AForm;

class Intern
{
  private:
	

  public:
	// CONSTRUCTOR
	Intern();
	~Intern();
	Intern(Intern const &original);

	// OPERATOR
	Intern &operator=(Intern const &other);
	
	// MEMBER FUNCTION
	AForm* makeForm(std::string const &formName, std::string const &target);
};
std::ostream &operator<<(std::ostream &o, const Intern &obj);

#endif // !INTERN_HPP