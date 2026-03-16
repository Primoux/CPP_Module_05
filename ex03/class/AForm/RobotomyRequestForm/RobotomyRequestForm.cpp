/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 17:40:00 by enchevri          #+#    #+#             */
/*   Updated: 2026/03/16 13:20:48 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "color.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() :
AForm("RobotomyRequestForm", 72, 45), _target("unknown")
{
	std::cout << ROBOTOMY << "RobotomyRequestForm default constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) :
AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << ROBOTOMY << "RobotomyRequestForm constructor called for " << _target << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &original) :
AForm(original), _target(original._target)
{
	std::cout << ROBOTOMY << "RobotomyRequestForm copy constructor called" << RESET << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << ROBOTOMY << "RobotomyRequestForm destructor called" << RESET << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	checkExecute(executor);

	static bool seeded = false;
	if (!seeded)
	{
		std::srand(time(NULL));
		seeded = true;
	}
	if (std::rand() % 2)
		std::cout << ROBOTOMYCOLOR << _target << " has been robotomized successfully!" << RESET << std::endl;
	else
		std::cout << ROBOTOMYCOLOR << "Robotomy of " << _target << " failed." << RESET << std::endl;
}

AForm *RobotomyRequestForm::createRobotomy(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}
