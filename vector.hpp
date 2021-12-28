/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:54:17 by nayache           #+#    #+#             */
/*   Updated: 2021/12/28 16:12:23 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <iostream>
# include <iterator>
# include <stdexcept>
# include "utils.hpp"
# include "reverse_iterator.hpp"
# include "vector_iterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include <limits>
# include <cstddef>

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
			this->clear();
			this->_alloc.deallocate(this->_data, this->_capacity);
		}
		
		//CONSTRUCTORS
		
		explicit	vector(const allocator_type& alloc = allocator_type()) : 
		_alloc(alloc), _data(0), _size(0), _capacity(0) {}

		vector(size_type n, const value_type& val = value_type(),
		const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(n), _capacity(n)
		{
			_data = _alloc.allocate(_capacity);
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_data + i, val);
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NullPtr) : _alloc(alloc), _size(0)
		{
			_capacity = ft::distance(first, last);
			_size = _capacity;
			_data = _alloc.allocate(_size);
			for (size_type i = 0; first != last; i++)
			{
				_alloc.construct(_data + i, *first);
				first++;
			}
		}
		
		vector(const vector& x) : _alloc(x._alloc), _size(x._size), _capacity(x._capacity)
		{
			this->_data = this->_alloc.allocate(this->_capacity);
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.construct(_data + i, *(x._data + i));
		}

		vector& operator=(vector& src)
		{
			if (src._size > this->_capacity && this->_data)
			{
				delete this->_data;
				this->_data = this->_alloc.allocate(src._capacity);
			}
			this->_size = src._size;
			this->_capacity = src._capacity;
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
		void	push_back(const value_type& val)
		{
			if (this->_size >= this->_capacity)
				this->reserve(this->_capacity * 2);
			this->_alloc.construct(this->_data + this->_size, val);
			this->_size++;
		}

		void	pop_back()
		{
			this->erase(this->end() - 1);
		}

		void	clear()
		{
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.destroy(this->_data + i);
			this->_size = 0;
		}

        void    swap(vector<T>& x)
        {
            pointer tmp = x._data;
			allocator_type tmpAlloc = x._alloc;
			size_type tmpSize = x.size();
			size_type tmpCapacity = x.capacity();
			
			x._data = this->_data;
			x._alloc = this->_alloc;
			x._size = this->_size;
			x._capacity = this->_capacity;

			this->_data = tmp;
			this->_alloc = tmpAlloc;
			this->_size = tmpSize;
			this->_capacity = tmpCapacity;
        }
	
		iterator	insert(iterator position, const value_type& val)
		{
			value_type tmp;
			value_type tmp2;
			size_type dist = 0;
			iterator it = this->begin();
			while (it != this->end() && it != position)
			{
				dist++;
				it++;
			}
			if (position != it && position != this->end())
				return (this->end() + 4);
			if (it == position || position == this->end())
			{
				if (position == this->end())
				{
					push_back(val);
					return (this->end() - 1);
				}
				tmp = *it;
				*it = val;
				it++;
			}
			while (it != this->end())
			{
				tmp2 = *it;
				*it = tmp;
				tmp = tmp2;
				it++;
			}
			push_back(tmp);
			return (this->begin() + dist);
		}

		void	insert(iterator position, size_type n, const value_type& val)
		{
			for (size_type i = 0; i < n; i++)
				position = this->insert(position, val);
		}

		template <class InputIterator>
		void	insert(iterator position, InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				value_type val = *first;
				position = this->insert(position, val);
				first++;
			}
		}
		
		iterator	erase(iterator position)
		{
			size_type dist = ft::distance(this->begin(), position);
			iterator it = this->begin();
			
			while (it != this->end() && it != position)
				it++;
			if (position != it && position != this->end())
				return (this->end() + 4);
			while (it != this->end())
			{
				if (it + 1 != this->end())
					*it = *(it + 1);
				it++;
			}
			this->_size--;
			return (this->begin() + dist);
		}

		//ELEMENT-ACCESS
		
		reference		operator[](size_type n) { return (*(this->_data + n)); }
		const_reference	operator[](size_type n) const { return (*(this->_data + n)); }
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
		const_reference		front() const { return (_data[0]); }
		reference			back() { return (_data[_size - 1]); }
		const_reference		back() const { return (_data[_size - 1]); }
		value_type			*data() { return (this->_data); }
		const value_type	*data() const { return (this->_data); }
		
		//ITERATORS funcs

		iterator			begin() { return (iterator(this->_data)); }
		const_iterator		cbegin() { return (const_iterator(this->_data)); }
		reverse_iterator	rbegin() { return (reverse_iterator(this->end() - 1)); }
		const_reverse_iterator	crbegin() { return (const_reverse_iterator(this->end() - 1)); }
		iterator		end() { return (this->begin() + this->_size); }
		const_iterator	cend() { return (this->cbegin() + this->_size); }
		reverse_iterator	rend() { return (reverse_iterator(this->begin() - 1)); }
		const_reverse_iterator	crend() { return (const_reverse_iterator(this->begin() - 1)); }
		
		/// CAPACITY
		
		size_type	size() const { return (this->_size); }
		size_type	capacity() const { return (this->_capacity); }
		size_type	max_size() const { return (this->_alloc.max_size()); }
		bool		empty() const { return(this->_size == 0); }
		
		void	resize(size_type n, value_type val = value_type())
		{
			if (n == 0)
				return;
			
			size_type i = 0;
			if (n > this->_size)
			{
				if (n > this->_capacity)
					this->reserve(n);
				for (size_type count = n - this->_size; i < count; i++)
					this->push_back(val);
			}
			else
			{
				iterator ite = this->end();
				for (size_type count = this->_size; count > n; count--)
					this->erase(--ite);
			}
		}

		void	reserve(size_type n)
		{
			if (n <= this->_capacity)
				return;
			pointer tmp = this->_data;
			iterator it = this->begin();
			iterator ite = this->end();
			this->_capacity = n;
			this->_data = this->_alloc.allocate(this->_capacity);
			assign(it, ite);
			this->_alloc.deallocate(tmp, this->_capacity);
		}

		void	shrink_to_fit()
		{
			if (this->_size == this->_capacity)
				return;
			ft::vector<T> tmp(*this);
			this->clear();
			this->_alloc.deallocate(this->_data, this->_capacity);
			this->_capacity = tmp.size();
			this->_data = this->_alloc.allocate(this->_capacity);
			this->assign(tmp.begin(), tmp.end());
		}
		
		//ALLOCATOR
		allocator_type	get_allocator() const { return (Allocator()); }

	private:

		allocator_type	_alloc;
		pointer			_data;
		size_type		_size;
		size_type		_capacity;
};	
}
#endif
