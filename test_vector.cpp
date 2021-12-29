/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:54:08 by nayache           #+#    #+#             */
/*   Updated: 2021/12/29 10:33:18 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int	main()
{
	std::cout << "\e[1;44mCONSTRUCTORS testing:" << RESET << std::endl;
	test_constructors();
	std::cout << "\e[1;44mITERATORS testing:" << RESET << std::endl;
	test_iterators();
	std::cout << "\e[1;44mCAPACITY testing:" << RESET << std::endl;
	test_capacity();
	std::cout << "\e[1;44mELEMENTS_ACCESS testing:" << RESET << std::endl;
	test_access();
	return (0);	
}
