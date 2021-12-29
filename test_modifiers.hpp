/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_modifiers.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:28:19 by nayache           #+#    #+#             */
/*   Updated: 2021/12/29 15:07:17 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_MODIFIERS_HPP
# define TEST_MODIFIERS_HPP

#include "test.hpp"

void	test_modifiers(void)
{
	//----------PUSH_BACK()-----------
	std::cout << YELLOW << ".push_back() testing" << RESET << std::endl;

	VECTOR<double> vec;
	
	VECTOR<double>::value_type val = 0;
	for (VECTOR<double>::size_type i = 0; i < 20; i++)
	{
		vec.push_back(val);
		if (vec.size() != i + 1)
			std::cout << RED << "error push_back(): size() is not updated correctly" << RESET << std::endl;
		val += 0.51;
	}
	val = 0;
	for (VECTOR<double>::size_type i = 0; i < 20; i++)
	{
		std::cout << "[" << vec[i] << "]";
		if (vec[i] != val)
			std::cout << RED << "error push_back(): values pushed are not identical to those expected" << RESET << std::endl;
		val += 0.51;
	}
	std::cout << std::endl;

	VECTOR<double> vec2(2, 4.4);

	vec2.push_back(12.12);
	if (*(vec2.end() - 1) != 12.12)
		std::cout << RED << "error push_back(): value push not at the end of array" << RESET << std::endl;
	
	std::cout << GREEN << ".push_back() ok" << RESET << std::endl;

	//-----------POP_BACK()------------
	std::cout << YELLOW << ".pop_back() testing" << RESET << std::endl;

	VECTOR<int>	test(10);

	VECTOR<int>::value_type value = 0;
	for (VECTOR<int>::size_type i = 0; i < 10; i++)
		test[i] = value++;
	test.pop_back();
	test.pop_back();
	test.pop_back();
	for (VECTOR<int>::size_type i = 0; i < 10; i++)
	{
		std::cout << "[" << test[i] << "]";
		if (i > 6 && test[i] != static_cast<int>(i))
			std::cout << RED << "error pop_back(): element < size && < capacity set at zero after called by this one" << RESET << std::endl;
	}
	std::cout << std::endl;
	if (test.size() != 7)
		std::cout << RED << "error pop_back(): size is not updated correctly" << RESET << std::endl;
	
	std::cout << GREEN << ".pop_back() ok" << RESET << std::endl;
	
	//------------ASSIGN()--------------
	std::cout << YELLOW << ".assign() testing" << RESET << std::endl;
	
	VECTOR<int> vect;

	// basic assign (n, value)
	vect.assign(4, 100);
	for (VECTOR<int>::iterator it = vect.begin(); it != vect.end(); it++)
	{
		if (*it != 100)
			std::cout << RED << "error assign(): wrong value" << RESET << std::endl;
		std::cout << "[" << *it << "]";
	}
	std::cout << std::endl;
	printAttributes(vect);
	if (vect.size() != 4)
		std::cout << RED << "error assign(): size are not updated correctly after function call" << RESET << std::endl;
	
	// a new basic assign(n, value) in the same vector -> must updated size at n
	vect.assign(1, -4);
	for (VECTOR<int>::iterator it = vect.begin(); it != vect.end(); it++)
	{
		if (*it != -4)
			std::cout << RED << "error assign(): wrong value" << RESET << std::endl;
		std::cout << "[" << *it << "]";
	}
	if (vect.size() != 1)
		std::cout << RED << "error assign(): size are not updated correctly after function call" << RESET << std::endl;
	std::cout << std::endl;

	VECTOR<int> vect2(10);

	VECTOR<int>::value_type v = 0;
	for (VECTOR<int>::size_type i = 0; i < 10; i++)
	{
		vect2[i] = v * 10;
		v++;
	}
	
	// assign with iterators(first, end)
	VECTOR<int> vect3;
	vect3.assign(vect2.begin(), vect2.end());
	printVector(vect3);
	v = 0;
	for (VECTOR<int>::iterator it = vect3.begin(); it != vect3.end(); it++)
	{
		if (*it != v * 10)
			std::cout << RED << "error assign(): wrong value" << RESET << std::endl;
		v++;
	}
	if (vect3.size() != 10)
		std::cout << RED << "error assign(): size are not updated correctly after function call" << RESET << std::endl;
	
	vect3.assign(vect2.begin() + 1, vect2.end() - 1);
	v = 1;
	for (VECTOR<int>::iterator it = vect3.begin(); it != vect3.end(); it++)
	{
		std::cout << "[" << *it << "]";
		if (*it != v * 10)
			std::cout << RED << "error assign(): wrong value" << RESET << std::endl;
		v++;
	}
	std::cout << std::endl;
	if (vect3.size() != 8)
		std::cout << RED << "error assign(): size are not updated correctly after function call" << RESET << std::endl;

	vect3.assign(vect3.begin(), vect3.end() - 3);
	v = 1;
	for (VECTOR<int>::iterator it = vect3.begin(); it != vect3.end(); it++)
	{
		std::cout << "[" << *it << "]";
		if (*it != v * 10)
			std::cout << RED << "error assign(): wrong value" << RESET << std::endl;
		v++;
	}
	std::cout << std::endl;
	if (vect3.size() != 5)
		std::cout << RED << "error assign(): size are not updated correctly after function call" << RESET << std::endl;

	// assign with array[] pointers(first, end)
	int	tabInt[] = {33, 66, 99, 132, 165, 198};
	vect3.assign(tabInt, tabInt + 6);
	v = 33;
	for (VECTOR<int>::iterator it = vect3.begin(); it != vect3.end(); it++)
	{
		std::cout << "[" << *it << "]";
		if (*it != v)
			std::cout << RED << "error assign(): wrong value" << RESET << std::endl;
		v += 33;
	}
	std::cout << std::endl;
	if (vect3.size() != 6)
		std::cout << RED << "error assign(): size are not updated correctly after function call" << RESET << std::endl;

	std::cout << GREEN << ".assign() ok" << RESET << std::endl;
	
	//-----------ERASE()-------------
	std::cout << YELLOW << ".erase() testing" << RESET << std::endl;


}

#endif
