/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:55:46 by nayache           #+#    #+#             */
/*   Updated: 2022/03/18 18:43:01 by nayache          ###   ########.fr       */
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
			this->_end->_left = newNode;

		newNode->_height = 0;
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

            if (height(root->_left) - height(root->_right) == 2)
            {
                if (pair.first < root->_left->_pair.first)
                    root = singleRightRotate(root);
                else
                    root = doubleRightRotate(root);
            }
        }
        else if (pair.first > root->_pair.first)
        {
			parent = root;
            root->_right = insertNode(root->_right, parent, ret, pair);

            if (height(root->_right) - height(root->_left) == 2)
            {
                if (pair.first > root->_right->_pair.first)
                    root = singleLeftRotate(root);
                else
                    root = doubleLeftRotate(root);
            }
		}

		root->_height = std::max(height(root->_left), height(root->_right)) + 1;
		return (root);
	}
    
	node_pointer	singleRightRotate(node_pointer &root)
    {
        node_pointer tmp = root->_left;
        root->_left = tmp->_right;
        tmp->_right = root;
        root->_height = std::max(height(root->_left), height(root->_right)) + 1;
        tmp->_height = std::max(height(tmp->_left), root->_height) + 1;
        return (tmp);
    }

    node_pointer singleLeftRotate(node_pointer &root)
    {
        node_pointer tmp = root->_right;
        root->_right = tmp->_left;
        tmp->_left = root;
        root->_height = std::max(height(root->_left), height(root->_right)) + 1;
        tmp->_height = std::max(height(root->_right), root->_height) + 1 ;
        return (tmp);
    }

    node_pointer doubleLeftRotate(node_pointer &root)
    {
        root->_right = singleRightRotate(root->_right);
        return (singleLeftRotate(root));
    }

    node_pointer doubleRightRotate(node_pointer &root)
    {
        root->_left = singleLeftRotate(root->_left);
        return (singleRightRotate(root));
    }

	node_pointer findMin(node_pointer root)
    {
        if (root == NULL)
            return NULL;
        else if (root->_left == NULL)
            return (root);
        else
            return (findMin(root->_left));
    }

    node_pointer findMax(node_pointer root)
    {
        if (root == NULL)
            return NULL;
        else if (root->_right == NULL)
            return (root);
        else
            return (findMax(root->_right));
    }

    node_pointer remove(key_type key, node_pointer root)
    {
        if (root == NULL)
            return NULL;

        if (key < root->_pair.first)
            root->_left = remove(key, root->_left);
        else if (key > root->_pair.first)
            root->_right = remove(key, root->_right);

        else
		{
			if (root->_right && root->_left)
			{
            	node_pointer tmp = findMin(root->_right);
            	root->_pair.first = tmp->_pair.first;
            	root->_right = remove(root->_pair.first, root->_right);
			}
			else
			{
            	node_pointer tmp = root->_left ? root->_left : root->_right;
            	if (tmp == NULL)
				{
					tmp = root;
					root = NULL;
				}
				else
					root->copy(*tmp);
				this->_alloc.destroy(tmp);
            	this->_alloc.deallocate(tmp, 1);
			}
        }
        if (root == NULL)
            return root;

        root->_height = std::max(height(root->_left), height(root->_right)) + 1;
		int	balance = getBalance(root);
		
		if (balance > 1 && getBalance(root->_left) >= 0)
        	return singleRightRotate(root);
    	
		if (balance < -1 &&  getBalance(root->_right) <= 0)
        	return singleLeftRotate(root);
    	
		if (balance > 1 &&  getBalance(root->_left) < 0)
		{
        	root->_left = singleLeftRotate(root->_left);
        	return singleRightRotate(root);
		}

		
		if (balance < -1 && getBalance(root->_right) > 0)
		{
        	root->_right = singleRightRotate(root->_right);
        	return singleLeftRotate(root);
    	}
        return (root);
    }

	int getBalance(node_pointer root)  
	{  
   		if (root == NULL)
        	return (0);
		return (height(root->_left) - height(root->_right));
	}

    int height(node_pointer root)
    {
        return (root == NULL ? -1 : root->_height);
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
