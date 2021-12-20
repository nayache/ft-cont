/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:54:50 by nayache           #+#    #+#             */
/*   Updated: 2021/12/20 12:45:25 by nayache          ###   ########.fr       */
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
    ft::vector<std::string> foo(3, "slt");
    ft::vector<std::string> bar(5, "holaa");

	foo.swap(bar);
	std::cout << " foo size: " << foo.size() << " capacity: " << foo.capacity() << std::endl;
    for (ft::vector<std::string>::iterator it = foo.begin(); it != foo.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
	std::cout << "bar size: " << bar.size() << " capacity: " << bar.capacity() << std::endl;
    for (ft::vector<std::string>::iterator it = bar.begin(); it != bar.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
	bar.clear();
	bar.push_back("1");
	bar.push_back("2");
	bar.push_back("3");
	bar.push_back(";(");
	bar.pop_back();
	bar.insert(bar.end(), foo.begin(), foo.end());
	bar.push_back("NN");
	bar.push_back("%");
	std::cout << "bar size: " << bar.size() << " capacity: " << bar.capacity() << std::endl;
    for (ft::vector<std::string>::iterator it = bar.begin(); it != bar.end(); it++)
	{
        std::cout << *it << " ";
	}
	std::cout << std::endl;	
	ft::vector<std::string>::iterator test = bar.erase(bar.end() - 1);
	std::cout << *test << std::endl;
	std::cout << "bar size: " << bar.size() << " capacity: " << bar.capacity() << std::endl;
    for (ft::vector<std::string>::iterator it = bar.begin(); it != bar.end(); it++)
	{
        std::cout << *it << " ";
	}
	std::cout << std::endl;	
	return (0);
}
