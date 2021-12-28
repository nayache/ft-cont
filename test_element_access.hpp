/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_element_access.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:10:35 by nayache           #+#    #+#             */
/*   Updated: 2021/12/28 19:04:41 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_ELEMENT_ACCESS_HPP
# define TEST_ELEMENT_ACCESS_HPP
# include <vector>
# include <iostream>
# include "vector.hpp"
# include "colors.hpp"

void	test_access(void)
{
	//-------OPERATOR[]---------
	std::cout << YELLOW << "operator[] testing" << RESET << std::endl;
	vector<double> test(6, 0);
	test[0] = 11.11;
	test[1] = 22.11;
	test[2] = 33.11;
	test[3] = 44.11;
	test[4] = 55.11;
	test[5] = 66.11;
	typename vector<double>::value_type val = 11.11;
	for (typename vector<double>::size_type i = 0; i < test.size(); i++)
	{
		if (test[i] != (11.11 + (i * 11)))
			std::cout << RED << "error operator[]: not good value" << RESET << std::endl;
		std::cout << "[" << test[i] << "]";
		if (i + 1 < test.size())
			std::cout << " ";
		val += 11;
	}

	typename vector<double>::size_type i = 0;
	if (test[i + 4] != 55.11)
		std::cout << RED << "error operator[]: not good value" << RESET << std::endl;
	
	i += 2;

	if (test[i - 2] != 11.11)
		std::cout << RED << "error operator[]: not good value" << RESET << std::endl;
	
	std::cout << std::endl;

	//------AT()-----
}

#endif
