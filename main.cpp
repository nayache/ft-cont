/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:54:50 by nayache           #+#    #+#             */
/*   Updated: 2021/12/09 13:09:58 by nayache          ###   ########.fr       */
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

template <class Iter>
void	func(Iter first, Iter last)
{
	typename std::iterator_traits< Iter >::difference_type n = std::distance( first, last ); 
    
	std::cout << "[" << n << "]" << std::endl;
	
	--n ; 
    while ( n > 0 )
	{
		std::cout << "[" << n << "]" << std::endl;
        typename std :: iterator_traits < Iter > :: value_type tmp=  *first ; 
        *first++  =  *--last; 
        *last = tmp ; 
        n -= 2;
	}
}

int	main(void)
{
	typedef ft::IteratorTraits<std::list<double>::iterator> traits;
	if (typeid(traits::iterator_category)== typeid(std::input_iterator_tag))
		std::cout << "equal" << std::endl;

//	std::vector<int> arr(10, 42);
//	ft::ReverseIterator< std::vector<int>::iterator > rev = arr.begin();
//	ft::ReverseIterator< std::vector<int>::iterator > revend = arr.end();
	
	std::vector<int> arr(12, 42);
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 40;
	arr[4] = 50;
	arr[5] = 60;
	arr[6] = 70;
	arr[7] = 80;
	arr[8] = 90;
	arr[9] = 100;
	ft::ReverseIterator<std::vector<int>::iterator> rev1 = arr.begin();
	ft::ReverseIterator<std::vector<int>::iterator> rev2 = arr.end();
	while (rev1 != rev2)
	{
		//std::cout << rev1->first << std::endl;
		std::cout << rev1[0] << std::endl;
		rev1 += 2;
	}
	if (rev1 != rev2)
		std::cout << "different" << std::endl;
	//	test.print();
//	test2.print();

//	std::cout << test.getData();

	return (0);
}
