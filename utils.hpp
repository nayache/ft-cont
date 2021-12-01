/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:39:20 by nayache           #+#    #+#             */
/*   Updated: 2021/11/19 16:41:58 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft {

template <class Iterator>
int	distance(Iterator first, Iterator last)
{
	int count(0);

	while (first != last)
	{
		first++;
		count++;
	}
	return (count);
}

}
