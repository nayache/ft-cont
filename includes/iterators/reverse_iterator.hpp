/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 07:33:26 by nayache           #+#    #+#             */
/*   Updated: 2022/04/21 11:16:33 by nayache          ###   ########.fr       */
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
	
	ReverseIterator(void) : current() {};
	
	ReverseIterator(iterator_type x) : current(x) {};
	
	template <class U>
	ReverseIterator(const ReverseIterator<U>& rev_it) : current(rev_it.base()) {};

	ReverseIterator& operator=(const ReverseIterator& other)
	{
		this->current = other.current;
		return (*this);
	}
	
	template <class U>
	bool	operator==(const ReverseIterator<U>& rhs) { return (this->base() == rhs.base()); }

	template <class U>
	bool	operator!=(const ReverseIterator<U>& rhs) { return (this->base() != rhs.base()); }
	
	template <class U>
	bool	operator<(const ReverseIterator<U>& rhs) { return (this->base() > rhs.base()); }
	
	template <class U>
	bool	operator>(const ReverseIterator<U>& rhs) { return (this->base() < rhs.base()); }
	
	template <class U>
	bool	operator<=(const ReverseIterator<U>& rhs) { return (this->base() >= rhs.base()); }
	
	template <class U>
	bool	operator>=(const ReverseIterator<U>& rhs) { return (this->base() <= rhs.base()); }
	
	iterator_type	base() const { return (this->current); }

	template <class Iterator>	
	difference_type operator-(const ReverseIterator<Iterator>& rhs)
	{
		return (rhs.base() - this->base());
	}

	ReverseIterator	operator+(difference_type n) const
	{
		return (ReverseIterator(this->current - n));
	}
	ReverseIterator&	operator++()
	{
		--this->current;
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
		return (ReverseIterator(this->current + n));
	}

	ReverseIterator&	operator--()
	{
		++this->current;
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
	reference	operator[](difference_type n) const { return *(this->operator+(n));}
	reference	operator*() const
	{
		iterator_type tmp(this->current);
		return (*--tmp);
	}
	pointer		operator->() const { return (&(operator*()));}

	protected:
	
	Iter	current;
};

template <class Iterator>
bool operator== (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs)
{
	return (lhs.base() == rhs.base());
}
template <class Iterator, class Iterator2>
bool operator== (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator2>& rhs)
{
	return (lhs.base() == rhs.base());
}

template <class Iterator>
bool operator!= (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs)
{
	return (lhs.base() != rhs.base());
}
template <class Iterator, class Iterator2>
bool operator!= (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator2>& rhs)
{
	return (lhs.base() != rhs.base());
}

template <class Iterator>
bool operator< (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs)
{
	return (lhs.base() > rhs.base());
}
template <class Iterator, class Iterator2>
bool operator< (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator2>& rhs)
{
	return (lhs.base() > rhs.base());
}

template <class Iterator>
bool operator> (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs)
{
	return (lhs.base() < rhs.base());
}
template <class Iterator, class Iterator2>
bool operator> (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator2>& rhs)
{
	return (lhs.base() < rhs.base());
}

template <class Iterator>
bool operator<= (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs)
{
	return (lhs.base() >= rhs.base());
}
template <class Iterator, class Iterator2>
bool operator<= (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator2>& rhs)
{
	return (lhs.base() >= rhs.base());
}

template <class Iterator>
bool operator>= (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs)
{
	return (lhs.base() <=rhs.base());
}
template <class Iterator, class Iterator2>
bool operator>= (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator2>& rhs)
{
	return (lhs.base() <= rhs.base());
}

template <class Iterator, class Iterator2>	
typename ReverseIterator<Iterator>::difference_type operator-(const ReverseIterator<Iterator>& lhs,
const ReverseIterator<Iterator2>& rhs)
{
	return (lhs.base() + rhs.base());
}

template <class Iterator, class Iterator2>	
bool operator-(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator2>& rhs)
{
	return (lhs.base() + rhs.base());
}

template <class Iterator>	
ReverseIterator<Iterator> operator+(typename ReverseIterator<Iterator>::difference_type n,
const ReverseIterator<Iterator>& rhs)
{
	return (rhs + n);
}

}

#endif
