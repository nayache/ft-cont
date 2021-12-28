/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pain.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:53:52 by nayache           #+#    #+#             */
/*   Updated: 2021/12/22 16:13:29 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utility> 
#include <iostream> 
#include "pair.hpp"

int main()
{
	ft::pair<std::string *, std::string *> u;
	ft::pair<int, std::string> test(142, "ici");
	std::cout << test.first << std::endl;
	std::cout << test.second << std::endl;
	ft::pair<int, std::string> test2(142, "ici");
	std::cout << test2.first << std::endl;
	std::cout << test2.second << std::endl;
	test.swap(test2);
	std::cout << test.first << std::endl;
	std::cout << test.second << std::endl;
	std::cout << test2.first << std::endl;
	std::cout << test2.second << std::endl;
	if (test == test2)
		std::cout << "equal" << std::endl;
	return (0);
}
