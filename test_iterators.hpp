/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterators.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:22:26 by nayache           #+#    #+#             */
/*   Updated: 2021/12/28 17:33:46 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_ITERATORS_HPP
# define TEST_ITERATORS_HPP
# include "colors.hpp"
# include <vector>
# include <iostream>
# include "vector.hpp"

void	test_iterators(void)
{
	//----------BEGIN()/END()---------
	std::cout << YELLOW << ".begin() && .end() testing" << RESET << std::endl;

	vector<int> vec(1, 2);
	vec.push_back(4);
	vec.push_back(6);
	vec.push_back(8);
	vec.push_back(10);

	vector<int>::iterator it;
	vector<int>::iterator ite;
	it = vec.begin();
	ite = vec.end();
	if (&(*it) != &(vec[0]))
		std::cout << RED << "error: begin iterator don't point to the first element" << RESET << std::endl;
	if (&(*ite) != &(vec[vec.size()]))
		std::cout << RED << "error: begin iterator don't point to the last element + 1" << RESET << std::endl;

	vector<int>::value_type v = 2;
	for (typename vector<int>::size_type i = 0; i < vec.size(); i++)
	{
		std::cout << *it << " " << std::endl;
		if (*it != v)
		{
			std::cout << RED << "error: iterator don't point a good value" << RESET << std::endl;
			break;
		}
		it++;
		v += 2;
	}
	if (it == vec.end())
		std::cout << "vector::iterator are iterable" << std::endl;
	std::cout << GREEN << ".begin() && .end() ok" << RESET << std::endl;

	//---------RBEGIN()/REND()--------
	std::cout << YELLOW << ".rbegin() && .rend() testing" << RESET << std::endl;
	
	vector<int> rvec(1, 1);
	rvec.push_back(2);
	rvec.push_back(3);
	rvec.push_back(4);
	rvec.push_back(5);

	vector<int>::reverse_iterator rit;
	vector<int>::reverse_iterator rite;
	rit = rvec.rbegin();
	rite = rvec.rend();
	if (&(*rit) != &(rvec[rvec.size() - 1]))
		std::cout << RED << "error: rbegin iterator don't point to the last element" << RESET << std::endl;
	if (&(*rite) != &(rvec[-1]))
		std::cout << RED << "error: begin iterator don't point to the first element - 1" << RESET << std::endl;
	
	vector<int>::value_type val = 5;
	while (rit != rite)
	{
		std::cout << *rit << " " << std::endl;
		if (*rit != val)
		{
			std::cout << RED << "error: reverse_iterator don't point a good value" << RESET << std::endl;
			break;
		}
		val--;
		rit++;
	}
	if (rit == rvec.rend() - 1)
		std::cout << "vector::reverse_iterator are iterable" << std::endl;
	std::cout << GREEN << ".rbegin() && .rend() ok" << RESET << std::endl;
}

#endif
