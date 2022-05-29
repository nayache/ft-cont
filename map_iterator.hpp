/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:22:22 by nayache           #+#    #+#             */
/*   Updated: 2022/05/29 23:30:26 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "Bst.hpp"
# include "iterator.hpp"
# include "utils.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"

namespace ft {
template <class T, class N, class Compare>
class MapIterator
{
	public:

	typedef T													value_type;
	typedef	typename T::first_type								key_type;
	typedef	typename T::second_type								mapped_type;
	typedef Compare												key_compare;
	typedef T&													reference;
	typedef T*													pointer;
	typedef std::size_t											size_type;
	typedef std::ptrdiff_t										difference_type;
	typedef N													node_type;
	typedef N*													node_pointer;
	typedef	std::bidirectional_iterator_tag						iterator_category;
	typedef ft::BinarySearchTree<key_type, mapped_type, Compare>	tree_type;

	MapIterator(const key_compare& comp = key_compare()) : _ptr(NULL), _comp(comp) {}
	MapIterator(node_pointer addr, node_pointer root, node_pointer end, const key_compare& comp = key_compare())
	: _ptr(addr), _end(end), _root(root), _comp(comp)
	{
	}
	
	template<class U>
	MapIterator(const MapIterator<U, N, Compare>& src, typename ft::enable_if<!ft::is_const<U>::value, U>::type* = NullPtr)
	: _ptr(src.getPtr()), _end(src.getEnd()), _root(src.getRoot())
	{
		this->_comp = key_compare();
	}
	~MapIterator() {}

	MapIterator&	operator=(const MapIterator& src)
	{
		this->_ptr = src.getPtr();
		this->_end = src._end;
		this->_root = src._root;
		this->_comp = src._comp;
		return (*this);
	}
	
	template <class U>
	bool	operator==(const MapIterator<U, N, Compare>& src) const
	{
		return (this->_ptr == src.getPtr());
	}

	template <class U>
	bool	operator!=(const MapIterator<U, N, Compare>& src) const
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
	node_pointer	getEnd() const { return (this->_end); }
	node_pointer	getRoot() const { return (this->_root); }

	//-----attributes--------

	private:

	node_pointer	_ptr;
	node_pointer	_end;
	node_pointer	_root;
	key_compare		_comp;
	
	//----------------------
	
	bool    upper(const key_type& a, const key_type& b)
    {
        return (this->_comp(a, b) == false && equal(a, b) == false);
    }
    
    bool    equal(const key_type& a, const key_type& b)
    {
        if (this->_comp(a, b) == false && this->_comp(b, a) == false)
            return (true);
        return (false);
    }	
	
	node_pointer maxNode()
	{
		node_pointer tmp = this->_root;
		while (tmp->_right != NULL)
			tmp = tmp->_right;
		
		return (tmp);
	}

	node_pointer	mostLeft(node_pointer x)
	{
		while (x->_left != NULL)
			x = x->_left;

		return (x);
	}

	node_pointer	mostRight(node_pointer x)
	{
		while (x->_right != NULL)
			x = x->_right;

		return (x);
	}
	
	void	prev()
	{
		if (this->_ptr == NULL)
			return;

		if (this->_ptr == this->_end)
		{
			this->_ptr = this->maxNode();
			return;
		}

		if (this->_ptr->_left != NULL)
			this->_ptr = mostRight(this->_ptr->_left);
		else
		{
			node_pointer tmp = this->_ptr;
			this->_ptr = this->_ptr->_parent;
			while (this->_ptr != NULL && this->_ptr->_left == tmp)
			{
				tmp = this->_ptr;
				this->_ptr = this->_ptr->_parent;
			}
		}
	}

	void	next()
	{
		if (this->_ptr == NULL || this->_ptr == this->_end)
			return;
		
		if (this->_ptr->_right != NULL)
			this->_ptr = mostLeft(this->_ptr->_right);
		else
		{
			node_pointer tmp = this->_ptr;
			this->_ptr = this->_ptr->_parent;
			while (this->_ptr != NULL && this->_ptr->_right == tmp)
			{
				tmp = this->_ptr;
				this->_ptr = this->_ptr->_parent;
			}
			if (this->_ptr == NULL)
				this->_ptr = this->_end;
		}
	}
};

/*template <class K, class V>
std::ostream&	operator<<(std::ostream& os, ft::pair<K, V> src)
{
	os << "(" << "\033[1;33m" << src.first << "\033[0;28m" << " | " << "\033[1;33m" << src.second << "\033[0;28m" << ")";
	return (os);
}*/

}


#endif
