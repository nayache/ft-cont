/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:54:08 by nayache           #+#    #+#             */
/*   Updated: 2022/05/03 16:20:28 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

void	test_constructors(std::ofstream& ofs)
{
	VECTOR<float> defaultVec;
	if (defaultVec.size() != 0)
		std::cout << RED << "error default constructor: size not equal at 0" << RESET << std::endl;
	if (defaultVec.capacity() != 0)
		std::cout << RED << "error default constructor: capacity not equal at 0" << RESET << std::endl;
	printVector(defaultVec, ofs);
	
	VECTOR<float> Vec(3);
	if (Vec.size() != 3)
		std::cout << RED << "error constructor(n): size not equal at 0" << RESET << std::endl;
	if (Vec.capacity() != 3)
		std::cout << RED << "error default constructor: capacity no at the right value" << RESET << std::endl;
	printVector(Vec, ofs);
	if (Vec[0] || Vec[1] || Vec[2])
		std::cout << RED << "error default constructor: value not at 0" << RESET << std::endl;
	
	VECTOR<float> fillVec(5, 50.5);
	if (fillVec.size() != 5)
		std::cout << RED << "error constructor(n, v): size not at the right value" << RESET << std::endl;
	if (fillVec.capacity() != 5)
		std::cout << RED << "error constructor(n, v): capacity not at the right value" << RESET << std::endl;
	printVector(fillVec, ofs);
	for (VECTOR<float>::size_type i = 0; i < 5; i++)
	{
		ofs << fillVec[i] << std::endl;
		if (fillVec[i] != 50.5)
			std::cout << RED << "error constructor(n, v): elements not at the right value" << RESET << std::endl;
	}
	
	VECTOR<float> rangeVec(fillVec.begin(), fillVec.end());
	if (rangeVec.size() != 5)
		std::cout << RED << "error constructor(begin, end): size not at the right value" << RESET << std::endl;
	if (rangeVec.capacity() != 5)
		std::cout << RED << "error constructor(begin, end): capacity not at the right value" << RESET << std::endl;
	printVector(rangeVec, ofs);
	for (VECTOR<float>::size_type i = 0; i < 5; i++)
	{
		if (rangeVec[i] != 50.5)
			std::cout << RED << "error constructor(begin, end): elements not at the right value" << RESET << std::endl;
	}
	
	VECTOR<float> copyVec(rangeVec);
	if (copyVec.size() != 5)
		std::cout << RED << "error copy constructor: size not at the right value" << RESET << std::endl;
	if (copyVec.capacity() != 5)
		std::cout << RED << "error copy constructor: capacity not at the right value" << RESET << std::endl;
	printVector(copyVec, ofs);
	if (&(copyVec[0]) == &(rangeVec[0]))
		std::cout << RED << "error copy constructor: Not a deep copy" << RESET << std::endl;
	for (VECTOR<float>::size_type i = 0; i < 5; i++)
	{
		if (copyVec[i] != 50.5)
			std::cout << RED << "error copy constructor: elements not at the right value" << RESET << std::endl;
	}
	
	VECTOR<float> copyOperatorVec = copyVec;
	if (copyVec.size() != 5)
		std::cout << RED << "error assign constructor: size not at the right value" << RESET << std::endl;
	if (copyVec.capacity() != 5)
		std::cout << RED << "error assign constructor: capacity not at the right value" << RESET << std::endl;
	printVector(copyOperatorVec, ofs);	
	if (&(copyOperatorVec[0]) == &(copyVec[0]))
		std::cout << RED << "error assign copy constructor: Not a deep copy" << RESET << std::endl;
	for (VECTOR<float>::size_type i = 0; i < 5; i++)
	{
		if (copyOperatorVec[i] != 50.5)
			std::cout << RED << "error assign copy constructor: elements not at the right value" << RESET << std::endl;
	}

	float	tab[] = {3, 30, 300, 3000};
	VECTOR<float>::iterator it(tab);
	VECTOR<float> tabVec(it, it + 4);
	if (tabVec.size() != 4)
		std::cout << RED << "error constructor(tab.begin, tab.end): size not at the right value" << RESET << std::endl;
	if (tabVec.capacity() != 4)
		std::cout << RED << "error constructor(tab.begin, tab.end): capacity not at the right value" << RESET << std::endl;
	printVector(tabVec, ofs);
	VECTOR<float>::value_type val = 3;
	for (VECTOR<float>::size_type i = 0; i < 4; i++)
	{
		ofs << val << std::endl;
		if (tabVec[i] != val)
			std::cout << RED << "error constructor(tab.begin, tab.end): elements not at the right value" << RESET << std::endl;
		val *= 10;
	}
}

void	test_iterators(std::ofstream& ofs)
{
	//----------BEGIN()/END()---------

	VECTOR<int> vec(1, 2);
	vec.push_back(4);
	vec.push_back(6);
	vec.push_back(8);
	vec.push_back(10);

	VECTOR<int>::iterator it;
	VECTOR<int>::iterator ite;
	it = vec.begin();
	ite = vec.end();
	if (&(*it) != &(vec[0]))
		std::cout << RED << "error: begin iterator don't point to the first element" << RESET << std::endl;
	if (&(*ite) != &(vec[vec.size()]))
		std::cout << RED << "error: begin iterator don't point to the last element + 1" << RESET << std::endl;

	VECTOR<int>::value_type v = 2;
	for (VECTOR<int>::size_type i = 0; i < vec.size(); i++)
	{
		ofs << *it << " " << std::endl;
		if (*it != v)
		{
			std::cout << RED << "error: iterator don't point a good value" << RESET << std::endl;
			break;
		}
		it++;
		v += 2;
	}

	//---------RBEGIN()/REND()--------
	
	VECTOR<int> rvec(1, 1);
	rvec.push_back(2);
	rvec.push_back(3);
	rvec.push_back(4);
	rvec.push_back(5);

	VECTOR<int>::reverse_iterator rit;
	VECTOR<int>::reverse_iterator rite;
	rit = rvec.rbegin();
	rite = rvec.rend();
	if (&(*rit) != &(rvec[rvec.size() - 1]))
		std::cout << RED << "error: rbegin iterator don't point to the last element" << RESET << std::endl;
	if (&(*rite) != &(rvec[-1]))
		std::cout << RED << "error: begin iterator don't point to the first element - 1" << RESET << std::endl;
	
	VECTOR<int>::value_type val = 5;
	while (rit != rite)
	{
		ofs << *rit << " " << std::endl;
		if (*rit != val)
		{
			std::cout << RED << "error: reverse_iterator don't point a good value" << RESET << std::endl;
			break;
		}
		val--;
		rit++;
	}
	printVector(rvec, ofs);
	if (rit == rvec.rend() - 1)
		std::cout << "VECTOR::reverse_iterator are iterable" << std::endl;
}

void	test_capacity(void)
{
	//--------SIZE()----------------
	
	VECTOR<int> vec;
	if (vec.size() != 0)
		std::cout << RED << "error: size invalid" << RESET << std::endl;
	
	VECTOR<int> vec1(10);
	if (vec1.size() != 10)
		std::cout << RED << "error: size invalid" << RESET << std::endl;
	
	VECTOR<int> vec2(4, 42);
	if (vec2.size() != 4)
		std::cout << RED << "error: size invalid" << RESET << std::endl;
	
	VECTOR<int> vec3(vec2.begin(), vec2.end());
	// modify size with push_back()/pop_back()
	vec3.push_back(1);
	vec3.push_back(1);
	vec3.push_back(1);
	vec3.pop_back();
	if (vec3.size() != 6)
		std::cout << RED << "error: size invalid" << RESET << std::endl;
	
	//-------------CAPACITY()-------------
	
	VECTOR<int> test;
	if (test.capacity() != 0)
		std::cout << RED << "error: capacity invalid" << RESET << std::endl;
	
	VECTOR<int> test2(10);
	if (test2.capacity() != 10)
		std::cout << RED << "error: capacity invalid" << RESET << std::endl;
	
	VECTOR<int> test3(4, 42);
	if (test3.capacity() != 4)
		std::cout << RED << "error: capacity invalid" << RESET << std::endl;
	// modify capacity with push_back()
	test3.push_back(1);
	test3.push_back(1);
	test3.push_back(1);
	if (test3.capacity() < 7)
		std::cout << RED << "error: capacity invalid" << RESET << std::endl;
	
	// modify size with pop_back() must doesnt change capacity !
	test3.pop_back();
	test3.pop_back();
	test3.pop_back();
	test3.pop_back();
	test3.pop_back();
	test3.pop_back();
	if (test3.capacity() < 7)
		std::cout << RED << "error: capacity invalid" << RESET << std::endl;
	
	//-------------EMPTY()-----------

	VECTOR<int> e;
	if (e.empty() == false)
		std::cout << RED << "error empty: invalid value" << RESET << std::endl;
	
	VECTOR<int> e1(5, 30);
	if (e1.empty() == true)
		std::cout << RED << "error empty: invalid value" << RESET << std::endl;
	e1.pop_back();
	e1.pop_back();
	e1.pop_back();
	e1.pop_back();
	e1.pop_back();
	if (e1.empty() == false)
		std::cout << RED << "error empty: invalid value" << RESET << std::endl;
	
	//---------RESERVE()------------

	VECTOR<int> res(4, 2);
	VECTOR<int>::size_type start_size = res.size();
	
	res.reserve(4);
	res.reserve(3);
	res.reserve(2);
	res.reserve(1);
	if (res.capacity() != 4)
		std::cout << RED << "error reserve: not a correct capacity" << RESET << std::endl;
	if (res.size() != start_size)
		std::cout << RED << "error reserve: size has been affected" << RESET << std::endl;
	
	res.reserve(30);
	if (res.capacity() < 30)
		std::cout << RED << "error reserve: not a correct capacity" << RESET << std::endl;
	if (res.size() != start_size)
		std::cout << RED << "error reserve: size has been affected" << RESET << std::endl;
	
	res.reserve(500);
	if (res.capacity() < 500)
		std::cout << RED << "error reserve: not a correct capacity" << RESET << std::endl;
	if (res.size() != start_size)
		std::cout << RED << "error reserve: size has been affected" << RESET << std::endl;
	
	//---------RESIZE()-----------

	VECTOR<int> tst(10, 9);

	tst.resize(2);
	if (tst.size() != 2)
		std::cout << RED << "error resize: invalid size" << RESET << std::endl;
	
	tst.resize(5, 93);
	if (tst.size() != 5)
		std::cout << RED << "error resize: invalid size" << RESET << std::endl;
	if (tst[2] != 93 || tst[3] != 93 || tst[4] != 93)
		std::cout << RED << "error resize: n elements created not equal at 0" << RESET << std::endl;
	
	tst.resize(12);
	if (tst.size() != 12)
		std::cout << RED << "error resize: invalid size" << RESET << std::endl;
	if (tst.capacity() < 12)
		std::cout << RED << "error resize: invalid capacity after resize(n > .capacity())" << RESET << std::endl;
	if (tst[5] || tst[6] || tst[7] || tst[8] || tst[9] || tst[10] || tst[11])
		std::cout << RED << "error resize: n elements created not equal at 0" << RESET << std::endl;
	
	//----------MAXSIZE()--------
}

void	test_access(std::ofstream& ofs)
{
	//-------OPERATOR[]---------
	
	VECTOR<double> test(6, 0);
	test[0] = 11.11;
	test[1] = 22.11;
	test[2] = 33.11;
	test[3] = 44.11;
	test[4] = 55.11;
	test[5] = 66.11;
	VECTOR<double>::value_type val = 11.11;
	for (VECTOR<double>::size_type i = 0; i < test.size(); i++)
	{
		if (test[i] != (11.11 + (i * 11)))
			std::cout << RED << "error operator[]: not good value" << RESET << std::endl;
		ofs << "[" << test[i] << "]";
		val += 11;
	}

	VECTOR<double>::size_type i = 0;
	if (test[i + 4] != 55.11)
		std::cout << RED << "error operator[]: not good value" << RESET << std::endl;
	
	i += 2;

	if (test[i - 2] != 11.11)
		std::cout << RED << "error operator[]: not good value" << RESET << std::endl;
	
	ofs << std::endl;

	//----------AT()----------

	VECTOR<std::string> testAt(5);
	for (VECTOR<std::string>::size_type i = 0; i < 5; i++)
	{
		switch (i)
		{
			case 0:
				testAt.at(i) = "one";
				break;
			case 1:
				testAt.at(i) = "two";
				break;
			case 2:
				testAt.at(i) = "three";
				break;
			case 3:
				testAt.at(i) = "four";
				break;
			case 4:
				testAt.at(i) = "five";
				break;
		}
	}
	std::string strs[5] = {"one", "two", "three", "four", "five"};
	for (VECTOR<std::string>::size_type i = 0; i < 5; i++)
	{
		ofs << "(" << testAt.at(i) << ")";
		if (strs[i].compare(testAt.at(i)) != 0)
			std::cout << RED << "error .at(): point to invaid value" << RESET << std::endl;
	}
	ofs << std::endl;
	
	VECTOR<std::string>::size_type j = 0;
	testAt.at(j + 2) = "modify";
	std::string testStr = testAt.at(2);
	ofs << testAt.at(2) << std::endl;
	if (testStr.compare("modify") != 0)
		std::cout << RED << "error .at(): point to invaid value" << RESET << std::endl;
	
	j = 4;
	testAt.at(j - 3) = "new modify";
	testStr = testAt.at(1);
	ofs << testAt.at(1) << std::endl;
	if (testStr.compare("new modify") != 0)
		std::cout << RED << "error .at(): point to invaid value" << RESET << std::endl;

	//test out of range exception
	try {
		testAt.at(10) = "new string";
	}
	catch (std::exception& e)
	{
		ofs << e.what() << std::endl;
	}

	//---------FRONT()------------
	
	VECTOR<char> vect;
	vect.push_back('h');
	vect.push_back('e');
	vect.push_back('l');
	vect.push_back('l');
	vect.push_back('o');
	vect.push_back('!');
	ofs << "-> " << vect.front() << std::endl;
	if (vect.front() != 'h')
		std::cout << RED << "error front(): front returns(reference) is a bad value" << RESET << std::endl;
	for (VECTOR<char>::size_type i = 0; i < 6; i++)
	{
		ofs << vect.front();
		vect.erase(vect.begin());
	}
	ofs << std::endl;
	
	VECTOR<char> vect2(1, 'Z');
	ofs << "-> " << vect2.front() << std::endl;
	if (vect2.front() != 'Z')
		std::cout << RED << "error front(): front returns(reference) is a bad value" << RESET << std::endl;
	
	//---------BACK()-------------

	VECTOR<std::string> tab;

	tab.push_back("only one element");
	ofs << "[" << tab.back() << "]" << std::endl;
	if (tab.back() != "only one element")
		std::cout << RED << "error back(): back returns(reference) is a bad value" << RESET << std::endl;
	
	tab.back() = "only one element is modified";
	ofs << "[" << tab.back() << "]" << std::endl;
	if (tab.back() != "only one element is modified")
		std::cout << RED << "error back(): back returns(reference) is a bad value" << RESET << std::endl;
	
	VECTOR<char> tab2;
	tab2.push_back('A');
	tab2.push_back('B');
	tab2.push_back('C');
	tab2.push_back('D');
	printVector(tab2, ofs);
	char c = 'D';
	for (VECTOR<char>::size_type i = 0; i < 1; i++)
	{
		ofs << tab2.back();
		if (tab2.back() != c)
			std::cout << RED << "error back(): back returns(reference) is a bad value" << RESET << std::endl;
		tab2.pop_back();
		c--;
	}
	ofs << std::endl;
}

void	test_modifiers(std::ofstream& ofs)
{
	//----------PUSH_BACK()-----------
	
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
	ofs << std::endl;

	VECTOR<double> vec2(2, 4.4);

	vec2.push_back(12.12);
	if (*(vec2.end() - 1) != 12.12)
		std::cout << RED << "error push_back(): value push not at the end of array" << RESET << std::endl;
	
	//-----------POP_BACK()------------

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
	
	//------------ASSIGN()--------------
	
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

	//-----------ERASE()-------------

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
	
	//---------CLEAR()-------------
	
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
	
	//-------------SWAP()----------------

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

	//--------------INSERT()---------------
	
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
}

int	test_vector(std::ofstream& file)
{
	file << "\e[107m\e[1;30m" << "=============VECTOR TEST===============" << RESET << std::endl;
	test_constructors(file);
	test_iterators(file);
	test_capacity();
	test_access(file);
	test_modifiers(file);
	file << "\e[107m\e[1;30m" << "=============END VECTOR TEST===========" << RESET << std::endl;
	return (0);	
}
