/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:00:41 by nayache           #+#    #+#             */
/*   Updated: 2022/05/20 18:41:25 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ITERATORS_HPP
# define RANDOM_ITERATORS_HPP

#include "iterator_traits.hpp"
#include "utils.hpp"

namespace ft {
template <typename T>
class	RandomIterator
{
	public:
	
	typedef typename std::random_access_iterator_tag			tag;
	typedef typename ft::Iterator<tag, T>::iterator_category	iterator_category;
	typedef typename ft::Iterator<tag, T>::difference_type		difference_type;
	typedef T													value_type;
	typedef T&													reference;
	typedef T*													pointer;

	RandomIterator() :	_p(0) {}; 
	RandomIterator(pointer addr) : _p(addr) {};

	template <typename U> 
	RandomIterator(const RandomIterator<U>& src) : _p(src.base()) {}
	
	RandomIterator(const RandomIterator& src) : _p(src.base()) {}

	RandomIterator&	operator=(const RandomIterator& rhs)
	{
		if (this == &rhs)
			return (*this);
		this->_p = rhs._p;
		return (*this);
	}

	reference	operator*(void) const {return (*(this->_p));}

	pointer	operator->(void) { return &(this->operator*()); }

	
	RandomIterator&	operator++()
	{
		++this->_p;
		return (*this);
	}
	RandomIterator	operator++(int)
	{
		RandomIterator	tmp(*this);
		++this->_p;
		return (tmp);
	}
	
	RandomIterator&	operator--()
	{
		--this->_p;
		return (*this);
	}
	
	RandomIterator	operator--(int)
	{
		RandomIterator	tmp(*this);
		--this->_p;
		return (tmp);
	}

	RandomIterator	operator+(difference_type n) const
	{
		return (RandomIterator(this->_p + n));
	}

	RandomIterator	operator-(difference_type n) const
	{
		return (RandomIterator(this->_p - n));
	}
	
	difference_type	operator-(const RandomIterator& x) const
	{
		return (this->_p - x.base());
	}
	
	RandomIterator&	operator-=(difference_type n)
	{
		this->_p -= n;
		return (*this);
	}

	RandomIterator&	operator+=(difference_type n)
	{
		this->_p += n;
		return (*this);	
	}

	reference	operator[](difference_type n) { return (*(this->_p + n)); }

	bool	operator==(const RandomIterator& x) const { return (this->_p == x._p); }
	bool	operator!=(const RandomIterator& x) const { return (this->_p != x._p); }
	bool	operator<(const RandomIterator& x) const { return (this->_p < x._p); }
	bool	operator>(const RandomIterator& x) const { return (this->_p > x._p); }
	bool	operator<=(const RandomIterator& x) const { return (this->_p <= x._p); }
	bool	operator>=(const RandomIterator& x) const { return (this->_p >= x._p); }	
	
	pointer	base() const { return (this->_p); }

	private:
	
	pointer	_p;
};

////------iterator/const-iterator----------//
template <typename T1, typename T2>
bool	operator==(const RandomIterator<T1>& lhs, const RandomIterator<T2>&rhs ) { return (lhs.base() == rhs.base()); }
template <typename T1, typename T2>
bool	operator!=(const RandomIterator<T1>& lhs, const RandomIterator<T2>&rhs ) { return (lhs.base() != rhs.base()); }
template <typename T1, typename T2>
bool	operator<(const RandomIterator<T1>& lhs, const RandomIterator<T2>&rhs ) { return (lhs.base() < rhs.base()); }
template <typename T1, typename T2>
bool	operator<=(const RandomIterator<T1>& lhs, const RandomIterator<T2>&rhs ) { return (lhs.base() <= rhs.base()); }
template <typename T1, typename T2>
bool	operator>(const RandomIterator<T1>& lhs, const RandomIterator<T2>&rhs ) { return (lhs.base() > rhs.base()); }
template <typename T1, typename T2>
bool	operator>=(const RandomIterator<T1>& lhs, const RandomIterator<T2>&rhs ) { return (lhs.base() >= rhs.base()); }

template <typename T>
typename RandomIterator<T>::difference_type operator-(const RandomIterator<T>& lhs, const RandomIterator<T>& rhs)
{
	return (lhs.base() - rhs.base());
}
template <typename T1, typename T2>
typename RandomIterator<T1>::difference_type operator-(const RandomIterator<T1>& lhs, const RandomIterator<T2>& rhs)
{
	return (lhs.base() - rhs.base());
}

template <typename T>
RandomIterator<T> operator+(typename RandomIterator<T>::difference_type n, const RandomIterator<T>& rhs)
{
	return (rhs + n);
}

}
#endif
