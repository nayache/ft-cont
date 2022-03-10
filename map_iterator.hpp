/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:22:22 by nayache           #+#    #+#             */
/*   Updated: 2022/03/10 16:45:01 by nayache          ###   ########.fr       */
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
	typedef typename ft::pair<Key, Mapped>						value_type;
	typedef std::size_t											size_type;
	typedef std::ptrdiff_t										difference_type;

	MapIterator() : _ptr(NULL) {};
	MapIterator(node_pointer addr) : _ptr(addr) {};
	MapIterator(const MapIterator& src) : _ptr(src._ptr) {};
	~MapIterator() {};

	MapIterator&	operator=(const MapIterator& src)
	{
		this->_ptr(src.getPtr());
	}
	
	bool	operator==(const MapIterator& src) const
	{
		return (this->_ptr == src.getPtr());
	}

	bool	operator!=(const MapIterator& src) const
	{
		return (this->_ptr != src.getPtr());
	}
	
	value_type&	operator*() const { return (this->_ptr->_pair); }
	value_type*	operator->() const { return &(this->_ptr->_pair); }
	
	MapIterator&	operator++()
	{
		this->next();
		return (*this);
	}
	
	MapIterator&	operator--()
	{
		this->prev();
		return (*this);
	}

	MapIterator	operator++(int)
	{
		MapIterator	tmp(*this);
		this->next();
		return (tmp);
	}
	
	MapIterator	operator--(int)
	{
		MapIterator	tmp(*this);
		this->prev();
		return (tmp);
	}

	node_pointer	getPtr() const { return (this->_ptr); }

	//-----attributes--------

	private:

	node_pointer	_ptr;
	
	//----------------------

	void	next() // a corriger si pas de prev ou next => what behavior ?
	{
		key_type key = this->_ptr->_pair.first;
		
		if (this->_ptr->_right == NULL)
		{
			if (this->_ptr->_parent != NULL)
				this->_ptr = this->_ptr->_parent;
			
			if (this->_ptr->_pair.first < key)
			{
				while (this->_ptr->_parent != NULL && key > this->_ptr->_parent->_pair.first)
					this->_ptr = this->_ptr->_parent;
				
				this->_ptr = this->_ptr->_parent;
			}
		}
		else
		{
			this->_ptr = this->_ptr->_right;
			while (this->_ptr->_left != NULL)
				this->_ptr = this->_ptr->_left;
		}
	}

	void	prev()
	{
		if (this->_ptr->_left == NULL)
			this->_ptr = this->_ptr->_parent;
		else
		{
			this->_ptr = this->_ptr->_left;
			while (this->_ptr->_right != NULL)
				this->_ptr = this->_ptr->_right;
		}
	}
};

template <class K, class V>
std::ostream&	operator<<(std::ostream& os, ft::pair<K, V> src)
{
	os << "(" << "\033[1;33m" << src.first << "\033[0;28m" << " | " << "\033[1;33m" << src.second << "\033[0;28m" << ")";
	return (os);
}

}

#endif
