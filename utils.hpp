/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:39:20 by nayache           #+#    #+#             */
/*   Updated: 2021/12/28 14:10:27 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP
# include "iterator_traits.hpp"

namespace ft {

template <class Iterator>
int	distance(Iterator first, Iterator last)
{
	int count = 0;
	while (first != last)
	{
		first++;
		count++;
	}
	return (count);
}

}
namespace ft {

class NullPtr
{
	public:
		template <class T>
		operator T*() const { return (0); }
		template <class C, class T>
		operator T* C::*() const { return (0); }
	private:
		void operator&() const;
} NullPtr = {};
}

#endif
