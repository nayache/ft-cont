/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:55:46 by nayache           #+#    #+#             */
/*   Updated: 2022/03/25 17:47:05 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
# define BST_HPP

# include "includes/pair.hpp"
# include <cstddef>
# include <iostream>
# include <memory>
# include <functional>
# include <algorithm>

namespace ft {
template <class K, class V>
class Node
{
	public:

	typedef ft::pair<K, V>	value_type;
	
	Node() : _left(NULL), _right(NULL) , _parent(NULL){}

	Node(const value_type& src) : _left(NULL), _right(NULL), _parent(NULL), _pair(src) {}
	
	~Node() {}

	Node&	operator=(const	Node& src)
	{
		this = &src;
		return (*this);
	}
	
	void	copy(const Node& src)
	{
		this->_parent = src._parent;
		this->_left = src._left;
		this->_right = src._right;
		this->_height = src._height;
		this->_pair = src._pair;
	}

//	private:
	//---------attributes-------------
	Node*					_left;
	Node*					_right;
	Node*					_parent;
	value_type				_pair;
	int						_height;
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
	{}

	~BinarySearchTree()
	{
		if (this->_main != NULL)
			freeTree(this->_main); 
	}

	node_pointer	createNode(node_pointer parent, pair_type pair)
	{
		node_pointer newNode = this->_alloc.allocate(1);
		this->_alloc.construct(newNode, node_type(pair));
		
		newNode->_height = 0;
		newNode->_parent = parent;
		
		return (newNode);
	}
	
	void	removeNode(node_pointer parent, node_pointer curr, key_type key)
	{
		if (curr == NULL)
			return;

		if (curr->_pair.first == key)
		{
			if (curr->_left == NULL && curr->_right == NULL)
			{
				if (parent != NULL && parent->_pair.first == curr->_pair.first)
				{
					this->_alloc.destroy(this->_main);
					this->_alloc.deallocate(this->_main, 1);
					this->_main = NULL;
					return;
				}
				else if (parent->_right == curr)
					parent->_right = NULL;
				else
					parent->_left = NULL;
				this->_alloc.destroy(curr);
				this->_alloc.deallocate(curr, 1);
				rebalancer(parent);
			}
			else if (curr->_left != NULL && curr->_right == NULL)
			{
				pair_type tmp = curr->_pair;
				curr->_pair = curr->_left->_pair;
				curr->_left->_pair = tmp;
				removeNode(curr, curr->_left, key);
			}
			else if (curr->_left == NULL && curr->_right != NULL)
			{
				pair_type tmp = curr->_pair;
				curr->_pair = curr->_right->_pair;
				curr->_right->_pair = tmp;
				removeNode(curr, curr->_right, key);
			}
			else
			{
				node_pointer tmp = curr->_right;
				int flag = 0;

				while (tmp->_left)
				{
					flag = 1;
					parent = tmp;
					tmp = tmp->_left;
				}
				if (!flag)
					parent = curr;
				
				pair_type tmpPair = curr->_pair;
				curr->_pair = tmp->_pair;
				tmp->_pair = tmpPair;
				removeNode(parent, tmp, tmp->_pair.first);
			}
		}
	}
	
	void	remove(key_type key)
	{
		node_pointer	tmp = this->_main;
		node_pointer	parent = tmp;
		bool			flag = false;

		if (tmp == NULL)
			removeNode(NULL, NULL, key);

		while (tmp)
		{
			if (key == tmp->_pair.first)
			{
				flag = true;
				removeNode(parent, tmp, key);
				break;
			}
			else
			{
				parent = tmp;
				if (key < tmp->_pair.first)
					tmp = tmp->_left;
				else
					tmp = tmp->_right;
			}
		}
	}
	
	node_pointer	treeSearch(node_pointer root, key_type key)
	{
		if (root == NULL)
			return (NULL);
		
		if (root->_pair.first == key)
			return (root);
		else if	(root->_parent && root->_parent->_pair.first == key)
			return (root->_parent);
		
		return (NULL);
	}

	node_pointer	insertNode(node_pointer root, pair_type pair)
	{
		node_pointer linker = root;
		node_pointer newNode = createNode(NULL, pair);
		
		while (linker != NULL)
		{
			if (linker->_pair.first > pair.first)
			{
				if (linker->_left == NULL)
				{
					linker->_left = newNode;
					newNode->_parent = linker;
					break;
				}
				else
					linker = linker->_left;
			}
			else
			{
				if (linker->_right == NULL)
				{
					linker->_right = newNode;
					newNode->_parent = linker;
					break;
				}
				else
					linker = linker->_right;
			}
		}
		rebalancer(newNode);
		
		return (searchByKey(this->_main, pair.first));
	}
	
	int	getHeight(node_pointer tmp) { return ((tmp == NULL) ? -1 : tmp->_height); }

	int balanceFactor(node_pointer tmp)
	{
		return (getHeight(tmp->_right) - getHeight(tmp->_left));
	}

	void heightBalance(node_pointer tmp)
	{
		int l = -1;
		int r = -1;
		
		if (tmp->_left)
			l = tmp->_left->_height;
		if (tmp->_right)
			r = tmp->_right->_height;
		tmp->_height = std::max(l, r) + 1;
	}
	
	void treeFix(node_pointer tmp)
	{
		if (balanceFactor(tmp) == 2)
		{
			if (balanceFactor(tmp->_right) < 0)
				rightRotate(tmp->_right);
			leftRotate(tmp);
			heightBalance(tmp);
		}
		else if (balanceFactor(tmp) == -2)
		{
			if (balanceFactor(tmp->_left) > 0)
				leftRotate(tmp->_left);
			rightRotate(tmp);
			heightBalance(tmp);
		}
	}
	
	void rebalancer(node_pointer tmp)
	{
		if (tmp == this->_main)
			treeFix(this->_main);
		else 
		{
			while  (tmp != NULL)
			{
				heightBalance(tmp);
				tmp = tmp->_parent;
				if (tmp)
					treeFix(tmp);
			}
		}
	}
	
	void	leftRotate(node_pointer x)
	{
		node_pointer newNode = createNode(NULL, x->_pair);
		node_pointer tmp = x->_right;

		if (x->_right && x->_right->_left)
			newNode->_right = x->_right->_left;
		newNode->_left = x->_left;
		x->_pair = x->_right->_pair;

		x->_left = newNode;
		if (newNode->_left)
			newNode->_left->_parent = newNode;
		if (newNode->_right)
			newNode->_right->_parent = newNode;
		newNode->_parent = x;

		if (x->_right->_right)
			x->_right = x->_right->_right;
		else
			x->_right = NULL;

		if (x->_right)
			x->_right->_parent = x;

		heightBalance(x->_left);
		if (x->_right)
			heightBalance(x->_right);
		heightBalance(x);
		
		this->_alloc.destroy(tmp);
		this->_alloc.deallocate(tmp, 1);
	}

	void	rightRotate(node_pointer x)
	{
		node_pointer newNode = createNode(NULL, x->_pair);
		node_pointer tmp = x->_left;
		
		if (x->_left && x->_left->_right)
			newNode->_left = x->_left->_right;
		newNode->_right = x->_right;
		x->_pair = x->_left->_pair;

		x->_right = newNode;
		if (newNode->_left)
			newNode->_left->_parent = newNode;
		if (newNode->_right)
			newNode->_right->_parent = newNode;
		newNode->_parent = x;

		if (x->_left->_left)
			x->_left = x->_left->_left;
		else
			x->_left = NULL;

		if (x->_left)
			x->_left->_parent = x;

		heightBalance(x->_right);
		if (x->_left)
			heightBalance(x->_left);
		heightBalance(x);
	
		this->_alloc.destroy(tmp);
		this->_alloc.deallocate(tmp, 1);
	}

	node_pointer	findMin() const
	{
		node_pointer tmp = this->_main;

		while (tmp->_left != NULL)
			tmp = tmp->_left;
		return (tmp);
	}
	
	node_pointer	findMax() const
	{
		node_pointer tmp = this->_main;

		while (tmp->_right != NULL)
			tmp = tmp->_right;
		return (tmp);
	}

//	private:
	//--------------attributes----------
	
	alloc_type				_alloc;
	node_pointer			_main;
	
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
	
	void	treeSize(node_pointer root, std::size_t* size) const
	{
		if (root == NULL)
			return;

		*size += 1;

		if (root->_right != NULL)
			treeSize(root->_right, size);
		
		if (root->_left != NULL)
			treeSize(root->_left, size);
	}

	node_pointer	searchByKey(node_pointer Bst, key_type key) const
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
	
	void printNode(node_pointer x)
	{
		std::cout << "\033[1;28m" << x << "\033[0;28m";
		std::cout << " data : " << x->_pair;
		std::cout << " parent : ";
		if (x != NULL && x->_parent != NULL)
			std::cout << x->_parent->_pair;
		else
			std::cout << "\033[1;36mnil\033[0;28m ";
		std::cout << " left : ";
		if (x != NULL && x->_left != NULL)
			std::cout << x->_left->_pair;
		else
			std::cout << "\033[1;36mnil\033[0;28m ";
		std::cout << " right : ";
		if (x != NULL && x->_right != NULL)
			std::cout << x->_right->_pair;
		else
			std::cout << "\033[1;36mnil\033[0;28m ";
		std::cout << std::endl;
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
