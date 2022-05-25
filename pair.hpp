/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:31:27 by nayache           #+#    #+#             */
/*   Updated: 2022/05/20 18:48:33 by nayache          ###   ########.fr       */
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
	
	pair() : first(first_type()), second(second_type()) {}

	template <class U, class V>
	pair(const pair<U,V>& pr) : first(pr.first), second(pr.second) {}
	
	pair(const pair& pr) : first(pr.first), second(pr.second) {}

	pair(const first_type& a, const second_type& b) : first(a), second(b) {}

	pair&	operator=(const pair& pr)
	{
		if (this == &pr)
			return (*this);

		this->first = pr.first;
		this->second = pr.second;
		return (*this);
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
{ return lhs.first == rhs.first && lhs.second == rhs.second; }

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


template <class T1, class T2>
pair<T1, T2> make_pair(T1 x, T2 y)
{
	return (pair<T1, T2>(x, y));
}

}

#endif
