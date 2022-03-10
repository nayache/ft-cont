/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptest.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:09:17 by nayache           #+#    #+#             */
/*   Updated: 2022/03/10 17:22:11 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map.hpp"
#include <iostream>
#include <utility>
#include "includes/pair.hpp"
//#include "Bst.hpp"
# include "map_iterator.hpp"

int	main()
{
	ft::map<int, std::string> testmap;

	testmap._tree._main->setValues(15, "fifteen");
	testmap._tree.addNode(ft::pair<int, std::string>(10, "ten"));
	testmap._tree.addNode(ft::pair<int, std::string>(20, "twenty"));
	testmap._tree.addNode(ft::pair<int, std::string>(16, "seize"));
	testmap._tree.addNode(ft::pair<int, std::string>(7, "seven"));
	testmap._tree.addNode(ft::pair<int, std::string>(9, "nine"));
	testmap._tree.addNode(ft::pair<int, std::string>(8, "eight"));
	testmap._tree.addNode(ft::pair<int, std::string>(12, "douze"));
	
	ft::map<int, std::string>::const_iterator it = testmap.begin();
	
	while (it != NULL)
	{
		std::cout << *it << std::endl;
		++it;
	}
	return 0;
} 
