/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:55:46 by nayache           #+#    #+#             */
/*   Updated: 2022/03/08 16:57:26 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
# define BST_HPP

# include "includes/pair.hpp"
# include <cstddef>
# include <iostream>
# include <memory>
# include <functional>

namespace ft {
template <class K, class V>
class Node
{
	public:

	typedef ft::pair<K, V>	value_type;
	
	Node() : _empty(true),_left(NULL), _right(NULL) {}

	Node(const value_type& src) : _empty(false), _left(NULL), _right(NULL), _pair(src) {}

	~Node() {}

	Node&	operator=(const	Node& src)
	{
		this = &src;
		return (*this);
	}

	bool	isEmpty() { return (_empty == true); }
	
	void	setValues(K key, V value)
	{
		if (this->_empty == true)
		{
			this->_pair = ft::make_pair(key, value);
			this->_empty = false;
		}
	}

//	private:
	//---------attributes-------------
	bool					_empty;
	Node*					_left;
	Node*					_right;
	value_type				_pair;
	//--------------------------------
};

template <class K, class V, class NodeType = Node<K, V>,
class Allocator = std::allocator<NodeType>, class Compare = std::less<K> >
class BinarySearchTree
{
	public:

	typedef ft::pair<K, V>				pair_type;
	typedef Allocator					alloc_type;
	typedef	NodeType					node_type;
	typedef	NodeType*					node_pointer;
	typedef K							key_type;
	typedef V							value_type;

	
	BinarySearchTree(const alloc_type alloc = alloc_type()) : _alloc(alloc)
	{
		this->_main = this->_alloc.allocate(1);
		this->_alloc.construct(this->_main, node_type());
	}

	~BinarySearchTree() { freeTree(this->_main); }

	void	addNode(pair_type pair)
	{
		if (keyExist(this->_main, pair.first) == true)
		{
			pair_type currentPair = searchKey(this->_main, pair.first);
			currentPair.second = pair.second;
			return;
		}

		node_pointer newNode = this->_alloc.allocate(1);
		this->_alloc.construct(newNode, node_type(pair));
		node_pointer place = searchPlace(this->_main, pair.first);
		
		if (pair.first < place->_pair.first)
			place->_left = newNode;
		else
			place->_right = newNode;
	}

	pair_type&	searchKey(node_pointer current, const key_type& k)
	{
		if (k == current->_pair.first)
			return (current->_pair);
		else if (k < current->_pair.first)
			return (searchKey(current->_left, k));
		else
			return (searchKey(current->_left, k));
	}

//	private:
	//--------------attributes----------
	
	node_pointer			_main;
	alloc_type				_alloc;
	
	//---------------------------------
	
	void	freeTree(node_pointer Bst)
	{
		if (Bst == NULL)
			return;
		
		if (Bst->_right != NULL)
			freeTree(Bst->_right);
		
		if (Bst->_left != NULL)
			freeTree(Bst->_left);
		
		this->_alloc.destroy(Bst);
		this->_alloc.deallocate(Bst, 1);
	}
	
	bool	keyExist(node_pointer Bst, key_type key)
	{
		node_pointer tmp = searchPlace(Bst, key);
		
		return (tmp->_pair.first == key);
	}

	node_pointer	searchPlace(node_pointer Bst, key_type key)
	{

		if (key < Bst->_pair.first)
		{
			if (Bst->_left == NULL)
				return (Bst);
			else
				return searchPlace(Bst->_left, key);
		}
		else
		{
			if (Bst->_right == NULL)
				return (Bst);
			else
				return searchPlace(Bst->_right, key);
		}
		return (Bst);
	}
};

}

#endif
