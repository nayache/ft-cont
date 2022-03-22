/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:30:28 by nayache           #+#    #+#             */
/*   Updated: 2022/03/22 20:33:59 by nayache          ###   ########.fr       */
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

	map(const key_compare& comp = key_compare(), const alloc_type& alloc = alloc_type()) : _alloc(alloc), _comp(comp), _tree(tree_type())
	{}
	
/*	template <class InputIterator>
	map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
	const alloc_type& alloc = alloc_type(),
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NullPtr)
	:	_alloc(alloc), _tree(tree_type())
	{

	}

	map (const map& x) : _alloc(x._alloc), _tree(tree_type())
	{
		std::cout << "copy constructor\n";
	}*/
		
	ft::pair<iterator, bool>	insert(const value_type& val)
	{
		//node_type*	ret;
		
		if (this->_tree._main == NULL)
		{
			this->_tree._main = this->_tree.createNode(NULL, val);
			this->_tree._begin->_right = this->_tree._main;
			this->_tree._end->_left = this->_tree._main;
			return (ft::make_pair(iterator(this->_tree._main), true));
		}
		node_type*	newNode = this->_tree.searchByKey(this->_tree._main, val.first);
		
		if (newNode != NULL && newNode->_pair.first == val.first)	
			return (ft::make_pair(iterator(newNode), false));
		
		newNode = this->_tree.insertNode(this->_tree._main, val);
		
		return (ft::make_pair(iterator(newNode), true));
	}

	iterator	insert(iterator position, const value_type& val)
	{
		node_type*	ret;
		
		if (val.first < position->first)
		{
			while (val.first < position->first)
				--position;
		}
		else
		{
			while (val.first > position->first)
				++position;
		}
		std::cout << *position << std::endl;
		//  revenir a une position precedente de la boucle , plus opti?????
		if (position != NULL && position->first == val.first)
			return (iterator(this->_tree.searchByKey(this->_tree._main, val.first)));
		
		this->_tree.insertNode(position.getPtr(), (position.getPtr())->_parent, &ret, val);

		return (iterator(ret));
	}
	
	size_type erase (const key_type& k)
	{
		if (this->_tree.searchByKey(this->_tree._main, k) == NULL)
			return (0);
		
		this->_tree.remove(k);
		return (1);
	}

	iterator				begin() { return (iterator(this->_tree.minKey())); }
	const_iterator			begin() const { return (const_iterator(this->_tree._begin->_right)); }
	iterator				end() { return (iterator(this->_tree._end->_left)); }
	const_iterator			end() const { return (const_iterator(this->_tree._end)); }
	reverse_iterator		rbegin() { return (reverse_iterator(NULL)); }
	const_reverse_iterator	rbegin() const { return (const_reverse_iterator(NULL)); }
	reverse_iterator		rend() { return (reverse_iterator(this->_tree.minKey())); }
	const_reverse_iterator	rend() const { return (const_reverse_iterator(this->_tree.minKey())); }

	void print2(node_type* root, int space)
	{
    // Base case
    	if (root == NULL)
		{
        	return;
		}
 
  	 	space += 5;
 
    // Process right child first
		if (root->_right != NULL)
    		print2(root->_right, space);
 
    // Print current node after space
    // count
    	std::cout << std::endl;
    	for (int i = 2; i < space; i++)
        	std::cout << " ";
    	std::cout << root->_pair.first <<"\n";
 
    // Process left child
		if (root->_left != NULL)
    		print2(root->_left, space);
	}
 
	// Wrapper over print2DUtil()
	void print()
	{
    // Pass initial space count as 0
    	print2(this->_tree._main, 0);
	}

	public:

	alloc_type		_alloc;
	key_compare		_comp;
	tree_type		_tree;
};

}

#endif
