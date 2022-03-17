/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptest.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:09:17 by nayache           #+#    #+#             */
/*   Updated: 2022/03/17 18:30:02 by nayache          ###   ########.fr       */
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

/*	testmap._tree._main->setValues(15, "fifteen");
	testmap._tree.addNode(ft::pair<int, std::string>(10, "ten"));
	testmap._tree.addNode(ft::pair<int, std::string>(20, "twenty"));
	testmap._tree.addNode(ft::pair<int, std::string>(16, "seize"));
	testmap._tree.addNode(ft::pair<int, std::string>(7, "seven"));
	testmap._tree.addNode(ft::pair<int, std::string>(9, "nine"));
	testmap._tree.addNode(ft::pair<int, std::string>(8, "eight"));
	testmap._tree.addNode(ft::pair<int, std::string>(12, "douze"));
*/	
	testmap.insert(ft::pair<int, std::string>(44, "text"));
	testmap.insert(ft::pair<int, std::string>(11, "text"));
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
	std::cout << ret.first->first << " " << ret.first->second << " " << ret.second << std::endl;
	ft::map<int, std::string>::iterator itt = testmap.begin();
	itt = testmap.insert(itt, ft::pair<int, std::string>(-1, "newNode"));
	std::cout << *itt << std::endl;
	itt = testmap.begin();
/*	while (itt != testmap.end())
	{
		std::cout << *itt << std::endl;
		itt++;
	}*/
//	testmap.insert(itt, ft::pair<int, std::string>(-1, "newNode"));
//	ret = testmap.insert(ft::pair<int, std::string>(-3, "zero"));

	testmap.print();
	return 0;
} 
