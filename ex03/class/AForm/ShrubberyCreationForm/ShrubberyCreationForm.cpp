/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 17:40:00 by enchevri          #+#    #+#             */
/*   Updated: 2026/03/16 13:35:26 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "color.h"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() :
AForm("ShrubberyCreationForm", 145, 137), _target("unknown")
{
	std::cout << SHRUBBERY << "ShrubberyCreationForm default constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) :
AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << SHRUBBERY << "ShrubberyCreationForm constructor called for " << _target << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &original) :
AForm(original), _target(original._target)
{
	std::cout << SHRUBBERY << "ShrubberyCreationForm copy constructor called" << RESET << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << SHRUBBERY << "ShrubberyCreationForm destructor called" << RESET << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	checkExecute(executor);

	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not create file" << std::endl;
		return;
	}
	file << "        *        " << std::endl;
	file << "       ***       " << std::endl;
	file << "      *****      " << std::endl;
	file << "     *******     " << std::endl;
	file << "    *********    " << std::endl;
	file << "   ***********   " << std::endl;
	file << "        |        " << std::endl;
	file << "        |        " << std::endl;
	file.close();
	std::cout << SHRUBBERYCOLOR << "Shrubbery created in " << _target << "_shrubbery" << RESET << std::endl;
}

AForm *ShrubberyCreationForm::createShrubbery(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}