/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:48:22 by nayache           #+#    #+#             */
/*   Updated: 2022/04/14 15:37:18 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LEXICOGRAPHICAL_HPP
# define LEXICOGRAPHICAL_HPP

namespace ft {

template <class InputIterator1, class InputIterator2>
bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
{
	while (first1 != last1)
	{
		if (*first1 != *first2)
			return false;
		first1++;
		first2++;
	}
	return (first2 == last2);
}

template <class InputIterator1, class InputIterator2>
bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
InputIterator2 first2, InputIterator2 last2)
{
	while (first1 != last1)
	{
		if (first2 == last2 || *first2 < *first1)
			return false;
		else if (*first1 < *first2)
			return true;
		++first2;
		++first1;
	}
	return (first2 != last2);
}

}
#endif
