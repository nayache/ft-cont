/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_constructors.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:22:26 by nayache           #+#    #+#             */
/*   Updated: 2021/12/28 18:17:00 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_CONSTRUCTORS_HPP
# define TEST_CONSTRUCTORS_HPP
# include <vector>
# include <iostream>
# include "vector.hpp"
# include "colors.hpp"
# define vector ft::vector

template <typename T>
void	printAttributes(vector<T> vec)
{
	std::cout << "size: " << vec.size() << " ";
	std::cout << "capacity: " << vec.capacity() << std::endl;
}

template <typename T>
void	printVector(vector<T> vec)
{
	prfloatAttributes(vec);

	for (typename vector<T>::size_type i = 0; i < vec.size(); i++)
	{
		std::cout << "[" << vec[i] << "]";
		if (i + 1 < vec.size())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void	test_constructors(void)
{
	std::cout << YELLOW << "vector() testing:" << RESET << std::endl;
	vector<float> defaultVec;
	if (defaultVec.size() != 0)
		std::cout << RED << "error default constructor: size not equal at 0" << RESET << std::endl;
	if (defaultVec.capacity() != 0)
		std::cout << RED << "error default constructor: capacity not equal at 0" << RESET << std::endl;
	prfloatVector(defaultVec);
	
	std::cout << YELLOW << "vector(n) testing:" << RESET << std::endl;
	vector<float> Vec(3);
	if (Vec.size() != 3)
		std::cout << RED << "error constructor(n): size not equal at 0" << RESET << std::endl;
	if (Vec.capacity() != 3)
		std::cout << RED << "error default constructor: capacity no at the right value" << RESET << std::endl;
	prfloatVector(Vec);
	if (Vec[0] || Vec[1] || Vec[2])
		std::cout << RED << "error default constructor: value not at 0" << RESET << std::endl;
	
	std::cout << YELLOW << "vector(n, v) testing:" << RESET << std::endl;
	vector<float> fillVec(5, 50.5);
	if (fillVec.size() != 5)
		std::cout << RED << "error constructor(n, v): size not at the right value" << RESET << std::endl;
	if (fillVec.capacity() != 5)
		std::cout << RED << "error constructor(n, v): capacity not at the right value" << RESET << std::endl;
	prfloatVector(fillVec);
	for (typename vector<float>::size_type i = 0; i < 5; i++)
	{
		std::cout << fillVec[i] << "\n";
		if (fillVec[i] != 50.5)
			std::cout << RED << "error constructor(n, v): elements not at the right value" << RESET << std::endl;
	}
	
	std::cout << YELLOW << "vector(it, ite) testing:" << RESET << std::endl;
	vector<float> rangeVec(fillVec.begin(), fillVec.end());
	if (rangeVec.size() != 5)
		std::cout << RED << "error constructor(begin, end): size not at the right value" << RESET << std::endl;
	if (rangeVec.capacity() != 5)
		std::cout << RED << "error constructor(begin, end): capacity not at the right value" << RESET << std::endl;
	prfloatVector(rangeVec);
	for (typename vector<float>::size_type i = 0; i < 5; i++)
	{
		if (rangeVec[i] != 50.5)
			std::cout << RED << "error constructor(begin, end): elements not at the right value" << RESET << std::endl;
	}
	
	std::cout << YELLOW << "vector(vector& copy) testing:" << RESET << std::endl;
	vector<float> copyVec(rangeVec);
	if (copyVec.size() != 5)
		std::cout << RED << "error copy constructor: size not at the right value" << RESET << std::endl;
	if (copyVec.capacity() != 5)
		std::cout << RED << "error copy constructor: capacity not at the right value" << RESET << std::endl;
	prfloatVector(copyVec);
	if (&(copyVec[0]) == &(rangeVec[0]))
		std::cout << RED << "error copy constructor: Not a deep copy" << RESET << std::endl;
	for (typename vector<float>::size_type i = 0; i < 5; i++)
	{
		if (copyVec[i] != 50.5)
			std::cout << RED << "error copy constructor: elements not at the right value" << RESET << std::endl;
	}
	
	std::cout << YELLOW << "vector operator=(vector& copy) testing:" << RESET << std::endl;
	vector<float> copyOperatorVec = copyVec;
	if (copyVec.size() != 5)
		std::cout << RED << "error assign constructor: size not at the right value" << RESET << std::endl;
	if (copyVec.capacity() != 5)
		std::cout << RED << "error assign constructor: capacity not at the right value" << RESET << std::endl;
	prfloatVector(copyOperatorVec);	
	if (&(copyOperatorVec[0]) == &(copyVec[0]))
		std::cout << RED << "error assign copy constructor: Not a deep copy" << RESET << std::endl;
	for (typename vector<float>::size_type i = 0; i < 5; i++)
	{
		if (copyOperatorVec[i] != 50.5)
			std::cout << RED << "error assign copy constructor: elements not at the right value" << RESET << std::endl;
	}

	float	tab[] = {3, 30, 300, 3000};
	std::cout << YELLOW << "vector(tab.it, tab.ite) testing:" << RESET << std::endl;
	vector<float>::iterator it(tab);
	vector<float> tabVec(it, it + 4);
	if (tabVec.size() != 4)
		std::cout << RED << "error constructor(tab.begin, tab.end): size not at the right value" << RESET << std::endl;
	if (tabVec.capacity() != 4)
		std::cout << RED << "error constructor(tab.begin, tab.end): capacity not at the right value" << RESET << std::endl;
	prfloatVector(tabVec);
	typename vector<float>::value_type val = 3;
	for (typename vector<float>::size_type i = 0; i < 4; i++)
	{
		std::cout << val << std::endl;
		if (tabVec[i] != val)
			std::cout << RED << "error constructor(tab.begin, tab.end): elements not at the right value" << RESET << std::endl;
		val *= 10;
	}
	std::cout << GREEN << "vector constructors ok" << RESET << std::endl;
}

#endif
