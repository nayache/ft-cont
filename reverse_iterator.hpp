/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 07:33:26 by nayache           #+#    #+#             */
/*   Updated: 2021/12/13 11:07:04 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR
# define REVERSE_ITERATOR

# include "iterator_traits.hpp"

namespace ft {

template <class Iter>
class	ReverseIterator : public ft::Iterator <std::bidirectional_iterator_tag, Iter>
{	
	public:

	typedef typename ft::IteratorTraits<Iter>::reference 		reference;
	typedef typename ft::IteratorTraits<Iter>::value_type 		value_type;
	typedef typename ft::IteratorTraits<Iter>::pointer			pointer;
	typedef typename ft::IteratorTraits<Iter>::difference_type	difference_type;
	typedef	Iter												iterator_type;
	
	ReverseIterator(void) : current(0) {};
	ReverseIterator(iterator_type x) : current(x) {};
	template <class U>
	ReverseIterator(const ReverseIterator<U> &other) : current(other) {};

	template< class U >
	ReverseIterator& operator=(const ReverseIterator<U>& other)
	{
		this->current = other.current;
		return (*this);
	}

	template <class Iterator>
	bool	operator!=(const ReverseIterator<Iterator> &rhs) const {return (this->current != rhs.current);}

	template <class Iterator>
	bool	operator==(const ReverseIterator<Iterator> &rhs) const {return (this->current != rhs.current);}

	ReverseIterator	operator+(difference_type n) const
	{
		ReverseIterator tmp(*this);
		for (difference_type i = 0; i < n; i++)
			++tmp.current;
		return (tmp);
	}
	ReverseIterator	operator++()
	{
		this->current += 1;
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
			--tmp.current;
		return (tmp);
	}
	ReverseIterator	operator--()
	{
		this->current -= 1;
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
		this->current -= n;
		return (*this);
	}
	ReverseIterator&	operator+=(difference_type n)
	{
		this->current += n;
		return (*this);
	}
	reference	operator[](difference_type n) const {return (*(this->current + n));}
	reference	operator*() const {return (*this->current);}
	pointer		operator->() const {return (&(operator*()));}

	bool	operator==(const ReverseIterator& rhs) {return (this->current == rhs.current);}
		
	protected:
	
	Iter	current;
};
}

#endif
