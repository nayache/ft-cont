/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:00:41 by nayache           #+#    #+#             */
/*   Updated: 2021/12/13 13:54:50 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {
template <typename T>
class	VecIterator
{
	public:
	
	typedef typename std::random_access_iterator_tag		tag;
	typedef typename ft::Iterator<tag, T>::reference	 	reference;
	typedef typename ft::Iterator<tag, T>::value_type 		value_type;
	typedef typename ft::Iterator<tag, T>::pointer			pointer;
	typedef typename ft::Iterator<tag, T>::difference_type	difference_type;
	

	VecIterator() :	_p(0) {}; 
	VecIterator(pointer addr) : _p(addr) {}; 

	reference	operator*() {return (*(this->_p));}
	
	VecIterator	operator++()
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
	VecIterator	operator--()
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

	bool operator!=(const VecIterator& rhs)
	{
		return (this->_p != rhs._p);
	}
	
	private:
	
	pointer	_p;
};
}

#endif
