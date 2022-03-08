/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:22:22 by nayache           #+#    #+#             */
/*   Updated: 2022/03/08 15:48:36 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "Bst.hpp"
# include "includes/iterators/iterator.hpp"

namespace ft {
template <class Key, class Mapped, class Node = Node<Key, Mapped> >
class MapIterator
{
	public:

	typedef Node												node_type;
	typedef Node*												node_pointer;
	typedef	Key													key_type;
	typedef Mapped												mapped_type;
	typedef typename ft::pair<Key, Mapped>						type;
	typedef typename std::bidirectional_iterator_tag			tag;
	typedef typename ft::Iterator<tag, type>::iterator_category	iterator_category;
	typedef typename ft::Iterator<tag, type>::reference			reference;
	typedef typename ft::Iterator<tag, type>::value_type		value_type;
	typedef typename ft::Iterator<tag, type>::pointer			pointer;
	typedef typename ft::Iterator<tag, type>::difference_type	difference_type;

	MapIterator() : _current(node_pointer()) {};
	MapIterator(node_pointer addr) : _current(addr) {};
	MapIterator(const MapIterator& src) : _current(src._current) {};

	//-----attributes--------

	private:

	node_pointer	_current;
};

}

#endif
