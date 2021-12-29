/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_capacity.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:22:26 by nayache           #+#    #+#             */
/*   Updated: 2021/12/29 10:37:48 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_CAPACITY_HPP
# define TEST_CAPACITY_HPP
# include "test.hpp"

void	test_capacity(void)
{
	//--------SIZE()----------------
	std::cout << YELLOW << ".size() testing" << RESET << std::endl;
	
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
	
	std::cout << GREEN << ".size(): ok" << RESET << std::endl;
	//max_size()
	
	//-------------CAPACITY()-------------
	std::cout << YELLOW << ".capacity() testing" << RESET << std::endl;
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
	
	std::cout << GREEN << ".capacity(): ok" << RESET << std::endl;

	//-------------EMPTY()-----------

	std::cout << YELLOW << ".empty() testing" << RESET << std::endl;

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
	
	std::cout << GREEN << ".empty() ok" << RESET << std::endl;

	//---------RESERVE()------------

	std::cout << YELLOW << ".reserve() testing" << RESET << std::endl;

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
	
	std::cout << GREEN << ".reserve() ok" << RESET << std::endl;

	//---------RESIZE()-----------

	std::cout << YELLOW << ".resize() testing" << RESET << std::endl;
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
	
	std::cout << GREEN << ".resize() ok" << RESET << std::endl;
	
	//----------MAXSIZE()--------
}
#endif
