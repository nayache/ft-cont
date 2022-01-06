/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_modifiers.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:28:19 by nayache           #+#    #+#             */
/*   Updated: 2022/01/06 17:57:26 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_MODIFIERS_HPP
# define TEST_MODIFIERS_HPP

#include "test.hpp"

void	test_modifiers(std::ofstream& ofs)
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
		ofs << "[" << vec[i] << "]";
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
		ofs << "[" << test[i] << "]";
		if (i > 6 && test[i] != static_cast<int>(i))
			std::cout << RED << "error pop_back(): element < size && < capacity set at zero after called by this one" << RESET << std::endl;
	}
	ofs << std::endl;
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
		ofs << "[" << *it << "]";
	}
	ofs << std::endl;
	printAttributes(vect, ofs);
	if (vect.size() != 4)
		std::cout << RED << "error assign(): size are not updated correctly after function call" << RESET << std::endl;
	
	// a new basic assign(n, value) in the same vector -> must updated size at n
	vect.assign(1, -4);
	for (VECTOR<int>::iterator it = vect.begin(); it != vect.end(); it++)
	{
		if (*it != -4)
			std::cout << RED << "error assign(): wrong value" << RESET << std::endl;
		ofs << "[" << *it << "]";
	}
	if (vect.size() != 1)
		std::cout << RED << "error assign(): size are not updated correctly after function call" << RESET << std::endl;
	ofs << std::endl;
	printAttributes(vect, ofs);

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
	printVector(vect3, ofs);
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
		ofs << "[" << *it << "]";
		if (*it != v * 10)
			std::cout << RED << "error assign(): wrong value" << RESET << std::endl;
		v++;
	}
	ofs << std::endl;
	if (vect3.size() != 8)
		std::cout << RED << "error assign(): size are not updated correctly after function call" << RESET << std::endl;

	vect3.assign(vect3.begin(), vect3.end() - 3);
	v = 1;
	for (VECTOR<int>::iterator it = vect3.begin(); it != vect3.end(); it++)
	{
		ofs << "[" << *it << "]";
		if (*it != v * 10)
			std::cout << RED << "error assign(): wrong value" << RESET << std::endl;
		v++;
	}
	ofs << std::endl;
	if (vect3.size() != 5)
		std::cout << RED << "error assign(): size are not updated correctly after function call" << RESET << std::endl;

	// assign with array[] pointers(first, end)
	int	tabInt[] = {33, 66, 99, 132, 165, 198};
	vect3.assign(tabInt, tabInt + 6);
	v = 33;
	for (VECTOR<int>::iterator it = vect3.begin(); it != vect3.end(); it++)
	{
		ofs << "[" << *it << "]";
		if (*it != v)
			std::cout << RED << "error assign(): wrong value" << RESET << std::endl;
		v += 33;
	}
	ofs << std::endl;
	if (vect3.size() != 6)
		std::cout << RED << "error assign(): size are not updated correctly after function call" << RESET << std::endl;

	std::cout << GREEN << ".assign() ok" << RESET << std::endl;
	
	//-----------ERASE()-------------
	std::cout << YELLOW << ".erase() testing" << RESET << std::endl;

	VECTOR<float> vecTest;

	VECTOR<float>::value_type f = 10.10f;	
	for (int i = 0; i < 10; i++)
	{
		vecTest.push_back(f);
		ofs << "(" << vecTest[i] << ")";
		f += 10.10f;
	}
	ofs << std::endl;
	f = *(vecTest.begin() + 3);
	vecTest.erase(vecTest.begin() + 3);
	for (VECTOR<float>::size_type i = 0; i < vecTest.size(); i++)
	{
		ofs << "(" << vecTest[i] << ")";
		if (vecTest[i] == f)
			std::cout << RED << "error erase(): value not removed!" << RESET << std::endl;
	}
	ofs << std::endl;
	if (vecTest.size() != 9)
		std::cout << RED << "error erase(): size not updated after remove element!" << RESET << std::endl;
	
	VECTOR<float> saveValues(vecTest.begin(), vecTest.end() - 4);
	vecTest.erase(vecTest.begin(), vecTest.end() - 4);
	
	for (VECTOR<float>::size_type i = 0; i < vecTest.size(); i++)
	{
		for (VECTOR<float>::size_type j = 0; j < saveValues.size(); j++)
		{
			if (vecTest[i] == saveValues[j])
				std::cout << RED << "error erase(): value not removed!" << RESET << std::endl;
		}
		ofs << "(" << vecTest[i] << ")";
	}
	ofs << std::endl;
	if (vecTest.size() != 4)
		std::cout << RED << "error erase(): size not updated after remove element!" << RESET << std::endl;
	
	std::cout << GREEN << ".erase() ok" << RESET << std::endl;

	//---------CLEAR()-------------
	std::cout << YELLOW << ".clear() testing" << RESET << std::endl;
	
	VECTOR<char> vecl;

	vecl.push_back('x');
	vecl.push_back('y');
	vecl.push_back('z');

	vecl.clear();
	for (VECTOR<char>::size_type i = 0; i < vecl.size(); i++)
	{
		std::cout << RED << "error clear(): size not updated at zero" << RESET << std::endl;
		break;
	}
	printVector(vecl, ofs);

	VECTOR<char> vecl2(10, 'x');

	vecl2.clear();
	vecl2.clear();
	vecl2.clear();
	vecl2.clear();
	for (VECTOR<char>::size_type i = 0; i < vecl2.size(); i++)
	{
		std::cout << RED << "error clear(): size not updated at zero" << RESET << std::endl;
		break;
	}
	printVector(vecl2, ofs);
	std::cout << GREEN << ".clear() ok" << RESET << std::endl;
	
	//-------------SWAP()----------------
	std::cout << YELLOW << ".swap() testing" << RESET << std::endl;

	VECTOR<std::string>	vecStr(4, "hola");
	VECTOR<std::string>	vecStr2(7, "hi");

	ofs << "vecStr: ";
	printVector(vecStr, ofs);
	ofs << "vecStr2: ";
	printVector(vecStr2, ofs);
	
	vecStr.swap(vecStr2);
	
	ofs << "after swap: " << std::endl;
	
	ofs << "vecStr: ";
	printVector(vecStr, ofs);
	ofs << "vecStr2: ";
	printVector(vecStr2, ofs);
	if ((vecStr.size() != 7 || vecStr.capacity() != 7) || (vecStr2.size() != 4 || vecStr2.capacity() != 4))
		std::cout << RED << "error swap(): invalid attributes" << RESET << std::endl;

	for (VECTOR<std::string>::size_type i = 0; i < vecStr.size(); i++)
	{
		if (vecStr[i].compare("hi") != 0)
			std::cout << RED << "error swap(): values are the same as before" << RESET << std::endl;
	}
	for (VECTOR<std::string>::size_type i = 0; i < vecStr2.size(); i++)
	{
		if (vecStr2[i].compare("hola") != 0)
			std::cout << RED << "error swap(): values are the same as before" << RESET << std::endl;
	}

	std::cout << GREEN << ".swap() ok" << RESET << std::endl;

	//--------------INSERT()---------------
	std::cout << YELLOW << ".insert() testing" << RESET << std::endl;
	
	//insert(pos, value)
	VECTOR<int> vecTst(3, 100);
	VECTOR<int>::iterator it = vecTst.begin();

	it = vecTst.insert(it, 200);
	printVector(vecTst, ofs);
	if (it != vecTst.begin() || *it != 200)
		std::cout << RED << "error insert(): function do not return the correct iterator position" << RESET << std::endl;
	if (!(vecTst[0] == 200 && vecTst[1] == 100 && vecTst[2] == 100 && vecTst[3]))
		std::cout << RED << "error insert(): invalid values in container" << RESET << std::endl;
	if (vecTst.size() != 4)
	std::cout << RED << "error insert(): invalid size after call function" << RESET << std::endl;

	//insert(pos, n, value)

	VECTOR<double> vecc(4, 24.58);

	vecc.insert(vecc.end(), 2, 1999.99);
	printVector(vecc, ofs);
	if (!(vecc[0] == 24.58 && vecc[1] == 24.58 && vecc[2] == 24.58 && vecc[3] == 24.58 && vecc[4] == 1999.99 && vecc[5] == 1999.99))
		std::cout << RED << "error insert(): invalid values in container" << RESET << std::endl;
	if (vecc.size() != 6)
		std::cout << RED << "error insert(): invalid size after call function" << RESET << std::endl;

	//insert(pos, first, end)
	VECTOR<int> vecTst2(2, -42);
	VECTOR<int> vecTst3(6, 33);

	vecTst2.insert(vecTst2.begin() + 1, vecTst3.begin(), vecTst3.end());
	printVector(vecTst2, ofs);
	if (!(vecTst2[0] == -42 && vecTst2[1] == 33 && vecTst2[2] == 33 && vecTst2[3] == 33 && vecTst2[4] == 33 &&
		vecTst2[5] == 33 && vecTst2[6] == 33 && vecTst2[7] == -42))
		std::cout << RED << "error insert(): invalid values in container" << RESET << std::endl;
	if (vecTst2.size() != 8)
	std::cout << RED << "error insert(): invalid size after call function" << RESET << std::endl;

	std::cout << GREEN << ".insert() ok" << RESET << std::endl;
}

#endif
