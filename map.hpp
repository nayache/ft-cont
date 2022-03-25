/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:30:28 by nayache           #+#    #+#             */
/*   Updated: 2022/03/25 17:53:17 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "Bst.hpp"
# include "map_iterator.hpp"
# include "includes/is_integral.hpp"
# include "includes/enable_if.hpp"
# include "includes/utils.hpp"
# include <unistd.h>

namespace ft {
template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
class	map
{
	public:

	typedef	Key													key_type;
	typedef T													mapped_type;
	typedef	ft::pair<const Key, T>								value_type;
	typedef	Compare												key_compare;
	typedef	Alloc												alloc_type;
	typedef typename alloc_type::pointer						pointer;
	typedef typename alloc_type::const_pointer					const_pointer;
	typedef	value_type&											reference;
	typedef	const value_type&									const_reference;
	typedef size_t												size_type;
	typedef BinarySearchTree<key_type, mapped_type>				tree_type;
	typedef Node<key_type, mapped_type>							node_type;
	typedef	ft::MapIterator<Key, T, false>						iterator;
	typedef	ft::MapIterator<Key, T, true>						const_iterator;
	typedef ft::RevMapIterator<Key, T, false>					reverse_iterator;
	typedef ft::RevMapIterator<Key, T, true>					const_reverse_iterator;

//---------------------------CONSTRUCTORS--------------------------------------/
	
	map(const key_compare& comp = key_compare(), const alloc_type& alloc = alloc_type()) : _alloc(alloc), _comp(comp), _tree(tree_type())
	{}
	
	template <class InputIterator>
	map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
	const alloc_type& alloc = alloc_type(),
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NullPtr)
	:	_alloc(alloc), _comp(comp), _tree(tree_type())
	{
		this->insert(first, last);	
	}

	map (const map& x) : _alloc(x._alloc), _comp(x._comp), _tree(tree_type())
	{
		this->insert(x.begin(), x.end());
	}
	
	~map()
	{}

	map&	operator=(const map& x)
	{
		if (this == &x)
			return (*this);

		this->clear();
		this->_alloc = x._alloc;
		this->_comp = x._comp;

		this->insert(x.begin(), x.end());

		return (*this);
	}

//--------------------------------MODIFIERS-----------------------------------//

	ft::pair<iterator, bool>	insert(const value_type& val)
	{
		if (this->_tree._main == NULL)
		{
			this->_tree._main = this->_tree.createNode(NULL, val);
			return (ft::make_pair(iterator(this->_tree._main), true));
		}
		node_type*	newNode = this->_tree.searchByKey(this->_tree._main, val.first);
		
		if (newNode != NULL)	
			return (ft::make_pair(iterator(newNode), false));
		
		newNode = this->_tree.insertNode(this->_tree._main, val);
		
		return (ft::make_pair(iterator(newNode), true));
	}

	iterator	insert(iterator position, const value_type& val)
	{
		node_type*	ret;
		
		if (position.getPtr() != NULL && val.first < position->first)
		{
			while (position.getPtr() != NULL && val.first < position->first)
				--position;
		}
		else
		{
			if (position.getPtr() != NULL)
				while (position.getPtr() != NULL && val.first > position->first)
					++position;
		}
		if (position.getPtr() != NULL && position->first == val.first)
			return (iterator(position.getPtr()));
		
		if (position.getPtr() != NULL)	
			ret = this->_tree.insertNode(position.getPtr(), val);
		else
			ret = this->_tree.insertNode(this->_tree._main, val);
			
		return (iterator(ret));
	}
	
	template <class InputIterator>
	void insert (InputIterator first, InputIterator last,
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NullPtr)
	{
		while (first != last)
			this->insert(*first++);
	}

	void	erase (iterator position)
	{
		this->erase(position->first);
	}

	size_type erase (const key_type& k)
	{
		if (this->find(k) == NULL)
			return (0);
		
		this->_tree.remove(k);

		return (1);
	}
	
	void	erase(iterator first, iterator last)
	{
		key_type b = first->first;
		key_type e = (--last)->first;
		
		iterator tmp = this->begin();
		
		while (tmp->first != e)
		{
			while (tmp->first < b)
				tmp++;
			
			std::cout << "-> "	<< tmp->first << " <-\n";
			this->erase(tmp);
			tmp = this->begin();
		}
		if (tmp->first == e)
		{
			std::cout << "-> "	<< tmp->first << " <-\n";
			this->erase(tmp);
		}
		
	}
	
	void	clear()
	{
		this->erase(this->begin(), this->end());
		this->_tree._main = NULL;
	}

//----------------------------ITERATORS---------------------------------------//

	iterator				begin() { return (iterator(this->_tree.findMin())); }
	const_iterator			begin() const { return (const_iterator(this->_tree.findMin())); }
	iterator				end() { return (iterator(this->_tree.findMax())); }
	const_iterator			end() const { return const_iterator(this->_tree.findMax()); }
	reverse_iterator		rbegin() { return (reverse_iterator(this->end())); }
	const_reverse_iterator	rbegin() const { return (const_reverse_iterator(this->rbegin())); }
	reverse_iterator		rend() { return (reverse_iterator(this->_tree.findMin())); }
	const_reverse_iterator	rend() const { return (const_reverse_iterator(this->rend())); }

//---------------------------OPERATIONS--------------------------------------/

	iterator	find(const key_type& k)
	{
		if (this->_tree._main == NULL)
			return (NULL);
		
		node_type*	finder = this->_tree.searchByKey(this->_tree._main, k);

		if (finder == NULL)
			return (this->end());

		return (iterator(finder));
	}

	const_iterator	find(const key_type& k) const
	{
		if (this->_tree._main == NULL)
			return (NULL);

		node_type*	finder = this->_tree.searchByKey(this->_tree._main, k);

		if (finder == NULL)
			return (this->end());

		return (const_iterator(finder));
	}

	size_type	count(const key_type& k) const
	{
		if (this->_tree._main == NULL || this->_tree.searchByKey(this->_tree._main, k) == NULL)
			return (0);
		return (1);
	}

//	iterator	lower_bound(const key_type& k)

//-------------------------------CAPACITY-------------------------------------/
	
	size_type	size()	const
	{
		size_type size = 0;
		this->_tree.treeSize(this->_tree._main, &size);
		
		return (size);
	}

	bool	empty() const { return (this->size() == 0 ? 1 : 0); }

//-------------------------------ELEMENT-ACCESS------------------------------//

	mapped_type&	operator[](const key_type& k)
	{
		if (this->_tree._main == NULL)
			this->insert(ft::make_pair(k, mapped_type()));
		
		iterator	ret = this->find(k);
		
		if (ret == this->end())
		{
			this->insert(ft::make_pair(k, mapped_type()));
			ret = this->find(k);
		}
		return (ret->second);		
	}

//----------------------------------------------------------------------------//
	void print2(node_type* root, int space)
	{
    	if (root == NULL)
		{
        	return;
		}
 
  	 	space += 5;
 
		if (root->_right != NULL)
    		print2(root->_right, space);
 
    	std::cout << std::endl;
    	for (int i = 2; i < space; i++)
        	std::cout << " ";
    	std::cout << root->_pair.first <<"\n";
 
		if (root->_left != NULL)
    		print2(root->_left, space);
	}
 
	void print()
	{
    	print2(this->_tree._main, 0);
	}

	public:

	alloc_type		_alloc;
	key_compare		_comp;
	tree_type		_tree;
};

}

#endif
