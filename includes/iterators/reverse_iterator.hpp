/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 07:33:26 by nayache           #+#    #+#             */
/*   Updated: 2022/04/13 12:07:35 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR
# define REVERSE_ITERATOR

# include "iterator_traits.hpp"

namespace ft {

template <class Iter>
class	ReverseIterator
{	
	public:

	typedef typename ft::IteratorTraits<Iter>::reference 			reference;
	typedef typename ft::IteratorTraits<Iter>::value_type 			value_type;
	typedef typename ft::IteratorTraits<Iter>::pointer				pointer;
	typedef typename ft::IteratorTraits<Iter>::difference_type		difference_type;
	typedef typename ft::IteratorTraits<Iter>::iterator_category	iterator_category;
	typedef	Iter													iterator_type;
	
	ReverseIterator(void) : current(0) {};
	ReverseIterator(const iterator_type x) : current(x) {};
	
	template <class U>
	ReverseIterator(const ReverseIterator<U> &other) : current(other.base()) {};

	template <class U>
	ReverseIterator& operator=(const ReverseIterator<U>& other)
	{
		this->current = other.current;
		return (*this);
	}
	
	iterator_type	base() const { return (this->current); }

	template <class Iterator>
	bool	operator!=(const ReverseIterator<Iterator> &rhs) {return (this->current != rhs.base());}

	template <class Iterator>
	bool	operator==(const ReverseIterator<Iterator> &rhs) {return (this->current != rhs.base());}

	ReverseIterator	operator+(difference_type n) const
	{
		ReverseIterator tmp(*this);
		for (difference_type i = 0; i < n; i++)
			--tmp.current;
		return (tmp);
	}
	ReverseIterator&	operator++()
	{
		this->current -= 1;
		return (*this);
	}
	ReverseIterator		operator++(int)
	{
		ReverseIterator	tmp(*this);
		++(*this);
		return (tmp);
	}
	ReverseIterator	operator-(difference_type n) const
	{
		ReverseIterator tmp(*this);
		for (difference_type i = 0; i < n; i++)
			++tmp.current;
		return (tmp);
	}
	ReverseIterator&	operator--()
	{
		this->current += 1;
		return (*this);
	}
	ReverseIterator		operator--(int)
	{
		ReverseIterator	tmp(*this);
		--(*this);
		return (tmp);
	}
	ReverseIterator&	operator-=(difference_type n)
	{
		this->current += n;
		return (*this);
	}
	ReverseIterator&	operator+=(difference_type n)
	{
		this->current -= n;
		return (*this);
	}
	reference	operator[](difference_type n) const {return (*(this->current + n));}
	reference	operator*() {return (*this->current);}
	pointer		operator->() {return (&(operator*()));}

	bool	operator==(const ReverseIterator& rhs) {return (this->current == rhs.base());}
	


	protected:
	
	Iter	current;
};
}

#endif
