/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:02:29 by enchevri          #+#    #+#             */
/*   Updated: 2026/03/03 18:04:58 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "color.h"
#include <iostream>
#include <ostream>

void printHeader(std::string const &title)
{
	std::cout << BCYAN << "\n═══════════════════════════════════════════════════════════" << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << "═══════════════════════════════════════════════════════════\n" << RESET << std::endl;
}

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

void testGradeTooHigh()
{
	printHeader("TEST 2: Grade Too High at Creation");
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

void testGradeTooLow()
{
	printHeader("TEST 3: Grade Too Low at Creation");
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
	printHeader("TEST 4: Increment Overflow");
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
	printHeader("TEST 5: Decrement Overflow");
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

void testCopyAndAssignment()
{
	printHeader("TEST 6: Copy Constructor & Assignment Operator");
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

int main(void)
{
	testValidBureaucrat();
	testGradeTooHigh();
	testGradeTooLow();
	testIncrementOverflow();
	testDecrementOverflow();
	testCopyAndAssignment();
	
	printHeader("All Tests Completed!");
	return 0;
}