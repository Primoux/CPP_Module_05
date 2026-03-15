/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:48:43 by enchevri          #+#    #+#             */
/*   Updated: 2026/03/15 16:11:59 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "color.h"
#include <iostream>

Form::Form() :
_name("Default"), _isSigned(false), _signGrade(1), _execGrade(1)
{
	std::cout << FORM << "Default constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << FORM << "Destructor called" << std::endl;
}

Form::Form(Form const &original) :
_name(original._name), _isSigned(original._isSigned), _signGrade(original._signGrade), _execGrade(original._execGrade)
{
	std::cout << FORM << "Copy constructor called for " << *this;
}

Form::Form(std::string const &name, int signGrade, int execGrade) :
_name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	std::cout << FORM << "Assignation constructor called for " << *this;
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw Form::GradeTooHighException();
	if (this->_signGrade > 150 || this->_execGrade > 150)
		throw Form::GradeTooLowException();
}

Form &Form::operator=(Form const &other)
{
	std::cout << FORM << "Operator = called for " << *this;
	std::cout << BYELLOW << "Warning:" RESET " only the boolean can be copied" << std::endl;
	this->_isSigned = other._isSigned;
	return (*this);
}

const std::string Form::getName(void) const
{
	return (this->_name);
}

bool Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

int Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

int Form::getExecGrade(void) const
{
	return (this->_execGrade);
}

void Form::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &o, Form const &obj)
{
	return (o << FORMCOLOR << obj.getName() << ", sign grade " << obj.getSignGrade() << ", exec grade " << obj.getExecGrade() << ", signed: " << (obj.getIsSigned() ? "yes" : "no") << RESET << std::endl);
}
