/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 19:43:31 by enchevri          #+#    #+#             */
/*   Updated: 2026/03/15 20:25:01 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <utility>


Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(Intern const &original)
{
	*this = original;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(Intern const &other)
{
	(void)other;
	std::cout << "Intern assignment operator called" << std::endl;
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const Intern &obj)
{
	(void)obj;
	return (o << "Intern" << std::endl);
}

AForm* Intern::makeForm(std::string const &formName, std::string const &target)
{
	static std::pair<std::string, AForm*(*)(std::string const&)> forms[] = {
		std::make_pair("ShrubberyCreationForm", &ShrubberyCreationForm::createShrubbery),
		std::make_pair("RobotomyRequestForm", &RobotomyRequestForm::createRobotomy),
		std::make_pair("PresidentialPardonForm", &PresidentialPardonForm::createPresidential)
	};

	for (size_t i = 0; i < sizeof(forms) / sizeof(forms[0]); i++)
	{
		if (forms[i].first == formName)
			return (forms[i].second(target));
	}
	throw AForm::FormNotFoundException();
}
