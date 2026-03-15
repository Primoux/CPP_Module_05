/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:02:29 by enchevri          #+#    #+#             */
/*   Updated: 2026/03/15 19:17:11 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "color.h"
#include <iostream>
#include <cstdlib>

void printHeader(std::string const &title)
{
	std::cout << BCYAN << "\n═══════════════════════════════════════════════════════════" << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << "═══════════════════════════════════════════════════════════\n" << RESET << std::endl;
}

// ─── BUREAUCRAT TESTS ────────────────────────────────────────────────────────

void testValidBureaucrat()
{
	printHeader("TEST 1: Valid Bureaucrat Creation");
	try
	{
		Bureaucrat bob("Bob", 75);
		std::cout << BWHITE << bob << RESET;

		std::cout << BYELLOW << "\n➜ Incrementing grade..." << RESET << std::endl;
		bob.incrementGrade();
		std::cout << BWHITE << bob << RESET;

		std::cout << BYELLOW << "➜ Decrementing grade..." << RESET << std::endl;
		bob.decrementGrade();
		std::cout << BWHITE << bob << RESET;
	}
	catch (const std::exception& e)
	{
		std::cout << BRED << "❌ Exception: " << e.what() << RESET << std::endl;
	}
}

void testBureaucratGradeTooHigh()
{
	printHeader("TEST 2: Bureaucrat Grade Too High at Creation");
	try
	{
		Bureaucrat alice("Alice", 0);
		std::cout << BWHITE << alice << RESET;
	}
	catch (const std::exception& e)
	{
		std::cout << BRED << "❌ Exception caught: " << e.what() << RESET << std::endl;
	}
}

void testBureaucratGradeTooLow()
{
	printHeader("TEST 3: Bureaucrat Grade Too Low at Creation");
	try
	{
		Bureaucrat charlie("Charlie", 151);
		std::cout << BWHITE << charlie << RESET;
	}
	catch (const std::exception& e)
	{
		std::cout << BRED << "❌ Exception caught: " << e.what() << RESET << std::endl;
	}
}

void testIncrementOverflow()
{
	printHeader("TEST 4: Bureaucrat Increment Overflow");
	try
	{
		Bureaucrat ceo("CEO", 1);
		std::cout << BWHITE << ceo << RESET;

		std::cout << BYELLOW << "➜ Trying to increment beyond grade 1..." << RESET << std::endl;
		ceo.incrementGrade();
		std::cout << BWHITE << ceo << RESET;
	}
	catch (const std::exception& e)
	{
		std::cout << BRED << "❌ Exception caught: " << e.what() << RESET << std::endl;
	}
}

void testDecrementOverflow()
{
	printHeader("TEST 5: Bureaucrat Decrement Overflow");
	try
	{
		Bureaucrat intern("Intern", 150);
		std::cout << BWHITE << intern << RESET;

		std::cout << BYELLOW << "➜ Trying to decrement below grade 150..." << RESET << std::endl;
		intern.decrementGrade();
		std::cout << BWHITE << intern << RESET;
	}
	catch (const std::exception& e)
	{
		std::cout << BRED << "❌ Exception caught: " << e.what() << RESET << std::endl;
	}
}

void testBureaucratCopyAndAssignment()
{
	printHeader("TEST 6: Bureaucrat Copy Constructor & Assignment Operator");
	try
	{
		Bureaucrat original("Original", 42);
		std::cout << BGREEN << "Original: " << RESET << BWHITE << original << RESET;

		Bureaucrat copy(original);
		std::cout << BGREEN << "Copy: " << RESET << BWHITE << copy << RESET;

		Bureaucrat assigned("Assigned", 100);
		std::cout << BGREEN << "Before assignment: " << RESET << BWHITE << assigned << RESET;
		assigned = original;
		std::cout << BGREEN << "After assignment: " << RESET << BWHITE << assigned << RESET;
	}
	catch (const std::exception& e)
	{
		std::cout << BRED << "❌ Exception: " << e.what() << RESET << std::endl;
	}
}

// ─── FORM TESTS ──────────────────────────────────────────────────────────────

void testShrubberyCreation()
{
	printHeader("TEST 7: ShrubberyCreationForm - Successful Sign & Execute");
	try
	{
		Bureaucrat gardener("Gardener", 140);
		ShrubberyCreationForm form("home");

		std::cout << BWHITE << gardener << RESET;
		std::cout << BWHITE << form << RESET;

		std::cout << BYELLOW << "➜ Signing and executing..." << RESET << std::endl;
		gardener.signForm(form);
		gardener.executeForm(form);
	}
	catch (const std::exception& e)
	{
		std::cout << BRED << "❌ Exception: " << e.what() << RESET << std::endl;
	}
}

void testShrubberyUnsigned()
{
	printHeader("TEST 8: ShrubberyCreationForm - Execute Without Signing");
	try
	{
		Bureaucrat gardener("Gardener", 140);
		ShrubberyCreationForm form("garden");

		std::cout << BYELLOW << "➜ Trying to execute without signing..." << RESET << std::endl;
		gardener.executeForm(form);
	}
	catch (const std::exception& e)
	{
		std::cout << BRED << "❌ Exception: " << e.what() << RESET << std::endl;
	}
}

void testRobotomySuccess()
{
	printHeader("TEST 9: RobotomyRequestForm - Sign & Execute");
	try
	{
		Bureaucrat doctor("Doctor", 45);
		RobotomyRequestForm form("Bender");

		std::cout << BWHITE << doctor << RESET;
		std::cout << BWHITE << form << RESET;

		doctor.signForm(form);
		doctor.executeForm(form);
		doctor.executeForm(form);
	}
	catch (const std::exception& e)
	{
		std::cout << BRED << "❌ Exception: " << e.what() << RESET << std::endl;
	}
}

void testPresidentialPardon()
{
	printHeader("TEST 10: PresidentialPardonForm - Sign & Execute");
	try
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm form("Arthur Dent");

		std::cout << BWHITE << president << RESET;
		std::cout << BWHITE << form << RESET;

		president.signForm(form);
		president.executeForm(form);
	}
	catch (const std::exception& e)
	{
		std::cout << BRED << "❌ Exception: " << e.what() << RESET << std::endl;
	}
}

void testSignFormFail()
{
	printHeader("TEST 11: signForm() - Grade Too Low");
	try
	{
		Bureaucrat intern("Intern", 100);
		PresidentialPardonForm form("VIP");

		std::cout << BWHITE << intern << RESET;
		std::cout << BWHITE << form << RESET;

		std::cout << BYELLOW << "➜ Intern (grade 100) tries to sign PresidentialPardonForm (signGrade 25)..." << RESET << std::endl;
		intern.signForm(form);
		intern.executeForm(form);
	}
	catch (const std::exception& e)
	{
		std::cout << BRED << "❌ Exception: " << e.what() << RESET << std::endl;
	}
}

void testExecuteGradeTooLow()
{
	printHeader("TEST 12: executeForm() - Executor Grade Too Low");
	try
	{
		Bureaucrat signer("Signer", 24);
		Bureaucrat executor("Executor", 10);
		PresidentialPardonForm f("Someone");

		signer.signForm(f);
		std::cout << BYELLOW << "➜ Executor (grade 10) tries to execute (execGrade 5)..." << RESET << std::endl;
		executor.executeForm(f);
	}
	catch (const std::exception& e)
	{
		std::cout << BRED << "❌ Exception: " << e.what() << RESET << std::endl;
	}
}

int main(void)
{
	std::srand(time(NULL));
	testValidBureaucrat();
	testBureaucratGradeTooHigh();
	testBureaucratGradeTooLow();
	testIncrementOverflow();
	testDecrementOverflow();
	testBureaucratCopyAndAssignment();

	testShrubberyCreation();
	testShrubberyUnsigned();
	testRobotomySuccess();
	testPresidentialPardon();
	testSignFormFail();
	testExecuteGradeTooLow();

	printHeader("All Tests Completed!");
	return 0;
}
