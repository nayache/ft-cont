/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:54:08 by nayache           #+#    #+#             */
/*   Updated: 2022/01/06 18:02:12 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <unistd.h>

int	main()
{
	std::ofstream file;
	file.open(".log");
	std::cout << "\e[1;45m----------CONSTRUCTORS-TEST------:" << RESET << std::endl;
	sleep(1);
	test_constructors(file);
	sleep(1);
	std::cout << "\e[1;45m----------ITERATORS----TEST------:" << RESET << std::endl;
	sleep(1);
	test_iterators(file);
	sleep(1);
	std::cout << "\e[1;45m----------CAPACITY-----TEST------:" << RESET << std::endl;
	sleep(1);
	test_capacity();
	sleep(1);
	std::cout << "\e[1;45m-------ELEMENTS_ACCESS-TEST------:" << RESET << std::endl;
	sleep(1);
	test_access(file);
	sleep(1);
	std::cout << "\e[1;45m----------MODIFIERS----TEST------:" << RESET << std::endl;
	sleep(1);
	test_modifiers(file);
	return (0);	
}
