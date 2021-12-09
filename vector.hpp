/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:54:17 by nayache           #+#    #+#             */
/*   Updated: 2021/12/07 12:22:41 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>
#include <iterator>
#include "utils.hpp"

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
		

		explicit	vector(const allocator_type& alloc = allocator_type()) : 
		_alloc(alloc), _data(0), _size(0), _capacity(0) {}
		
		explicit	vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
		_alloc(alloc), _data(0), _size(n), _capacity(n)
		{	
			std::cout << "ici" << std::endl;;
			_data = _alloc.allocate(_size);
			//this->assign(n, val);
			for (int i = 0; i < n; i++)
			{
				_alloc.construct(_data + i, val);
			}
		}
		
		template <class InputIterator>
		explicit	vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : // probleme de diff type iterator
		_alloc(alloc), _size(0)
		{
			_capacity = ft::distance(first, last);
			_size = _capacity;
			_data = _alloc.allocate(_size);
			this->assign(first, last);
		}
		
		template <class InputIterator>
		void	assign(InputIterator first, InputIterator last)
		{
		//	for (size_type i = 0; first != last; i++)
//				_alloc.construct(_data + i, *first);
		}

		void	assign(size_type n, const value_type& val)
		{
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_data + i, val);
		}
		

		pointer	getData() { return this->_data; }
		
		void	print()
		{
			unsigned long i = 0;
			for (pointer tmp = _data; i < _size; i++)
				std::cout << '[' << *(tmp + i) << ']';
			_alloc.deallocate(_data, _capacity);
		}

	private:

		allocator_type	_alloc;
		pointer			_data;
		size_type		_size;
		size_type		_capacity;
};	
}
#endif
