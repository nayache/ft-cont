/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:30:28 by nayache           #+#    #+#             */
/*   Updated: 2022/03/08 17:16:29 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "Bst.hpp"
# include "map_iterator.hpp"
# include "includes/is_integral.hpp"
# include "includes/enable_if.hpp"
# include "includes/utils.hpp"

namespace ft {
template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
class	map
{
	public:

	typedef	Key													key_type;
	typedef T													mapped_type;
	typedef	ft::pair<const Key, T>								value_type;
	typedef	Compare												key_compare;
	typedef	Alloc												alloc_type;
	typedef typename alloc_type::pointer						pointer;
	typedef typename alloc_type::const_pointer					const_pointer;
	typedef	value_type&											reference;
	typedef	const value_type&									const_reference;
	typedef size_t												size_type;
	typedef BinarySearchTree<key_type, mapped_type>				tree_type;
	typedef	ft::MapIterator<Key, T>								iterator;
	typedef	ft::MapIterator<Key, const T>						const_iterator;

	map(const key_compare& comp = key_compare(), const alloc_type& alloc = alloc_type()) : _alloc(alloc), _comp(comp), _tree(tree_type())
	{}
	
/*	template <class InputIterator>
	map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
	const alloc_type& alloc = alloc_type(),
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NullPtr)
	:	_alloc(alloc), _tree(tree_type())
	{
		std::cout << "iterator constructor\n";
	}

	map (const map& x) : _alloc(x._alloc), _tree(tree_type())
	{
		std::cout << "copy constructor\n";
	}*/

	public:

	alloc_type		_alloc;
	key_compare		_comp;
	tree_type		_tree;
};

}

#endif
