/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:54:17 by nayache           #+#    #+#             */
/*   Updated: 2021/12/16 13:36:15 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include "utils.hpp"
#include "reverse_iterator.hpp"
#include "vector_iterator.hpp"
#include <stdio.h> // a supp

namespace ft {

template <class T, class Allocator = std::allocator<T> >
class	vector
{
	public:
	
		typedef T												value_type;
		typedef Allocator										allocator_type;
		typedef T&												reference;
		typedef const T&										const_reference;
		typedef	T*												pointer;
		typedef	const T*										const_pointer;
		typedef	size_t											size_type;
		typedef typename std::ptrdiff_t							difference_type;
		typedef typename ft::VecIterator<value_type>			iterator;		
		typedef typename ft::VecIterator<const value_type>		const_iterator;		
		typedef typename ft::ReverseIterator<iterator>			reverse_iterator;		
		typedef typename ft::ReverseIterator<const_iterator>	const_reverse_iterator;
	
		//DESTRUCTOR	
		
		~vector()
		{
			delete this->_data;
		}
		
		//CONSTRUCTORS
		
		explicit	vector(const allocator_type& alloc = allocator_type()) : 
		_alloc(alloc), _data(0), _size(0), _capacity(0) {}
		
		explicit	vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
		_alloc(alloc), _size(n), _capacity(n)
		{
			//std::cout << "constructor size/val" << std::endl;
			_data = _alloc.allocate(_size);
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_data + i, val);
		}
	
		template <class Iterator>	
		vector(Iterator first, Iterator last, const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(0)
		{
			//std::cout << "constructor iterators" << std::endl;
			_capacity = ft::distance(first, last);
			_size = _capacity;
			_data = _alloc.allocate(_size);
			for (size_type i = 0; first != last; i++)
			{
				_alloc.construct(_data + i, *first);
				first++;
			}
		}

		vector& operator=(const vector& src)
		{
			if (this->_data)
				delete this->_data;
			this->_size = src.size();
			this->_capacity = src.capacity();
			this->_alloc = src._alloc;
			this->_data = _alloc.allocate(this->_capacity);
			this->assign(src.begin(), src.end());
			return (*this);
		}

		//MODIFIERS
		
		void	assign(size_type n, const value_type& val)
		{
			if (n > this->_capacity)
			{
				delete this->_data;
				this->_data = this->_alloc.allocate(n);
				this->_capacity = n;
			}
			this->_size = n;
			for (size_type i = 0; i < n; i++)
				_alloc.construct(this->_data + i, val);
		}

		template <class Iterator>
		void	assign(Iterator first, Iterator last)
		{
		//	std::cout << "ici assign(iterators)\n";
			size_type n = ft::distance(first, last);
			if (n > this->_capacity)
			{
				delete this->_data;
				this->_data = this->_alloc.allocate(n);
				this->_capacity = n;
			}
			this->_size = n;
			for (size_type i = 0; first != last; i++)
			{
				_alloc.construct(this->_data + i, *first);
				first++;
			}
		}

		void	print()
		{
			unsigned long i = 0;
			for (pointer tmp = _data; i < _size; i++)
				std::cout << '[' << *(tmp + i) << ']';
			_alloc.deallocate(_data, _capacity);
		}
		//ELEMENT-ACCESS
		
		reference	operator[](size_type n) const { return (*(this->_data + n)); }
		reference	at(size_type n) {
			if (n >= this->_size)
				throw std::out_of_range("check_acces_range: n index >= this->size() !");
			return (this->_data[n]);
		}
		const_reference	at(size_type n) const {
			if (n >= this->_size)
				throw std::out_of_range("n index >= this->size() !\n");
			return (this->_data[n]);
		}
		reference			front() { return (_data[0]); }
		reference			back() { return (_data[_size - 1]); }
		value_type			*data() { return (this->_data); }
		const value_type	*data() const { return (this->_data); }
		
		//ITERATORS funcs

		iterator			begin() { return (iterator(this->_data)); }
		const_iterator		cbegin() { return (const_iterator(this->_data)); }
		reverse_iterator	rbegin() { return (reverse_iterator(this->end() - 1)); }
		const_reverse_iterator	crbegin() { return (const_reverse_iterator(this->end() - 1)); }
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
		reverse_iterator	rend() { return (reverse_iterator(this->begin() - 1)); }
		const_reverse_iterator	crend() { return (const_reverse_iterator(this->begin() - 1)); }
		
		/// CAPACITY
		
		size_type	size() const { return (this->_size); }
		size_type	capacity() const { return (this->_capacity); }
	
	private:

		allocator_type	_alloc;
		pointer			_data;
		size_type		_size;
		size_type		_capacity;
};	
}
#endif
