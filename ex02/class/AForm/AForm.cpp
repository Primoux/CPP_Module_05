/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:48:43 by enchevri          #+#    #+#             */
/*   Updated: 2026/03/15 17:40:00 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "color.h"
#include <iostream>

AForm::AForm() :
_name("Default"), _isSigned(false), _signGrade(1), _execGrade(1)
{
	std::cout << FORM << "Default constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << FORM << "Destructor called" << std::endl;
}

AForm::AForm(AForm const &original) :
_name(original._name), _isSigned(original._isSigned), _signGrade(original._signGrade), _execGrade(original._execGrade)
{
	std::cout << FORM << "Copy constructor called for " << *this;
}

AForm::AForm(std::string const &name, int signGrade, int execGrade) :
_name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	std::cout << FORM << "Assignation constructor called for " << *this;
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw AForm::GradeTooHighException();
	if (this->_signGrade > 150 || this->_execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm &AForm::operator=(AForm const &other)
{
	std::cout << FORM << "Operator = called for " << *this;
	std::cout << BYELLOW << "Warning:" RESET " only the boolean can be copied" << std::endl;
	this->_isSigned = other._isSigned;
	return (*this);
}

const std::string AForm::getName(void) const
{
	return (this->_name);
}

bool AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

int AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

int AForm::getExecGrade(void) const
{
	return (this->_execGrade);
}

void AForm::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &o, AForm const &obj)
{
	return (o << FORMCOLOR << obj.getName() << ", sign grade " << obj.getSignGrade() << ", exec grade " << obj.getExecGrade() << ", signed: " << (obj.getIsSigned() ? "yes" : "no") << RESET << std::endl);
}
