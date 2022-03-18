/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptest.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:09:17 by nayache           #+#    #+#             */
/*   Updated: 2022/03/18 18:49:02 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <vector>
#include "map.hpp"
#include <iostream>
#include <utility>
#include "includes/pair.hpp"
#include "Bst.hpp"
# include "map_iterator.hpp"
# include "includes/containers/vector.hpp"
int	main()
{
	ft::map<int, std::string> testmap;

/*	testmap.insert(ft::pair<int, std::string>(44, "text"));
	testmap.insert(ft::pair<int, std::string>(11, "text"));
	testmap.insert(ft::pair<int, std::string>(45, "text"));
	testmap.insert(ft::pair<int, std::string>(-3, "text"));
	testmap.insert(ft::pair<int, std::string>(-7, "text"));
	testmap.insert(ft::pair<int, std::string>(0, "text"));
	testmap.insert(ft::pair<int, std::string>(40, "text"));
	testmap.insert(ft::pair<int, std::string>(31, "text"));
	testmap.insert(ft::pair<int, std::string>(39, "text"));
	testmap.insert(ft::pair<int, std::string>(44, "text"));
	testmap.insert(ft::pair<int, std::string>(43, "text"));
	testmap.insert(ft::pair<int, std::string>(42, "text"));
	ft::pair<ft::map<int, std::string>::iterator, bool> ret;
	ret = testmap.insert(ft::pair<int, std::string>(49, "zero"));
	ret = testmap.insert(ft::pair<int, std::string>(46, "zero"));
	ret = testmap.insert(ft::pair<int, std::string>(47, "zero"));
	ret = testmap.insert(ft::pair<int, std::string>(50, "zero"));
	ret = testmap.insert(ft::pair<int, std::string>(50, "zero"));*/
//	std::cout << ret.first->first << " " << ret.first->second << " " << ret.second << std::endl;
//	ft::map<int, std::string>::iterator itt = testmap.begin();
//	ft::map<int, std::string>::iterator itt;
//	itt++;
//	itt++;
//	itt++;
//	itt++;
//	testmap.insert(ft::pair<int, std::string>(1, "newNode"));
//	std::cout << *itt << std::endl;
//	itt = testmap.begin();
//	testmap.erase(47);
//	testmap.erase(44);
	for (int i = 0; i < 500000; i++)
		testmap.insert(ft::pair<int, std::string>(i, "babar"));
//	itt = testmap.begin();
/*	while (itt != testmap.end())
	{
		std::cout << *itt << std::endl;
		itt++;
	}*/
//	for (int i = 0; i < 13; i++)
//	{
//		testmap.insert(ft::pair<int, std::string>(i, "babar"));
//	}
//	for (std::map<int, std::string>::iterator it = testmap.begin(); it != testmap.end(); it++)
//		std::cout << it->first << std::endl;
/*	while (itt != testmap.end())
	{
		std::cout << *itt << std::endl;
		itt++;
	}*/
//	testmap.insert(itt, ft::pair<int, std::string>(-1, "newNode"));
//	ret = testmap.insert(ft::pair<int, std::string>(-3, "zero"));

//	testmap.print();
	return 0;
} 
