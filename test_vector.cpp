/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:54:08 by nayache           #+#    #+#             */
/*   Updated: 2021/12/30 09:16:57 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int	main()
{
	std::cout << "\e[1;45m----------CONSTRUCTORS-TEST------:" << RESET << std::endl;
	test_constructors();
	std::cout << "\e[1;45m----------ITERATORS----TEST------:" << RESET << std::endl;
	test_iterators();
	std::cout << "\e[1;45m----------CAPACITY-----TEST------:" << RESET << std::endl;
	test_capacity();
	std::cout << "\e[1;45m-------ELEMENTS_ACCESS-TEST------:" << RESET << std::endl;
	test_access();
	std::cout << "\e[1;45m----------MODIFIERS----TEST------:" << RESET << std::endl;
	test_modifiers();
	return (0);	
}
