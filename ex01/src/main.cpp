/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:02:29 by enchevri          #+#    #+#             */
/*   Updated: 2026/03/15 14:37:50 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "color.h"
#include <iostream>

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

void testValidForm()
{
	printHeader("TEST 7: Valid Form Creation");
	try
	{
		Form f("Tax Return", 50, 25);
		std::cout << BWHITE << f << RESET;
	}
	catch (const std::exception& e)
	{
		std::cout << BRED << "❌ Exception: " << e.what() << RESET << std::endl;
	}
}

void testFormGradeTooHigh()
{
	printHeader("TEST 8: Form Grade Too High at Creation");
	try
	{
		Form f("BadForm", 0, 50);
		std::cout << BWHITE << f << RESET;
	}
	catch (const std::exception& e)
	{
		std::cout << BRED << "❌ Exception caught: " << e.what() << RESET << std::endl;
	}
}

void testFormGradeTooLow()
{
	printHeader("TEST 9: Form Grade Too Low at Creation");
	try
	{
		Form f("BadForm", 50, 151);
		std::cout << BWHITE << f << RESET;
	}
	catch (const std::exception& e)
	{
		std::cout << BRED << "❌ Exception caught: " << e.what() << RESET << std::endl;
	}
}

void testSignFormSuccess()
{
	printHeader("TEST 10: Successful Signing via signForm()");
	try
	{
		Bureaucrat manager("Manager", 30);
		Form contract("Contract", 50, 10);

		std::cout << BWHITE << manager << RESET;
		std::cout << BWHITE << contract << RESET;

		std::cout << BYELLOW << "➜ Manager (grade 30) signs Contract (signGrade 50)..." << RESET << std::endl;
		manager.signForm(contract);

		std::cout << BWHITE << contract << RESET;
	}
	catch (const std::exception& e)
	{
		std::cout << BRED << "❌ Exception: " << e.what() << RESET << std::endl;
	}
}

void testSignFormFail()
{
	printHeader("TEST 11: Failed Signing via signForm() - Grade Too Low");
	try
	{
		Bureaucrat intern("Intern", 100);
		Form topSecret("Top Secret", 10, 5);

		std::cout << BWHITE << intern << RESET;
		std::cout << BWHITE << topSecret << RESET;

		std::cout << BYELLOW << "➜ Intern (grade 100) tries to sign Top Secret (signGrade 10)..." << RESET << std::endl;
		intern.signForm(topSecret);

		std::cout << BWHITE << topSecret << RESET;
	}
	catch (const std::exception& e)
	{
		std::cout << BRED << "❌ Exception: " << e.what() << RESET << std::endl;
	}
}

void testBeSignedDirectly()
{
	printHeader("TEST 12: beSigned() Called Directly");
	try
	{
		Bureaucrat b("Director", 1);
		Form f("Presidential Order", 1, 1);

		std::cout << BWHITE << f << RESET;
		std::cout << BYELLOW << "➜ Signing with grade 1 (highest)..." << RESET << std::endl;
		f.beSigned(b);
		std::cout << BWHITE << f << RESET;
	}
	catch (const std::exception& e)
	{
		std::cout << BRED << "❌ Exception: " << e.what() << RESET << std::endl;
	}
}

void testFormCopyAndAssignment()
{
	printHeader("TEST 13: Form Copy Constructor & Assignment Operator");
	try
	{
		Form original("Original Form", 42, 10);
		std::cout << BGREEN << "Original: " << RESET << BWHITE << original << RESET;

		Form copy(original);
		std::cout << BGREEN << "Copy: " << RESET << BWHITE << copy << RESET;

		Form target("Target Form", 80, 40);
		std::cout << BGREEN << "Before assignment: " << RESET << BWHITE << target << RESET;
		target = original;
		std::cout << BGREEN << "After assignment (only isSigned copied): " << RESET << BWHITE << target << RESET;
	}
	catch (const std::exception& e)
	{
		std::cout << BRED << "❌ Exception: " << e.what() << RESET << std::endl;
	}
}

int main(void)
{
	testValidBureaucrat();
	testBureaucratGradeTooHigh();
	testBureaucratGradeTooLow();
	testIncrementOverflow();
	testDecrementOverflow();
	testBureaucratCopyAndAssignment();

	testValidForm();
	testFormGradeTooHigh();
	testFormGradeTooLow();
	testSignFormSuccess();
	testSignFormFail();
	testBeSignedDirectly();
	testFormCopyAndAssignment();

	printHeader("All Tests Completed!");
	return 0;
}
