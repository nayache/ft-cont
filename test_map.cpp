/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:20:55 by nayache           #+#    #+#             */
/*   Updated: 2022/04/26 16:05:16 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_MAP_HPP
# define TEST_MAP_HPP

# include <map>
# include "includes/containers/map.hpp"
# include <cassert>
# include <fstream>

class Object
{
	public:
	int		a;
	char	b;
	double	c;
	void*	d;
};

template <typename Iterator>
void	printPair(Iterator& x, std::ofstream &ofs)
{
	ofs << "(" << x->first << ") (" << x->second << ")" << std::endl;
}

template <class M>
void	printSize(M& src, std::ofstream& ofs)
{
	ofs << "size: " << src.size() << std::endl;
	ofs << "max_size: " << src.max_size() << std::endl;
}

template <class M>
void	printAttributes(M& src, std::ofstream& ofs)
{
	ofs << "------------Print--------------" << std::endl;
	printSize(src, ofs);
	ofs << std::boolalpha;
	
	ofs << "empty : " << src.empty() << std::endl;
	ofs << "Content :" << std::endl;
	
	for (typename M::iterator it = src.begin(); it != src.end(); it++)
		ofs << "[" << it->first << "] [" << it->second << "]" << std::endl;
	
	ofs << "-------------------------------" << std::endl;
}

void	test_constructors(std::ofstream& ofs)
{
//----------Default--------------
	
	MAP<int, std::string> mp;
	
	printAttributes(mp, ofs);
	assert(mp.size() == 0);

//----------Range--------------

	mp[42] = "fortytwo";
	mp[24] = "twentyfour";

	MAP<int, std::string> mp2(mp.begin(), mp.end());
	printAttributes(mp2, ofs);
	assert(mp2.size() == 2);

	mp[12] = "douze";
	mp[13] = "treize";
	mp[100] = "cent";

	MAP<int, std::string> mp3(++mp.begin(), --mp.end());
	printAttributes(mp3, ofs);
	assert(mp3.size() == 3);
	
	MAP<int, std::string> mp4( ++(++mp.begin()), --(--mp.end()) );
	printAttributes(mp4, ofs);
	
	assert(mp4.size() == 1);
//------------Copy-------------

	MAP<char, double> mapp;

	for (double i = 97.5; i < 107.5; i += 1.0)
	{
		char c = static_cast<char>(i);
		mapp[c] = i - 90;
	}
	
	MAP<char, double> mappCopy(mapp);
	printAttributes(mappCopy, ofs);
	assert(mappCopy.size() == 10);

	//----expect a deep copy---

	mapp['a'] = 13.4;
	printAttributes(mappCopy, ofs);
	assert(mappCopy['a'] != 13.40);

//-------Assign operator--------

	MAP<char, int> first;
	MAP<char, int> second;

	first['w'] = 4;
	first['x'] = 40;
	first['y'] = 400;
	first['z'] = 4000;

	second = first;
	first = MAP<char, int>();

	printAttributes(second, ofs);
	assert(second.size() == 4);
	assert(first.size() == 0);
}

void	test_iterators(std::ofstream& ofs)
{
//-----------------Begin/End----------------------
	
	MAP<int, std::string> test;

	test[2] = "two";
	test[4] = "four";
	test[6] = "six";
	test[8] = "eight";
	test[10] = "ten";
	test[12] = "twelve";
	test[14] = "fourteen";
	
	MAP<int, std::string>::iterator it = test.begin();
	MAP<int, std::string>::iterator ite = test.end();
	
	printPair(it, ofs);	
	it = ++(test.begin());
	printPair(it, ofs);
	it = ++(++(++test.begin()));
	printPair(it, ofs);
	printPair(--it, ofs);
	printPair(--it, ofs);
	printPair(it, ofs);
	printPair(++it, ofs);

	printPair(--ite, ofs);
	ite = (--(--(test.end())));
	printPair(ite, ofs);
	ite = --(--(--(--(--(test.end())))));
	printPair(ite, ofs);
	printPair(++ite, ofs);
	printPair(++ite, ofs);
	printPair(ite, ofs);
	
	MAP<int, std::string> testEmpty;
	MAP<int, std::string>::iterator it0 = testEmpty.begin();
	MAP<int, std::string>::iterator ite0 = testEmpty.end();

	assert(it0 == ite0);

//-----------------Rbegin/Rend-------------------

	MAP<int, float> rmap;

	rmap[10] = 1.40f;
	rmap[20] = 2.40f;
	rmap[30] = 3.40f;
	rmap[40] = 4.40f;
	rmap[50] = 5.40f;
	rmap[60] = 6.40f;

	MAP<int, float>::reverse_iterator rit = rmap.rbegin();
	MAP<int, float>::reverse_iterator rite = rmap.rend();
	
	printPair(rit, ofs);	
	rit = ++(rmap.rbegin());
	printPair(rit, ofs);
	rit = ++(++(++rmap.rbegin()));
	printPair(rit, ofs);
	printPair(--rit, ofs);
	printPair(rit, ofs);
	printPair(++rit, ofs);

	printPair(--rite, ofs);
	rite = (--(--(rmap.rend())));
	printPair(rite, ofs);
	rite = --(--(--(--(--(rmap.rend())))));
	printPair(rite, ofs);
	printPair(++rite, ofs);
	printPair(++rite, ofs);
	printPair(++rite, ofs);
	printPair(--rite, ofs);
	
}

void	test_capacity(std::ofstream& ofs)
{
//-------------------Empty-------------------
	
	MAP<double, char> emp;
	
	assert(emp.empty() == true);

	emp[77.7] = 'z';
	assert(emp.empty() == false);

	emp.erase(77.7);
	assert(emp.empty() == true);

	emp[11.1] = 's';
	emp[22.2] = 'c';
	emp.clear();
	assert(emp.empty() == true);

	emp[11.1] = 's';
	emp[22.2] = 'c';
	emp[44.4] = 'd';
	emp[33.3] = 'x';
	emp[99.9] = 'a';

	while (emp.empty() == false)
	{
		MAP<double, char>::iterator itt = emp.begin();
		printPair(itt, ofs);
		emp.erase(itt);
	}
	assert(emp.empty() == true);	

//-----------------Size------------------

	MAP<short, char> smap;

	assert(smap.size() == 0);

	smap[1] = 'a';
	smap[7] = 'f';
	smap[3] = 'b';
	smap[2] = 'c';
	smap[5] = 'k';
	assert(smap.size() == 5);

	smap.erase(7);
	assert(smap.size() == 4);
	
	smap.erase(2);
	assert(smap.size() == 3);
	
	smap.erase(1);
	smap.erase(3);
	assert(smap.size() == 1);

//---------------Max size-----------------

	MAP<int, std::string> 	map1;
	MAP<char, std::string> 	map2;
	MAP<int, double>		map3;
	MAP<double, int>		map4;
	MAP<float, std::string> map5;
	MAP<char, float>		map6;
	MAP<double, char>		map7;
	MAP<double, Object>		map8;
	MAP<Object, char>		map9;
	MAP<int, Object>		map10;

	printSize(map1, ofs);
	printSize(map2, ofs);
	printSize(map3, ofs);
	printSize(map4, ofs);
	printSize(map5, ofs);
	printSize(map6, ofs);
	printSize(map7, ofs);
	printSize(map8, ofs);
	printSize(map9, ofs);
	printSize(map10, ofs);
}

void	test_modifiers(std::ofstream& ofs)
{
//-----------------Insert---------------------
		
	MAP<int, std::string> mp;

	mp.insert(PAIR<int, std::string>(4, "quatre"));
	mp.insert(PAIR<int, std::string>(5, "cinq"));
	mp.insert(PAIR<int, std::string>(6, "six"));
	mp.insert(PAIR<int, std::string>(7, "sept"));

	printAttributes(mp, ofs);
}

int	main(void)
{
	std::ofstream file;
	file.open("log");

	test_constructors(file);
	
	test_iterators(file);
	
	test_capacity(file);

	test_modifiers(file);
	
	return (0);
}

#endif
