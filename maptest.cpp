/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptest.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:09:17 by nayache           #+#    #+#             */
/*   Updated: 2022/03/08 17:15:28 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map.hpp"
#include <iostream>
#include <utility>
#include "includes/pair.hpp"
//#include "Bst.hpp"

int	main()
{
	ft::map<int, std::string> testmap;
//	testmap[33] = "salut";

	ft::pair<int, std::string> pair(42, "SALUT");
	ft::BinarySearchTree<int, std::string>	test;
//
	test._main->setValues(15, "fifteen");
	test.addNode(ft::pair<const int, std::string>(10, "ten"));
	test.addNode(ft::pair<const int, std::string>(20, "twenty"));
/*	test.addNode(9, "nine");
	test.addNode(11, "eleven");
	test.addNode(8, "eight");
	test.addNode(8, "lalala");
	std::cout << test._main->_pair.first << std::endl;
	std::cout << test._main->_left->_pair.first << std::endl;
	std::cout << test._main->_left->_left->_pair.first << std::endl;
	std::cout << test._main->_left->_left->_right->_pair.first << std::endl;
	std::cout << test._main->_left->_right->_pair.first << std::endl;
	std::cout << test._main->_left->_left->_right->_left->_pair.first << std::endl;
	std::cout << test._main->_left->_left->_right->_left->_pair.second << std::endl;*/
	return 0;
}
