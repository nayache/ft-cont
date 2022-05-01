/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:54:17 by nayache           #+#    #+#             */
/*   Updated: 2022/05/01 16:24:09 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <iostream>
# include <iterator>
# include <stdexcept>
# include <limits>
# include <cstddef>
# include "../iterators/random_iterator.hpp"
# include "../iterators/reverse_iterator.hpp"
# include "../enable_if.hpp"
# include "../is_integral.hpp"
# include "../lexicographical.hpp"
# include "../utils.hpp"

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
		typedef RandomIterator<value_type>						iterator;		
		typedef RandomIterator<const value_type>				const_iterator;		
		typedef typename ft::ReverseIterator<iterator>			reverse_iterator;		
		typedef typename ft::ReverseIterator<const_iterator>	const_reverse_iterator;
	
		//DESTRUCTOR	
		
		~vector()
		{
			if (this->_data == NULL)
				return;

			this->clear();
			this->_alloc.deallocate(this->_data, this->_capacity);
		}
		
		//CONSTRUCTORS
		
		explicit	vector(const allocator_type& alloc = allocator_type()) : 
		_alloc(alloc), _data(NULL), _size(0), _capacity(0) {}

		explicit vector(size_type n, const value_type& val = value_type(),
		const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(n), _capacity(n)
		{
			this->_data = this->_alloc.allocate(this->_capacity);
			for (size_type i = 0; i < n; i++)
				this->_alloc.construct(_data + i, val);
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NullPtr) : _alloc(alloc), _size(0)
		{
			this->_capacity = ft::distance(first, last);
			this->_size = this->_capacity;
			this->_data = this->_alloc.allocate(_size);
			for (size_type i = 0; first != last; i++)
			{
				this->_alloc.construct(_data + i, *first);
				first++;
			}
		}
		
		vector(const vector& x) : _alloc(x._alloc), _size(x._size), _capacity(x._capacity)
		{
			if (this->_capacity == 0)
				return;

			this->_data = this->_alloc.allocate(this->_capacity);
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.construct(_data + i, x[i]);
		}

		vector& operator=(const vector& src)
		{
			if (&src == this)
				return (*this);

			this->clear();
			if (src.size() > this->_capacity)
			{
				this->_alloc.deallocate(this->_data, this->_capacity);
				this->_capacity = src.size();
				this->_data = this->_alloc.allocate(this->_capacity);
			}

			for (size_type i = 0; i < src.size(); i++)
				this->push_back(src[i]);

			return (*this);
		}

		//MODIFIERS
		
		void	assign(size_type n, const value_type& val)
		{
			this->clear();
			if (n == 0)
				return;
			if (this->_capacity < n)
			{
				this->reserve(n);
				this->_capacity = n;
			}
			for (size_type i = 0; i < n; i++)
				this->_alloc.destroy(this->_data + i);
			this->_size = 0;
			for (size_type i = 0; i < n; i++)
			{
				_alloc.construct(this->_data + i, val);
				this->_size++;
			}
		}

		template <class Iterator>
		void	assign(Iterator first, Iterator last,
		typename ft::enable_if<!ft::is_integral<Iterator>::value, Iterator>::type* = NullPtr)
		{
			size_type n = ft::distance(first, last);
			if (this->_capacity < n)
			{
				this->reserve(n);
				this->_capacity = n;
			}
			for (size_type i = 0; i < n; i++)
				this->_alloc.destroy(this->_data + i);
			this->_size = 0;
			for (size_type i = 0; first != last; i++)
			{
				_alloc.construct(this->_data + i, *first);
				first++;
				this->_size++;
			}
		}		
		void	push_back(const value_type& val)
		{
			if (this->_size == this->_capacity)
			{
				if (this->_capacity == 0)
				{
					this->_data = this->_alloc.allocate(1);
					this->_capacity = 1;
				}
				else
					this->reserve(this->_capacity * 2);
			}
			this->_alloc.construct(this->_data + this->_size, val);
			this->_size++;
		}

		void	pop_back()
		{
			if (this->_size)
				this->_size--;
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
			size_type	ret = position - this->begin();
			
			this->insert(position, 1, val);
			
			return (iterator(this->_data + ret));
		}

		void	insert(iterator position, size_type n, const value_type& val)
		{
			size_type	start = position - this->begin();
			
			while (this->_capacity < this->_size + n)
			{
				if (this->_capacity * 2 < this->_size + n)
					this->reserve(this->_size + n);
				else
					this->reserve(this->_capacity * 2);
			}
			
			this->_size += n;
			
			if (this->_size - n > 0)
			{
				int	index = this->_size - 1;

				while (index - static_cast<int>(n) >= static_cast<int>(start))
				{
					this->_data[index] = this->_data[index - n];
					index--;
				}
			}
			for (size_type i = 0; i < n; i++)
				this->_alloc.construct(this->_data + start + i, val);
		}

		template <class InputIterator>
		void	insert(iterator position, InputIterator first, InputIterator last,
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NullPtr)
		{
			while (first != last)
			{
				value_type val = *first;
				position = this->insert(position, val);
				position++;
				first++;
			}
		}
		
		iterator	erase(iterator position)
		{
			for (size_type i = position - this->begin() ; i < _size - 1 ; i++)
				this->_data[i] = this->_data[i + 1];

			this->_size--;
			this->_alloc.destroy(this->_data + this->_size);

			return (position);
		}

		iterator	erase(iterator first, iterator last)
		{
			difference_type n = ft::distance(first, last);
			
			for (difference_type i = 0; i < n; i++)
				first = erase(first);
			
			return (first);
		}

		//ELEMENT-ACCESS
		
		reference		operator[](size_type n) { return (*(this->_data + n)); }
		const_reference	operator[](size_type n) const { return (*(this->_data + n)); }
		reference	at(size_type n)
		{
			if (n >= this->_size)
			{
				std::string msg("vector::_M_range_check: __n (which is ");
				msg.insert(msg.size(), ft::itoa(n));
				msg.insert(msg.size(), ") >= this->size() (which is ");
				msg.insert(msg.size(), ft::itoa(static_cast<long long int>(this->size())));
				msg.insert(msg.size(), ")");
				throw std::out_of_range(msg);
			}
			else
				return (this->_data[n]);
		}
		const_reference	at(size_type n) const
		{
			if (n >= this->_size)
			{
				std::string msg("vector::_M_range_check: __n (which is ");
				msg.insert(msg.size(), ft::itoa(n));
				msg.insert(msg.size(), ") >= this->size() (which is ");
				msg.insert(msg.size(), ft::itoa(static_cast<long long int>(this->size())));
				msg.insert(msg.size(), ")");
				throw std::out_of_range(msg);
			}
			else
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
		const_iterator		begin() const { return (const_iterator(this->_data)); }
		reverse_iterator	rbegin() { return (reverse_iterator(this->end())); }
		iterator		end() { return (this->begin() + this->_size); }
		const_iterator	end() const { return (this->begin() + this->_size); }
		reverse_iterator	rend() { return (reverse_iterator(this->begin())); }
		const_reverse_iterator	rbegin() const { return (const_reverse_iterator(this->end())); }
		const_reverse_iterator	rend() const { return (const_reverse_iterator(this->begin())); }
		
		/// CAPACITY
		
		size_type	size() const { return (this->_size); }
		size_type	capacity() const { return (this->_capacity); }
		size_type	max_size() const { return (this->_alloc.max_size()); }
		bool		empty() const { return (this->_size == 0); }
		
		void	resize(size_type n, value_type val = value_type())
		{
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
			if (n > this->max_size())
				throw (std::length_error("vector::reserve"));

			else if (n > this->_capacity)
			{
				pointer	newVec = this->_alloc.allocate(n);

				for (size_type i = 0; i < this->_size; i++)
				{
					this->_alloc.construct(newVec + i, this->_data[i]);
					this->_alloc.destroy(this->_data + i);
				}
				this->_alloc.deallocate(this->_data, this->_capacity);
				this->_capacity = n;
				this->_data = newVec;
			}
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

template <class T, class Alloc>
void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
{
	x.swap(y);
}

template <class T, class Alloc>
bool	operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}
template <class T, class Alloc>
bool	operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
	return (!(lhs == rhs));
}
template <class T, class Alloc>
bool	operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
	rhs.end()));
}
template <class T, class Alloc>
bool	operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
	return (rhs < lhs);
}
template <class T, class Alloc>
bool	operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
	return (!(rhs < lhs));
}
template <class T, class Alloc>
bool	operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
	return (!(lhs < rhs));
}

}
#endif
