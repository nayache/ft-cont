/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:54:17 by nayache           #+#    #+#             */
/*   Updated: 2021/12/13 13:59:02 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>
#include <iterator>
#include "utils.hpp"
#include "reverse_iterator.hpp"
#include "vector_iterator.hpp"

namespace ft {

template <class T, class Allocator = std::allocator<T> >
class	vector
{
	public:
	
		typedef T												value_type;
		typedef Allocator										allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef	typename allocator_type::pointer				pointer;
		typedef	typename allocator_type::const_pointer			const_pointer;
		typedef typename std::ptrdiff_t							difference_type;
		typedef	typename allocator_type::size_type				size_type;
		typedef typename ft::VecIterator<value_type>			iterator;		
		typedef typename ft::VecIterator<const value_type>		const_iterator;		
		typedef typename ft::ReverseIterator<iterator>			reverse_iterator;		
		typedef typename ft::ReverseIterator<const_iterator>	const_reverse_iterator;		

		explicit	vector(const allocator_type& alloc = allocator_type()) : 
		_alloc(alloc), _data(0), _size(0), _capacity(0) {}
		
		explicit	vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
		_alloc(alloc), _size(n), _capacity(n)
		{
			std::cout << "constructor size/val" << std::endl;
			_data = _alloc.allocate(_size);
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_data + i, val);
		}
	
		template <class Iterator>	
		vector(Iterator first, Iterator last, const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(0)
		{
			std::cout << "constructor iterators" << std::endl;
			_capacity = ft::distance(first, last);
			_size = _capacity;
			_data = _alloc.allocate(_size);
			for (size_type i = 0; first != last; i++)
			{
				_alloc.construct(_data + i, *first);
				first++;
			}
		}
		
		void	assign(size_type n, const value_type& val)
		{
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_data + i, val);
		}

		#include <stdio.h>
		template <class Iterator>
		void	assign(Iterator first, Iterator last)
		{
			for (size_type i = 0; first != last; i++)
			{
				_alloc.construct(_data + i, *first);
				first++;
			}
		}

		pointer	getData() { return this->_data; }
		
		void	print()
		{
			unsigned long i = 0;
			for (pointer tmp = _data; i < _size; i++)
				std::cout << '[' << *(tmp + i) << ']';
			_alloc.deallocate(_data, _capacity);
		}
		//operators

		reference	operator[](difference_type n) const {return (*(this->_data + n));}

		//iterator funcs
		
		iterator		begin() {return (iterator(this->_data));}
		const_iterator	cbegin() {return (const_iterator(this->_data));}
		iterator		end()
		{
			iterator it = this->begin();
			for (size_type i = 0; i < _size; i++)
				it++;
			return (it);
		}
		const_iterator	cend()
		{
			const_iterator it = this->cbegin();
			for (size_type i = 0; i < _size; i++)
				it++;
			return (it);
		}
	private:

		allocator_type	_alloc;
		pointer			_data;
		size_type		_size;
		size_type		_capacity;
};	
}
#endif
