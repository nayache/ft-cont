/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:15:58 by nayache           #+#    #+#             */
/*   Updated: 2021/12/09 11:54:28 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include "iterator.hpp"

namespace ft {

template<class Iter>
class IteratorTraits {
	
	public:
    
	typedef typename Iter::iterator_category	iterator_category;
    typedef typename Iter::value_type			value_type;
    typedef typename Iter::difference_type		difference_type;	
    typedef	typename Iter::pointer				pointer;
    typedef typename Iter::reference			reference;
  };

template<class T> //requires std::is_object_v<T>
class IteratorTraits<T*> {
	
	public:
    
	typedef std::random_access_iterator_tag		iterator_category;
    typedef T									value_type;
    typedef std::ptrdiff_t						difference_type;
    typedef T*									pointer;
    typedef T&									reference;
  };
}

#endif
