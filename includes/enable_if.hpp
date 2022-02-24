/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:14:51 by nayache           #+#    #+#             */
/*   Updated: 2021/12/22 13:12:35 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP


namespace ft {

template <bool B, class T = void>
struct	enable_if {};


template <class T>
struct	enable_if<true, T>
{
	typedef T	type;
};


}
#endif
