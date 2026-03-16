/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:09:47 by enchevri          #+#    #+#             */
/*   Updated: 2026/03/16 10:42:34 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "color.h"
#include <iostream>
#include <ostream>
#include <string>

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << BUREAUCRAT << "Default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade)
{
	std::cout << BUREAUCRAT << "Assignation constructor called for " << this->_name << " of grade " << this->_grade << RESET << std::endl;
	this->checkGrade();
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade)
{
	std::cout << BUREAUCRAT << "Copy constructor called for " << this->_name << " of grade " << this->_grade << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	std::cout << BUREAUCRAT << "Assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << BUREAUCRAT << "Destructor called for " << this->_name << " of grade " << this->_grade << RESET << std::endl;
}

const std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade(void)
{
	int tmp = this->_grade - 1;
	if (tmp < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = tmp;
}

void Bureaucrat::decrementGrade(void)
{
	int tmp = this->_grade + 1;
	if (tmp > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = tmp;
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << BUREAUCRATCOLOR << this->_name << " signed " << form.getName() << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << BRED << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << RESET << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << BUREAUCRATCOLOR << this->_name << " executed " << form.getName() << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << BRED << this->_name << " couldn't execute " << form.getName() << " because " << e.what() << RESET << std::endl;
	}
}

void Bureaucrat::checkGrade(void)
{
	std::cout << BUREAUCRAT << "checkGrade called" << RESET << std::endl;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &obj)
{
	return (o << BUREAUCRATCOLOR << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << RESET << std::endl);
}
