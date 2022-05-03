/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:55:46 by nayache           #+#    #+#             */
/*   Updated: 2022/04/22 13:55:17 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
# define BST_HPP

# include "pair.hpp"
# include <cstddef>
# include <iostream>
# include <memory>
# include <functional>
# include <algorithm>
# include <unistd.h> //a supppppppppp

namespace ft {
template <class K, class V>
class Node
{
	public:

	typedef ft::pair<K, V>	value_type;
	
	Node() : _left(NULL), _right(NULL) , _parent(NULL){}

	Node(const value_type& src) : _left(NULL), _right(NULL), _parent(NULL), _pair(src) {}
	template <class U, class W>
	Node(const Node<U, W>& src) : _left(src._left), _right(src._right), _parent(src._parent), _pair(src._pair), _height(src._height) {}
	
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

	//---------attributes-------------
	Node*					_left;
	Node*					_right;
	Node*					_parent;
	value_type				_pair;
	int						_height;
	//--------------------------------
};

template <class K, class V, class Compare = std::less<K>, class NodeType = Node<K, V>, 
class Allocator = std::allocator<NodeType> >
class BinarySearchTree
{
	public:

	typedef ft::pair<K, V>				pair_type;
	typedef Allocator					alloc_type;
	typedef	NodeType					node_type;
	typedef	NodeType*					node_pointer;
	typedef K							key_type;
	typedef V							value_type;
	typedef Compare						key_compare;

	
	BinarySearchTree(const alloc_type alloc = alloc_type(), const key_compare comp = key_compare()) : _alloc(alloc), _comp(comp), _root(NULL)
	{
		this->_end = this->_alloc.allocate(1);
	}
	
	~BinarySearchTree()
	{
		if (this->_root != NULL)
			freeTree(this->_root);
		if (this->_end != NULL)
			this->_alloc.deallocate(this->_end, 1); 
	}
	
	BinarySearchTree(const BinarySearchTree& src)
	{
		if (&src != this)
			*this = src;
	}

	BinarySearchTree&	operator=(const BinarySearchTree& src)
	{
		this->_alloc = src._alloc;
		this->_comp = src._comp;
		this->_root = src._root;
		this->_end = src._end;

		return (*this);
	}
	
	void	swap(BinarySearchTree& x)
	{
		node_pointer	tmp = this->_root;
		node_pointer	tmp2 = this->_end;
		alloc_type		tmp3 = this->_alloc;

		this->_root = x._root;
		this->_end = x._end;
		this->_alloc = x._alloc;

		x._root = tmp;
		x._end = tmp2;
		x._alloc = tmp3;
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
					this->_alloc.destroy(this->_root);
					this->_alloc.deallocate(this->_root, 1);
					this->_root = NULL;
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
		node_pointer	tmp = this->_root;
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
			if (upper(linker->_pair.first, pair.first))
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
		
		return (searchByKey(this->_root, pair.first));
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
		if (tmp == this->_root)
			treeFix(this->_root);
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
		
		if (x != NULL && x->_left != NULL && this->_comp(x->_pair.first, x->_left->_pair.first))
			swapNode(x, x->_left);

		this->_alloc.destroy(tmp);
		this->_alloc.deallocate(tmp, 1);
	}
	
	void	swapNode(node_pointer a, node_pointer b)
	{
		pair_type c = a->_pair;

		a->_pair = b->_pair;
		b->_pair = c;
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
		
		if (x != NULL && x->_left != NULL && this->_comp(x->_pair.first, x->_left->_pair.first))
			swapNode(x, x->_left);
	
		this->_alloc.destroy(tmp);
		this->_alloc.deallocate(tmp, 1);
	}

	node_pointer	findMin() const
	{
		node_pointer tmp = this->_root;
		
		if (tmp == NULL)
			return (this->_end);

		while (tmp->_left != NULL)
			tmp = tmp->_left;
		return (tmp);
	}
	
	node_pointer	findMax() const
	{
		node_pointer tmp = this->_root;

		if (tmp == NULL)
			return (this->_end);
		
		while (tmp->_right != NULL)
			tmp = tmp->_right;
		return (tmp);
	}

	//--------------attributes----------
	
	alloc_type				_alloc;
	key_compare				_comp;
	node_pointer			_end;
	node_pointer			_root;
	
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
		
		if (this->_comp(key, Bst->_pair.first))
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
	
	bool    upper(const key_type& a, const key_type& b)
    {
        return (this->_comp(a, b) == false && equal(a, b) == false);
    }
    
    bool    equal(const key_type& a, const key_type& b)
    {
        if (this->_comp(a, b) == false && this->_comp(b, a) == false)
            return (true);
        return (false);
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
    	print2(this->_root, 0);
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
