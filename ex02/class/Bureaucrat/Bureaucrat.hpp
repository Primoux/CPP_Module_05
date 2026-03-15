/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:09:47 by enchevri          #+#    #+#             */
/*   Updated: 2026/03/15 17:40:00 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <ostream>
#include <string>

class AForm;

class Bureaucrat
{
	private:
	const std::string	_name;
	int					_grade;
	void				checkGrade(void);

	public:
	// CONSTRUCTORS
	Bureaucrat();
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &original);
	Bureaucrat &operator=(Bureaucrat const &other);
	~Bureaucrat();

	// GETTERS
	const std::string	getName(void) const;
	int					getGrade(void) const;

	// MEMBER FUNCTIONS
	void	incrementGrade(void);
	void	decrementGrade(void);
	void	signForm(AForm &form);
	void	executeForm(AForm const &form);

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
