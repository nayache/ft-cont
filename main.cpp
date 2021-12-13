/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:54:50 by nayache           #+#    #+#             */
/*   Updated: 2021/12/13 13:59:55 by nayache          ###   ########.fr       */
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
	ft::vector<double> arr0(11);
	ft::vector<double> arr2(10, (double)101.99);
	ft::vector<double> arr(10);

	for (ft::vector<double>::iterator it = arr2.begin(); it != arr2.end(); it++)
		std::cout << *it << std::endl;

	arr2.assign(10, 22.33);
	arr.assign(arr2.begin(), arr2.end());
	for (ft::vector<double>::iterator it = arr.begin(); it != arr.end(); it++)
		std::cout << *it << std::endl;
/*	
	ft::vector<double> arr3(10, 90);
	for (ft::vector<double>::iterator it = arr3.begin(); it != arr3.end(); it++)
		ft::cout << *it << ft::endl;*/
	
	return (0);
}
