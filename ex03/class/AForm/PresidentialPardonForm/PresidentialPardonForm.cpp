/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 17:40:00 by enchevri          #+#    #+#             */
/*   Updated: 2026/03/16 13:42:07 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "color.h"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() :
AForm("PresidentialPardonForm", 25, 5), _target("unknown")
{
	std::cout << PRESIDENTIAL << "PresidentialPardonForm default constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) :
AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << PRESIDENTIAL << "PresidentialPardonForm constructor called for " << _target << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &original) :
AForm(original), _target(original._target)
{
	std::cout << PRESIDENTIAL << "PresidentialPardonForm copy constructor called" << RESET << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << PRESIDENTIAL << "PresidentialPardonForm destructor called" << RESET << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	checkExecute(executor);

	std::cout << PRESIDENTIALCOLOR << _target << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}

AForm *PresidentialPardonForm::createPresidential(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}