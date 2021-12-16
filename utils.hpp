/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:39:20 by nayache           #+#    #+#             */
/*   Updated: 2021/12/16 10:03:59 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterator_traits.hpp"

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
