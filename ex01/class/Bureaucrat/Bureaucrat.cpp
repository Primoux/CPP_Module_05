/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:09:47 by enchevri          #+#    #+#             */
/*   Updated: 2026/03/15 16:28:59 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "color.h"
#include <iostream>
#include <ostream>
#include <string>

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << BUREAUCRAT << "Default constructor called" << RESET << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << BUREAUCRAT << "Destructor called for " << this->_name << " of grade " << this->_grade << RESET << std::endl;
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

const std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

void Bureaucrat::checkGrade(void)
{
	std::cout << BUREAUCRAT << "checkGrade called" << RESET << std::endl;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &obj)
{
	return (o << BUREAUCRATCOLOR << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << RESET << std::endl);
}

void Bureaucrat::incrementGrade()
{
    int tmp = this->_grade - 1;
    if (tmp < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade = tmp;
}

void Bureaucrat::decrementGrade()
{
    int tmp = this->_grade + 1;
    if (tmp > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = tmp;
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << BUREAUCRATCOLOR << this->_name << " signed " << form.getName() << RESET << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << BUREAUCRATCOLOR << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << RESET << std::endl;
    }
}
