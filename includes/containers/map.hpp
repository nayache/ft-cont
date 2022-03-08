/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:22:16 by nayache           #+#    #+#             */
/*   Updated: 2022/03/02 19:29:24 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include "../pair.hpp"

namespace ft {
template <class Key, class T, class Compare = std::less<Key>, class Allocator = 
std::allocator<ft::pair<const Key, T> > >
class map
{
	public:

	typedef Key										key_type;
	typedef	T										mapped_type;
	typedef	ft::pair<const key_type, mapped_type>	value_type;
	typedef	Compare									key_compare;
//	typedef	?/										value_compare;
	typedef	Allocator								allocator_type;
	typedef	typename Allocator::pointer				pointer;
	typedef	typename Allocator::const_pointer		const_pointer;
	typedef	typename Allocator::reference			reference;
	typedef	typename Allocator::const_reference		const_reference;
//	typedef typename ft::MapIterator				iterator;
};

}

#endif
