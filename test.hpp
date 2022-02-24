/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:28:56 by nayache           #+#    #+#             */
/*   Updated: 2022/02/24 14:40:54 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
#define TEST_HPP

# define RED "\e[1;31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"
# define PURPLE "\e[35m"
# define RESET "\e[0;38m"

# include <vector>
# include "includes/containers/vector.hpp"
# include <iostream>
# include <fstream>


void	test_constructors(std::ofstream& ofs);
void	test_iterators(std::ofstream& ofs);
void	test_capacity(void);
void	test_access(std::ofstream& ofs);
void	test_modifiers(std::ofstream& ofs);

template <typename T>
void	printAttributes(ft::vector<T>& vec, std::ofstream& ofs)
{
	ofs << "size: " << vec.size() << " ";
	ofs << "capacity: " << vec.capacity() << std::endl;
}

template <typename T>
void	printAttributes(std::vector<T>& vec, std::ofstream& ofs)
{
	ofs << "size: " << vec.size() << " ";
	ofs << "capacity: " << vec.capacity() << std::endl;
}

template <typename T>
void	printVector(ft::vector<T>& vec, std::ofstream& ofs)
{
	printAttributes(vec, ofs);

	for (typename VECTOR<T>::size_type i = 0; i < vec.size(); i++)
		ofs << "[" << vec[i] << "]";
	ofs << std::endl;
}

template <typename T>
void	printVector(std::vector<T>& vec, std::ofstream& ofs)
{
	printAttributes(vec, ofs);

	for (typename VECTOR<T>::size_type i = 0; i < vec.size(); i++)
		ofs << "[" << vec[i] << "]";
	ofs << std::endl;
}

#endif
