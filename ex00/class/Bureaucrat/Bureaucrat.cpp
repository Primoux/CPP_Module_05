/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:09:47 by enchevri          #+#    #+#             */
/*   Updated: 2026/03/03 18:01:42 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>
#include <string>

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called for " << this->_name << " of grade " << this->_grade << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat assignation constructor called for " << this->_name << " of grade " << this->_grade << std::endl;
	this->checkGrade();
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat copy constructor called for " << this->_name << " of grade " << this->_grade << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

const std::string Bureaucrat::getName(void) const
{
	// std::cout << "Bureaucrat getName called" << std::endl;
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	// std::cout << "Bureaucrat getGrade called" << std::endl;
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
	std::cout << "Bureaucrat checkGrade called" << std::endl;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &obj)
{
	return (o << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl);
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
