/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:48:43 by enchevri          #+#    #+#             */
/*   Updated: 2026/03/15 17:40:00 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat;

class AForm
{
	private:
	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_execGrade;

	public:
	// CONSTRUCTORS
	AForm();
	AForm(std::string const &name, int signGrade, int execGrade);
	AForm(AForm const &original);
	AForm &operator=(AForm const &other);
	virtual ~AForm();

	// GETTERS
	const std::string	getName(void) const;
	bool				getIsSigned(void) const;
	int					getSignGrade(void) const;
	int					getExecGrade(void) const;

	// MEMBER FUNCTIONS
	void beSigned(Bureaucrat const &b);
	virtual void execute(Bureaucrat const &executor) const = 0;

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

std::ostream &operator<<(std::ostream &o, AForm const &obj);

#endif // !AFORM_HPP
