/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:22:22 by nayache           #+#    #+#             */
/*   Updated: 2022/03/17 17:53:21 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "Bst.hpp"
# include "includes/iterators/iterator.hpp"
# include "includes/utils.hpp"

namespace ft {
template <class Key, class Mapped, bool B, class Node = Node<Key, Mapped> >
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
	typedef typename TrueType<B, value_type&, const value_type&>::type	reference;
	typedef typename TrueType<B, value_type*, const value_type*>::type	pointer;

	MapIterator() : _ptr(NULL) {};
	MapIterator(node_pointer addr) : _ptr(addr) {};
	MapIterator(const MapIterator<Key, Mapped, false, Node>& src) : _ptr(src.getPtr()) {};
	~MapIterator() {};

	MapIterator&	operator=(const MapIterator& src)
	{
		this->_ptr = src.getPtr();
		return (*this);
	}
	
	bool	operator==(const MapIterator& src) const
	{
		return (this->_ptr == src.getPtr());
	}

	bool	operator!=(const MapIterator& src) const
	{
		return (this->_ptr != src.getPtr());
	}
	
	reference	operator*() const { return (this->_ptr->_pair); }
	pointer		operator->() const { return &(this->_ptr->_pair); }
	
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
				
		//		if (this->_ptr->_parent == NULL)
		//			this->_ptr = this->_end;
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
		key_type key = this->_ptr->_pair.first;
		
		if (this->_ptr->_left == NULL)
		{
			while (this->_ptr != NULL && this->_ptr->_pair.first >= key)
				this->_ptr = this->_ptr->_parent;
			
		//	if (this->_ptr == NULL)
		//		this->_ptr = this->_end;
		}
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

template <class Key, class Mapped, bool B, class Node = Node<Key, Mapped> >
class RevMapIterator
{
	public:

	typedef Node												node_type;
	typedef Node*												node_pointer;
	typedef	Key													key_type;
	typedef Mapped												mapped_type;
	typedef typename ft::pair<Key, Mapped>						value_type;
	typedef std::size_t											size_type;
	typedef std::ptrdiff_t										difference_type;
	typedef typename TrueType<B, value_type&, const value_type&>::type	reference;
	typedef typename TrueType<B, value_type*, const value_type*>::type	pointer;

	RevMapIterator() : _ptr(NULL) {};
	RevMapIterator(node_pointer addr) : _ptr(addr) {};
	RevMapIterator(const RevMapIterator<Key, Mapped, false, Node>& src) : _ptr(src.getPtr()) {};
	RevMapIterator(const MapIterator<Key, Mapped, false, Node>& src) : _ptr(src.getPtr()) {};
	~RevMapIterator() {};

	RevMapIterator&	operator=(const RevMapIterator& src)
	{
		this->_ptr(src.getPtr());
	}
	
	bool	operator==(const RevMapIterator& src) const
	{
		return (this->_ptr == src.getPtr());
	}

	bool	operator!=(const RevMapIterator& src) const
	{
		return (this->_ptr != src.getPtr());
	}
	
	reference	operator*() const { return (this->_ptr->_pair); }
	pointer		operator->() const { return &(this->_ptr->_pair); }
	
	RevMapIterator&	operator++()
	{
		this->prev();
		return (*this);
	}
	
	RevMapIterator&	operator--()
	{
		this->next();
		return (*this);
	}

	RevMapIterator	operator++(int)
	{
		RevMapIterator	tmp(*this);
		this->prev();
		return (tmp);
	}
	
	RevMapIterator	operator--(int)
	{
		RevMapIterator	tmp(*this);
		this->next();
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
		key_type key = this->_ptr->_pair.first;
		
		if (this->_ptr->_left == NULL)
		{
			while (this->_ptr != NULL && this->_ptr->_pair.first >= key)
			this->_ptr = this->_ptr->_parent;
		}
		else
		{
			this->_ptr = this->_ptr->_left;
			while (this->_ptr->_right != NULL)
				this->_ptr = this->_ptr->_right;
		}
	}
};
}


#endif
