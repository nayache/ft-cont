/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_element_access.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:10:35 by nayache           #+#    #+#             */
/*   Updated: 2021/12/29 11:18:29 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_ELEMENT_ACCESS_HPP
# define TEST_ELEMENT_ACCESS_HPP

# include "test.hpp"

void	test_access(void)
{
	//-------OPERATOR[]---------
	std::cout << YELLOW << "operator[] testing" << RESET << std::endl;
	VECTOR<double> test(6, 0);
	test[0] = 11.11;
	test[1] = 22.11;
	test[2] = 33.11;
	test[3] = 44.11;
	test[4] = 55.11;
	test[5] = 66.11;
	typename VECTOR<double>::value_type val = 11.11;
	for (typename VECTOR<double>::size_type i = 0; i < test.size(); i++)
	{
		if (test[i] != (11.11 + (i * 11)))
			std::cout << RED << "error operator[]: not good value" << RESET << std::endl;
		std::cout << "[" << test[i] << "]";
		if (i + 1 < test.size())
			std::cout << " ";
		val += 11;
	}

	typename VECTOR<double>::size_type i = 0;
	if (test[i + 4] != 55.11)
		std::cout << RED << "error operator[]: not good value" << RESET << std::endl;
	
	i += 2;

	if (test[i - 2] != 11.11)
		std::cout << RED << "error operator[]: not good value" << RESET << std::endl;
	
	std::cout << std::endl;

	//----------AT()----------
	std::cout << YELLOW << ".at() testing" << RESET << std::endl;

	VECTOR<std::string> testAt(5);
	for (typename VECTOR<std::string>::size_type i = 0; i < 5; i++)
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
	for (typename VECTOR<std::string>::size_type i = 0; i < 5; i++)
	{
		std::cout << "(" << testAt.at(i) << ")";
		if (strs[i].compare(testAt.at(i)) != 0)
			std::cout << RED << "error .at(): point to invaid value" << RESET << std::endl;
		if (i + 1 < 5)
			std::cout << " ";
	}
	std::cout << std::endl;
	
	typename VECTOR<std::string>::size_type j = 0;
	testAt.at(j + 2) = "modify";
	std::string testStr = testAt.at(2);
	std::cout << testAt.at(2) << std::endl;
	if (testStr.compare("modify") != 0)
		std::cout << RED << "error .at(): point to invaid value" << RESET << std::endl;
	
	j = 4;
	testAt.at(j - 3) = "new modify";
	testStr = testAt.at(1);
	std::cout << testAt.at(1) << std::endl;
	if (testStr.compare("new modify") != 0)
		std::cout << RED << "error .at(): point to invaid value" << RESET << std::endl;

	//test out of range exception
	try {
		testAt.at(10) = "new string";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << GREEN << ".at() ok" << RESET << std::endl;

	//---------FRONT()------------
	std::cout << YELLOW << ".front() testing" << RESET << std::endl;
	
	VECTOR<char> vect;
	vect.push_back('h');
	vect.push_back('e');
	vect.push_back('l');
	vect.push_back('l');
	vect.push_back('o');
	vect.push_back('!');
	std::cout << "-> " << vect.front() << std::endl;
	if (vect.front() != 'h')
		std::cout << RED << "error front(): front returns(reference) is a bad value" << RESET << std::endl;
	for (typename VECTOR<char>::size_type i = 0; i < 6; i++)
	{
		std::cout << vect.front();
		vect.erase(vect.begin());
	}
	std::cout << std::endl;
	
	VECTOR<char> vect2(1, 'Z');
	std::cout << "-> " << vect2.front() << std::endl;
	if (vect2.front() != 'Z')
		std::cout << RED << "error front(): front returns(reference) is a bad value" << RESET << std::endl;
	
	std::cout << GREEN << ".front() ok" << RESET << std::endl;

	//---------BACK()-------------
	std::cout << YELLOW << ".back() testing" << RESET << std::endl;

	VECTOR<std::string> tab;

	tab.push_back("only one element");
	std::cout << "[" << tab.back() << "]" << std::endl;
	if (tab.back() != "only one element")
		std::cout << RED << "error back(): back returns(reference) is a bad value" << RESET << std::endl;
	
	tab.back() = "only one element is modified";
	std::cout << "[" << tab.back() << "]" << std::endl;
	if (tab.back() != "only one element is modified")
		std::cout << RED << "error back(): back returns(reference) is a bad value" << RESET << std::endl;
	
	VECTOR<std::string> tab2;
	tab2.push_back("UN");
	tab2.push_back("DEUX");
	tab2.push_back("TROIS");
	tab2.push_back("QUATRE");
	std::string str[4] = {"QUATRE", "TROIS", "DEUX", "UN"};
	for (typename VECTOR<char>::size_type i = 0; i < 4; i++)
	{
		std::cout << tab2.back();
		if (str[i].compare(tab2.back()) != 0)
			std::cout << RED << "error back(): back returns(reference) is a bad value" << RESET << std::endl;
		if (i + 1 < 4)
			std::cout << " ";
		tab2.pop_back();
	}
	std::cout << std::endl;

	std::cout << GREEN << ".back() ok" << RESET << std::endl;
}

#endif
