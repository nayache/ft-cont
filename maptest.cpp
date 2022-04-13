/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptest.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:09:17 by nayache           #+#    #+#             */
/*   Updated: 2022/04/13 13:37:26 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <vector>
#include <iostream>
#include <utility>
#include "includes/pair.hpp"
# include "includes/iterators/map_iterator.hpp"
# include "includes/containers/map.hpp"
int	main()
{
	ft::map<int, std::string> coco, lolo;

	coco.insert(ft::pair<int, std::string>(1, "one"));
	coco.insert(ft::pair<int, std::string>(2, "two"));
	coco.insert(ft::pair<int, std::string>(3, "three"));
	
	lolo.insert(ft::pair<int, std::string>(22, "hi"));
	lolo.insert(ft::pair<int, std::string>(44, "hii"));
	lolo.insert(ft::pair<int, std::string>(66, "hiii"));
	lolo.insert(ft::pair<int, std::string>(88, "hiiii"));
	lolo.insert(ft::pair<int, std::string>(111, "hiiiii"));
	
	for (ft::map<int, std::string>::const_reverse_iterator rit = coco.rbegin(); rit != coco.rend(); rit++)
		std::cout << *rit << " :)\n";
	
	ft::map<int, std::string> copy(coco);
	
	for (ft::map<int, std::string>::const_reverse_iterator rit = copy.rbegin(); rit != copy.rend(); rit++)
		std::cout << *rit << " :)\n";
	
	for (ft::map<int, std::string>::const_iterator it = lolo.begin(); it != lolo.end(); it++)
		std::cout << *it << std::endl;
	
	lolo.swap(copy);
	
	for (ft::map<int, std::string>::const_iterator it = lolo.begin(); it != lolo.end(); it++)
		std::cout << *it << std::endl;
	
	for (ft::map<int, std::string>::const_iterator it = copy.begin(); it != copy.end(); it++)
		std::cout << *it << std::endl;

	
	return 0;
} 
