/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:55:46 by nayache           #+#    #+#             */
/*   Updated: 2022/03/17 18:31:12 by nayache          ###   ########.fr       */
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
	
	Node() : _empty(true),_left(NULL), _right(NULL) , _parent(NULL){}

	Node(const value_type& src) : _empty(false), _left(NULL), _right(NULL), _parent(NULL), _pair(src) {}

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
	Node*					_parent;
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

	
	BinarySearchTree(const alloc_type alloc = alloc_type()) : _alloc(alloc), _main(NULL)
	{
		this->_begin = this->_alloc.allocate(1);
		this->_alloc.construct(this->_begin, node_type());
		this->_end = this->_alloc.allocate(1);
		this->_alloc.construct(this->_end, node_type());
	}

	~BinarySearchTree()
	{
		if (this->_begin != NULL)
		{
			this->_alloc.destroy(this->_begin);
			this->_alloc.deallocate(this->_begin, 1);
		}
		if (this->_end != NULL)
		{
			this->_alloc.destroy(this->_end);
			this->_alloc.deallocate(this->_end, 1);
		}
		freeTree(this->_main); 
	}

	node_pointer	createNode(node_pointer parent, pair_type pair)
	{
		node_pointer newNode = this->_alloc.allocate(1);
		this->_alloc.construct(newNode, node_type(pair));
		
		if (parent == NULL)
		{
			this->_begin->_right = newNode;
			this->_end->_left = newNode;
		}
		else if (newNode->_pair.first < this->_begin->_right->_pair.first)
			this->_begin->_right = newNode;
		else if (newNode->_pair.first > this->_end->_left->_pair.first)
			this->_end->_right = newNode;

		newNode->_parent = parent;

		return (newNode);
	}
	
	node_pointer	insertNode(node_pointer root, node_pointer parent, node_pointer* ret, const pair_type& pair)
	{
		if (root == NULL)
			return ((*ret = createNode(parent, pair)));

		else if (pair.first < root->_pair.first)
		{
			parent = root;
			root->_left = insertNode(root->_left, parent, ret, pair);
		}
		
		else
		{
			parent = root;
			root->_right = insertNode(root->_right, parent, ret, pair);
		}
		
		return root;
	}

	node_pointer	minKey() const
	{
		node_pointer tmp = this->_main;

		while (tmp->_left != NULL)
			tmp = tmp->_left;
		return (tmp);
	}

//	private:
	//--------------attributes----------
	
	alloc_type				_alloc;
	node_pointer			_main;
	node_pointer			_begin;
	node_pointer			_end;
	
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
	

	node_pointer	searchByKey(node_pointer Bst, key_type key)
	{
		if (key == Bst->_pair.first)
			return (Bst);
		
		if (key < Bst->_pair.first)
		{
			if (Bst->_left == NULL)
				return (NULL);
			else
				return searchByKey(Bst->_left, key);
		}
		else
		{
			if (Bst->_right == NULL)
				return (NULL);
			else
				return searchByKey(Bst->_right, key);
		}
	}
};

template <class K, class V>
std::ostream&	operator<<(std::ostream& os, Node<K, V> src)
{
	os << "(" << "\033[1;33m" << src._pair.first << "\033[0;28m" << " | " << "\033[1;33m" << src._pair.second << "\033[0;28m" << ")";
	return (os);
}

}

#endif
