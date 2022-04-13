/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:00:41 by nayache           #+#    #+#             */
/*   Updated: 2022/04/13 12:13:53 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "../utils.hpp"

namespace ft {
template <typename T, bool B>
class	VecIterator
{
	public:
	
	typedef typename std::random_access_iterator_tag			tag;
	typedef typename ft::Iterator<tag, T>::iterator_category	iterator_category;
	typedef typename ft::Iterator<tag, T>::difference_type		difference_type;
	typedef typename TrueType<B, T, const T>::type				value_type;
	typedef typename TrueType<B, T&, const T&>::type			reference;
	typedef typename TrueType<B, T*, const T*>::type			pointer;

	VecIterator() :	_p(0) {}; 
	VecIterator(pointer addr) : _p(addr) {}; 
	VecIterator(const VecIterator<T, false>& src) { this->_p = src.getPointer(); }

	VecIterator&	operator=(const VecIterator& src)
	{
		this->_p = src._p;
		return (*this);
	}

	reference	operator*() {return (*(this->_p));}

	VecIterator	operator+(difference_type n)
	{
		VecIterator	tmp(*this);
		for (difference_type i = 0; i < n; i++)
			++tmp;
		return (tmp);
	}

	VecIterator&	operator+=(difference_type n)
	{
		*this = *this + n;
		return (*this);	
	}
	
	VecIterator&	operator++()
	{
		this->_p += 1;
		return (*this);
	}
	VecIterator	operator++(int)
	{
		VecIterator	tmp(*this);
		++(*this);
		return (tmp);
	}
	VecIterator	operator-(difference_type n)
	{
		VecIterator	tmp(*this);
		for (difference_type i = 0; i < n; i++)
			--tmp;
		return (tmp);
	}
	VecIterator&	operator--()
	{
		this->_p -= 1;
		return (*this);
	}
	VecIterator	operator--(int)
	{
		VecIterator	tmp(*this);
		--(*this);
		return (tmp);
	}
	VecIterator&	operator-=(difference_type n)
	{
		*this = *this - n;
		return (*this);
	}

	reference	operator[](difference_type b)
	{
		return (*(this->_p + b));
	}

	bool	operator!=(const VecIterator& rhs)
	{
		return (this->_p != rhs._p);
	}
	
	bool	operator==(const VecIterator& rhs)
	{
		return (this->_p == rhs._p);
	}
	
	bool	operator<(const VecIterator& rhs)
	{
		return (this->_p < rhs._p);
	}

	bool	operator>(const VecIterator& rhs)
	{
		return (this->_p > rhs._p);
	}
	
	pointer	getPointer() const { return (this->_p); }

	private:
	
	pointer	_p;
};
}

#endif
