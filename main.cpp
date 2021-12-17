/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:54:50 by nayache           #+#    #+#             */
/*   Updated: 2021/12/17 14:34:59 by nayache          ###   ########.fr       */
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
	std::vector<std::string> arr3(10, "ahah");

	arr3.pop_back();
	arr3.push_back(static_cast<std::string>("1st"));
	
	std::cout << "size " << arr3.size() << std::endl;
	std::cout << "capacity " << arr3.capacity() << std::endl;
	
//	arr3.insert(arr3.begin(), "inserer");
	
	for (std::vector<std::string>::iterator it = arr3.begin(); it != arr3.end(); ++it)
	{
		std::cout << "(" << *it << ")" << std::endl;
	}
	std::vector<std::string> arr90(1, "ahah");
	std::cout << arr3.max_size() << std::endl;
	std::cout << arr90.back() << std::endl;
	std::cout << arr90.front() << std::endl;
	return (0);
}
