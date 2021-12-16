/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:54:50 by nayache           #+#    #+#             */
/*   Updated: 2021/12/16 13:38:47 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "reverse_iterator.hpp"
#include <vector>
#include <list>
#include <iostream>
#include <memory>
#include <cstddef>
#include <typeinfo>
#include <stdlib.h>
int	main()
{
	std::vector<double> arr0(2, 103.4);
	std::vector<double> arr2(arr0.begin(), arr0.end());
	std::vector<double> arr(4, 4.4);

	std::cout << arr2.size() << std::endl;
	std::cout << arr2.capacity() << std::endl;
	arr2.assign(12, 22.33);
	std::cout << arr2.size() << std::endl;
	std::cout << arr2.capacity() << std::endl;
	std::vector<double>::iterator test = arr2.begin();
	for (std::vector<double>::iterator it = test; it != arr2.end(); it++)
		std::cout << '[' << *it << ']' << std::endl;

	arr.assign(arr2.begin(), arr2.end());
	for (std::vector<double>::iterator it = arr.begin(); it != arr.end(); it++)
		std::cout << *it << std::endl;
	
	std::vector<double> arr3(5, 90.9);
	arr3[0] = 0.93;
	arr3[1] = 77.93;
	arr3[4] = 199.93;
	for (std::vector<double>::const_iterator it = arr3.cbegin(); it != arr3.cend(); ++it)
	{
		std::cout << "(" << *it << ")" << std::endl;
	}
	return (0);
}
