/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:55:46 by nayache           #+#    #+#             */
/*   Updated: 2022/05/25 15:43:24 by nayache          ###   ########.fr       */
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
# include "utils.hpp"

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
		this->_root = src._root;
		this->_end = src._end;
		this->_alloc = src._alloc;
		this->_comp = src._comp;

		return (*this);
	}
	
	void	swap(BinarySearchTree& x)
	{
		ft::swapp(this->_root, x._root);
		ft::swapp(this->_end, x._end);
		ft::swapp(this->_alloc, x._alloc);
		ft::swapp(this->_comp, x._comp);
	}

	node_pointer	createNode(node_pointer parent, pair_type pair)
	{
		node_pointer newNode = this->_alloc.allocate(1);
		this->_alloc.construct(newNode, node_type(pair));
		
		newNode->_height = 0;
		newNode->_parent = parent;
		
		return (newNode);
	}
	
	void removeNode(node_pointer parent, node_pointer curr, key_type k)
	{
		if (curr == NULL)
			return;

		if (this->equal(curr->_pair.first, k))
		{
			if (curr->_left == NULL && curr->_right == NULL)
			{
				if (curr == this->_root)
				{
					this->_alloc.destroy(curr);
					this->_alloc.deallocate(curr, 1);
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
				swapLeft(curr, curr->_left);
				removeNode(curr->_parent, curr, k);
			}
			else if (curr->_left == NULL && curr->_right != NULL)
			{
				swapRight(curr, curr->_right);
				removeNode(curr->_parent, curr, k);
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
				if (flag == 0)
					swapRight(curr, tmp);
				else
					swapNodes(curr, tmp);
				
				removeNode(curr->_parent, curr, k);
			}
		}

	}
	
	void	swapRight(node_pointer a, node_pointer b)
	{
		node_pointer tmp_parent = a->_parent;
		node_pointer tmp_left = a->_left;
		int tmp_height = a->_height;

		a->_parent = b;
		a->_left = b->_left;
		if (a->_left)
			a->_left->_parent = a;
		a->_right = b->_right;
		if (a->_right)
			a->_right->_parent = a;
		a->_height = b->_height;

		if (tmp_parent && tmp_parent->_right == a)
			tmp_parent->_right = b;
		else if (tmp_parent && tmp_parent->_left == a)
			tmp_parent->_left = b;

		b->_parent = tmp_parent;
		b->_right = a;
		b->_left = tmp_left;
		if (b->_left)
			b->_left->_parent = b;
		b->_height = tmp_height;
		if (this->_root == a)
			this->_root = b;
	}

	void	swapLeft(node_pointer a, node_pointer b)
	{
		node_pointer tmp_parent = a->_parent;
		node_pointer tmp_right = a->_right;
		int tmp_height = a->_height;

		a->_parent = b;
		a->_left = b->_left;
		if (a->_left)
			a->_left->_parent = a;
		a->_right = b->_right;
		if (a->_right)
			a->_right->_parent = a;
		a->_height = b->_height;

		if (tmp_parent && tmp_parent->_right == a)
			tmp_parent->_right = b;
		else if (tmp_parent && tmp_parent->_left == a)
			tmp_parent->_left = b;

		b->_parent = tmp_parent;
		b->_right = tmp_right;
		if (b->_right)
			b->_right->_parent = b;
		b->_left = a;
		b->_height = tmp_height;
		if (this->_root == a)
			this->_root = b;
	}
	
	void	swapNodes(node_pointer a, node_pointer b)
	{
		node_pointer tmp_parent = a->_parent;
		node_pointer tmp_right = a->_right;
		node_pointer tmp_left = a->_left;
		int tmp_height = a->_height;
		
		if (b->_parent && b->_parent->_right == b)
			b->_parent->_right = a;
		else if (b->_parent && b->_parent->_left == b)
			b->_parent->_left = a;

		a->_parent = b->_parent;
		a->_left = b->_left;
		if (a->_left)
			a->_left->_parent = a;
		a->_right = b->_right;
		if (a->_right)
			a->_right->_parent = a;
		a->_height = b->_height;
		
		if (tmp_parent && tmp_parent->_right == a)
			tmp_parent->_right = b;
		else if (tmp_parent && tmp_parent->_left == a)
			tmp_parent->_left = b;
		
		b->_parent = tmp_parent;
		b->_right = tmp_right;
		if (b->_right)
			b->_right->_parent = b;
		b->_left = tmp_left;
		if (b->_left)
			b->_left->_parent = b;
		b->_height = tmp_height;
		if (this->_root == a)
			this->_root = b;
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
			if (equal(key, tmp->_pair.first))
			{
				flag = true;
				removeNode(parent, tmp, key);
				break;
			}
			else
			{
				parent = tmp;
				if (this->_comp(key, tmp->_pair.first))
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
				RightLeftRotate(tmp);
			leftRotate(tmp);
			heightBalance(tmp);
		}
		else if (balanceFactor(tmp) == -2)
		{
			if (balanceFactor(tmp->_left) > 0)
				LeftRightRotate(tmp);
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
	
	void LeftRightRotate(node_pointer x)
	{
		node_pointer tmp = x->_left;
		node_pointer tmp2 = x->_left->_right;

		tmp->_parent = tmp2;
		tmp2->_parent = x;
		
		if (tmp2->_left)
		{
			tmp->_right = tmp2->_left;
			tmp->_right->_parent = tmp;
		}
		else
			tmp->_right = NULL;
		
		x->_left = tmp2;
		
		tmp2->_left = tmp;

		heightBalance(x->_left);
		if (x->_right)
			heightBalance(x->_right);
		heightBalance(x);
	}

	void RightLeftRotate(node_pointer x)
	{
		node_pointer tmp = x->_right;
		node_pointer tmp2 = x->_right->_left;

		tmp->_parent = tmp2;
		tmp2->_parent = x;
		
		if (tmp2->_right)
		{
			tmp->_left = tmp2->_right;
			tmp->_left->_parent = tmp;
		}
		else
			tmp->_left = NULL;
		
		x->_right = tmp2;
		
		tmp2->_right = tmp;

		heightBalance(x->_right);
		if (x->_left)
			heightBalance(x->_left);
		heightBalance(x);
	}

	void	leftRotate(node_pointer x)
	{
		if (this->_comp(x->_right->_pair.first, x->_pair.first))
			swapRight(x, x->_right);

		node_pointer newRoot = x->_right;
		node_pointer parent = x->_parent;

		x->_parent = newRoot;

		newRoot->_parent = parent;

		if (x->_right && x->_right->_left)
			x->_right = x->_right->_left;
		else
			x->_right = NULL;

		newRoot->_left = x;

		if (parent && parent->_right == x)
			parent->_right = newRoot;
		else if (parent && parent->_left == x)
			parent->_left = newRoot;

		if (x->_right)
			x->_right->_parent = x;

		if (parent == NULL)
			this->_root = newRoot;
		
		heightBalance(newRoot->_left);
		if (newRoot->_right)
			heightBalance(newRoot->_right);
		heightBalance(newRoot);
	}
	
	void	rightRotate(node_pointer x)
	{
		if (this->upper(x->_left->_pair.first, x->_pair.first))
			swapLeft(x, x->_left);

		node_pointer newRoot = x->_left;
		node_pointer parent = x->_parent;

		x->_parent = newRoot;

		newRoot->_parent = parent;

		if (x->_left && x->_left->_right)
			x->_left = x->_left->_right;
		else
			x->_left = NULL;

		newRoot->_right = x;

		if (parent && parent->_right == x)
			parent->_right = newRoot;
		else if (parent && parent->_left == x)
			parent->_left = newRoot;

		if (x->_left)
			x->_left->_parent = x;

		if (parent == NULL)
			this->_root = newRoot;
		
		heightBalance(newRoot->_right);
		if (newRoot->_left)
			heightBalance(newRoot->_left);
		heightBalance(newRoot);
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

	node_pointer	findMax(node_pointer root) const
	{
		while (root->_right != NULL)
			root = root->_right;
		return (root);
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
		if (Bst == NULL)
			return (NULL);
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
    	std::cout << root->_pair.first;
		if (root->_parent)
			std::cout << "(" << root->_parent->_pair.first << ")";
		std::cout << std::endl;
 
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
