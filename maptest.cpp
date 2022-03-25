/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptest.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:09:17 by nayache           #+#    #+#             */
/*   Updated: 2022/03/25 17:49:44 by nayache          ###   ########.fr       */
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

	testmap.insert(ft::pair<int, std::string>(5, "text"));
	testmap.insert(ft::pair<int, std::string>(0, "text"));
	testmap.insert(ft::pair<int, std::string>(10, "text"));
	testmap.insert(ft::pair<int, std::string>(20, "text"));
	testmap.insert(ft::pair<int, std::string>(15, "text"));
	testmap.insert(ft::pair<int, std::string>(11, "text"));
	testmap.insert(ft::pair<int, std::string>(-3, "text"));
	testmap.insert(ft::pair<int, std::string>(-3, "text"));
	testmap.insert(ft::pair<int, std::string>(-7, "text"));
/*	testmap.insert(ft::pair<int, std::string>(5, "text"));
	testmap.insert(ft::pair<int, std::string>(0, "text"));
	testmap.insert(ft::pair<int, std::string>(44, "text"));
	testmap.insert(ft::pair<int, std::string>(45, "text"));
	testmap.insert(ft::pair<int, std::string>(30, "text"));
	testmap.insert(ft::pair<int, std::string>(0, "text"));
	testmap.insert(ft::pair<int, std::string>(-3, "text"));
	testmap.insert(ft::pair<int, std::string>(-7, "text"));
	testmap.insert(ft::pair<int, std::string>(0, "text"));
	testmap.insert(ft::pair<int, std::string>(40, "text"));
	testmap.insert(ft::pair<int, std::string>(31, "text"));
	testmap.insert(ft::pair<int, std::string>(39, "text"));
	testmap.insert(ft::pair<int, std::string>(44, "text"));
	testmap.insert(ft::pair<int, std::string>(43, "text"));
	testmap.insert(ft::pair<int, std::string>(42, "text"));
	testmap.insert(ft::pair<int, std::string>(47, "text"));
	testmap.insert(ft::pair<int, std::string>(46, "text"));
	ft::pair<ft::map<int, std::string>::iterator, bool> ret;
	ret = testmap.insert(ft::pair<int, std::string>(65, "zero"));
	ret = testmap.insert(ft::pair<int, std::string>(56, "zero"));
	ret = testmap.insert(ft::pair<int, std::string>(49, "zero"));
	ret = testmap.insert(ft::pair<int, std::string>(46, "zero"));
	ret = testmap.insert(ft::pair<int, std::string>(47, "zero"));
	ret = testmap.insert(ft::pair<int, std::string>(50, "zero"));
	ret = testmap.insert(ft::pair<int, std::string>(50, "zero"));
	ret = testmap.insert(ft::pair<int, std::string>(55, "zero"));
	ret = testmap.insert(ft::pair<int, std::string>(58, "zero"));
	ret = testmap.insert(ft::pair<int, std::string>(60, "zero"));
	ret = testmap.insert(ft::pair<int, std::string>(65, "zero"));
	ret = testmap.insert(ft::pair<int, std::string>(65, "nnnno"));
//	std::cout << *ret.first << ret.second << std::endl;
	testmap.erase(-7);
	testmap.erase(0);
	testmap.erase(44);
	testmap.erase(45);
	testmap.erase(5);
	testmap.erase(-7);
//	testmap.erase(65);
//	testmap.insert(ft::pair<int, std::string>(-10, "text"));
//	std::cout << ret.first->first << " " << ret.first->second << " " << ret.second << std::endl;
	ft::map<int, std::string>::iterator retIte = testmap.begin();
	retIte++;
	retIte++;
	retIte++;
	retIte++;
	retIte++;
	retIte++;
	retIte++;
	retIte++;
	retIte++;
	retIte++;
	retIte++;
	retIte++;
//	std::cout << retIte->first << " --> ;)\n";
	retIte = testmap.insert(retIte, ft::pair<int, std::string>(12, "nnnndo"));
//	std::cout << retIte->first << " --> ;)\n";
//	testmap.insert(ft::pair<int, std::string>(1, "newNode"));
//	std::cout << *itt << std::endl;
//	itt = testmap.begin();*/
/*	ft::map<int, std::string> testt;
	for (int i = 0; i < 500000; i++)
		testt.insert(ft::pair<int, std::string>(i, "babar"));
	ft::map<int, std::string>::iterator ita = testt.begin();
	while (ita != testt.end())
	{
		std::cout << ita->first << " ";
		ita++;
	}*/
//	testmap.print();
	ft::map<int, std::string>::iterator itt = testmap.begin();
	//std::cout << "BEGINN -> " << (testmap.begin()).getPtr() << *(testmap.begin()) << std::endl;
	//std::cout << "ENNNDDD -> " << (testmap.end()).getPtr() << *(testmap.end()) << std::endl;
	//std::cout << "ENNNDDD -> " << ((testmap.end()).getPtr())->_left << std::endl;*/
	while (itt != testmap.end())
	{
		//std::cout << "->* " << itt.getPtr() << " " <<  *itt << std::endl;
		std::cout << "->* " << itt->first << itt->second << std::endl;
			
	/*	ft::Node<int, std::string>* ptr = itt.getPtr();
		if (ptr->_parent != NULL)
			std::cout << "parent : " << ptr->_parent->_pair << std::endl;
		if (ptr->_left != NULL)
			std::cout << "left : " << ptr->_left->_pair << std::endl;
		if (ptr->_right != NULL)
			std::cout << "right : " << ptr->_right->_pair << std::endl;*/
		++itt;
	}
	std::cout << "===SIZE============> " << testmap.size() << std::endl;
/*	ft::map<int, std::string> copy;
	copy.insert(ft::pair<int, std::string>(1000, "text"));
	copy.insert(ft::pair<int, std::string>(2000, "text"));
	copy.insert(ft::pair<int, std::string>(3000, "text"));
	copy.insert(ft::pair<int, std::string>(4000, "text"));
	copy.insert(ft::pair<int, std::string>(5000, "text"));
	copy.insert(ft::pair<int, std::string>(6000, "text"));
	copy.insert(ft::pair<int, std::string>(7000, "text"));*/
	//ft::map<int, std::string> copy(testmap.begin(), testmap.end());
	ft::map<int, std::string> copy = testmap;
//	copy.insert(testmap.begin(), testmap.end());
//	for (ft::map<int, std::string>::iterator it = copy.begin(); it != copy.end(); it++)
//		std::cout << "-->* " << it->first << std::endl;
//	std::cout << "ENNNDDD -> " << (testmap.end()).getPtr() << *(testmap.end()) << std::endl;
//	--itt;
//		std::cout << "=-=->* " << itt.getPtr() << " " <<  *itt << std::endl;
//	itt++;
//	ft::Node<int, std::string>* ptr = itt.getPtr();
//	std::cout << "ici: " << ptr->_left->_pair << std::endl;
//	std::cout << "ici: " << ptr->_right->_left->_pair << std::endl;
//	std::cout << *itt << std::endl;
//	itt++;
//	std::cout << *itt << std::endl;
//	itt++;
//	std::cout << *itt << std::endl;
//	itt++;
//	for (int i = 0; i < 13; i++)
//	{
//		testmap.insert(ft::pair<int, std::string>(i, "babar"));
//	}
//	for (ft::map<int, std::string>::iterator it = testmap.begin(); it != testmap.end(); it++)
//		std::cout << it->first << std::endl;
/*	while (itt != testmap.end())
	{
		std::cout << *itt << std::endl;
		itt++;
	}*/
//	testmap.insert(itt, ft::pair<int, std::string>(-1, "newNode"));
//	ret = testmap.insert(ft::pair<int, std::string>(-3, "zero"));

	//testmap.print();
	testmap.clear();
	testmap.count(3);
	std::cout << "====SIZE=====> " << testmap.size() << "=====EMPTY===>" << testmap.empty() << std::endl;
	std::cout << "====SIZE=====> " << testmap.size() << "=====EMPTY===>" << testmap.empty() << std::endl;
//	copy.print();
//	testmap.print();
	return 0;
} 
