/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 09:06:02 by nayache           #+#    #+#             */
/*   Updated: 2021/12/09 11:54:07 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>
# include <iterator>
# include <stdio.h>

namespace ft {

template < class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T& >
class Iterator
{
	public:
	typedef Category	iterator_category;
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef	Pointer		pointer;
	typedef Reference	reference;
};

}

#endif
