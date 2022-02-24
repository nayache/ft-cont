/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:31:27 by nayache           #+#    #+#             */
/*   Updated: 2021/12/22 16:13:58 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {

template <class T1, class T2>
struct pair
{
	typedef T1	first_type;
	typedef T2	second_type;
	
	first_type first;
	second_type second;
	
	pair()
	{
		first = first_type();
		second = second_type();
	}

	template <class U, class V>
	pair(const pair<U,V>& pr)
	{
		first = first_type(pr.first);
		second = second_type(pr.second);
	}

	pair(const first_type& a, const second_type& b)
	{
		first = first_type(a);
		second = second_type(b);
	}

	pair&	operator=(const pair& pr)
	{
		first = first_type(pr.first);
		second = second_type(pr.second);
	}

	void	swap(pair& pr)
	{
		first_type tmp = first;
		second_type tmp2 = second;

		first = pr.first;
		second = pr.second;
		pr.first = tmp;
		pr.second = tmp2;
	}
};

template <class T1, class T2>
  bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return lhs.first==rhs.first && lhs.second==rhs.second; }

template <class T1, class T2>
  bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs==rhs); }

template <class T1, class T2>
  bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

template <class T1, class T2>
  bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(rhs<lhs); }

template <class T1, class T2>
  bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return rhs<lhs; }

template <class T1, class T2>
  bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs<rhs); }
}

#endif
