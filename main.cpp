/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:54:50 by nayache           #+#    #+#             */
/*   Updated: 2021/11/19 17:31:14 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <iostream>
#include <memory>

int	main(void)
{
//	std::vector<int> arr(12, 44);
//	ft::vector<char> test(arr.begin(), arr.end());
	ft::vector<char> test(10, 42);
//	ft::vector<int> test2;

	/*for (std::vector<char>::iterator it = test.begin(); it != test.end(); it++)
	{
		std::cout << '[' << *it << ']';
	}*/
	test.print();
//	test2.print();

//	std::cout << test.getData();

	return (0);
}
