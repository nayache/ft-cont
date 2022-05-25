/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:20:55 by nayache           #+#    #+#             */
/*   Updated: 2022/05/20 15:26:35 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_MAP_HPP
# define TEST_MAP_HPP

# include <map>
# include "map.hpp"
# include "test.hpp"
# include "lexicographical.hpp"
# include <cassert>
# include <fstream>

void	tst_constructors(std::ofstream& ofs)
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

	printAttributes(first, ofs); // asup

	second = first;
	first = MAP<char, int>();

	printAttributes(second, ofs);
	assert(second.size() == 4);
	assert(first.size() == 0);
}

void	tst_iterators(std::ofstream& ofs)
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

void	tst_capacity(std::ofstream& ofs)
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

void	tst_modifiers(std::ofstream& ofs)
{
//-----------------Insert---------------------

	MAP<int, std::string> mp;

	mp.insert(PAIR<int, std::string>(4, "quatre"));
	mp.insert(PAIR<int, std::string>(5, "cinq"));
	mp.insert(PAIR<int, std::string>(6, "six"));
	mp.insert(PAIR<int, std::string>(7, "sept"));

	printAttributes(mp, ofs);
	
	PAIR<MAP<int, std::string>::iterator, bool>	ret;
	
	ret = mp.insert(PAIR<int, std::string>(4, "newquatre"));
	ofs << std::boolalpha;
	ofs << ret.second << " " << ret.first->first << " " << ret.first->second << std::endl;

	ret = mp.insert(PAIR<int, std::string>(10, "dix"));
	ofs << ret.second << " " << ret.first->first << " " << ret.first->second << std::endl;
	ret = mp.insert(PAIR<int, std::string>(12, "douze"));
	ofs << ret.second << " " << ret.first->first << " " << ret.first->second << std::endl;
	ret = mp.insert(PAIR<int, std::string>(5, "newcinq"));
	ofs << ret.second << " " << ret.first->first << " " << ret.first->second << std::endl;
	ret = mp.insert(PAIR<int, std::string>(1, "un"));
	ofs << ret.second << " " << ret.first->first << " " << ret.first->second << std::endl;
	
	MAP<int, std::string> mp2;
	MAP<int, std::string>::iterator ret2;

	mp2.insert(mp.begin(), mp.end());
	assert(ft::equal(mp2.begin(), mp2.end(), mp.begin(), mp.end()) == true);
	
	ret2 = mp2.insert(mp2.begin(), PAIR<int, std::string>(111, "new"));
	assert(ret2->first == 111);
	
	ret2 = mp2.insert(mp2.begin(), PAIR<int, std::string>(222, "new"));
	assert(ret2->first == 222);
	
	ret2 = mp2.insert(mp2.begin(), PAIR<int, std::string>(111, "newnew"));
	assert(ret2->first == 111 && ret2->second == "new");
	
	ret2 = mp2.insert(mp2.end(), PAIR<int, std::string>(44, "end"));
	assert(ret2->first == 44);
	
	ret2 = mp2.insert(mp2.end(), PAIR<int, std::string>(48, "end"));
	assert(ret2->first == 48);
	
	printAttributes(mp, ofs);
	printAttributes(mp2, ofs);
	
	//------------Time test(insert lot of nodes in ascending order)---------
	
	MAP<int, std::string>	mp3;

	for (int i = 0; i < 900000; i++)
		mp3.insert(PAIR<int, std::string>(i, "--"));

	printSize(mp3, ofs);
	
//-----------------------Erase--------------------------------

	MAP<int, std::string> err;

	err[1] = "uno";
	err[2] = "dos";
	err[3] = "tres";
	err[4] = "cuatro";
	err[5] = "cinco";

	err.erase(err.begin());
	assert(err.size() == 4);
	assert(err.begin()->first != 1);
	
	err.erase(--err.end());
	assert(err.size() == 3);
	assert((--err.end())->first != 1);

	MAP<int, std::string>::size_type ret3;

	ret3 = err.erase(3);
	assert(ret3 == 1 && err.size() == 2);
	
	ret3 = err.erase(3);
	assert(ret3 == 0 && err.size() == 2);
	
	err.clear();
	
	for(int i = 0; i < 25; i++)
		err[i] = ":o";

	while (err.empty() == false)
		err.erase(err.begin());
	
	assert(err.size() == 0);
	assert(err.empty() == true);

	for(int i = 0; i < 500000; i++)
		err[i] = ";)";
	
	err.erase(err.begin(), err.end());

	assert(err.size() == 0);
	assert(err.empty() == true);

//--------------------Swap------------------------

	MAP<int, std::string>	foo, bar;

	foo[2] = "banane";
	foo[4] = "peche";
	foo[6] = "abricot";
	foo[8] = "mangue";

	bar[1] = "fraise";
	bar[3] = "ananas";
	bar[5] = "framboise";

	MAP<int, std::string>::iterator it01 = foo.begin();
	MAP<int, std::string>::iterator it02 = bar.begin();
	
	foo.swap(bar);
	printAttributes(foo, ofs);
	printAttributes(bar, ofs);

	assert(foo.size() == 3);
	assert(bar.size() == 4);
	assert(foo.begin() == it02);
	assert(bar.begin() == it01);

//----------------Clear---------------------

	MAP<int, char>	pam;

	for (int i = 0; i < 10; i++)
		pam[i] = i + 97;
	
	printSize(pam, ofs);
	printAttributes(pam, ofs);

	pam.clear();
	printAttributes(pam, ofs);
	assert(pam.size() == 0 && pam.empty() == true);

	pam[0] = 'p';
	pam[1] = 's';
	pam[2] = 'g';

	pam.clear();
	printAttributes(pam, ofs);
	assert(pam.size() == 0 && pam.empty() == true);

	pam.clear();
	assert(pam.size() == 0 && pam.empty() == true);
}

void	tst_observers(std::ofstream& ofs)
{
//----------------Key comp--------------------

	MAP<int, char> mapi;

	mapi[12] = 'a';
	mapi[30] = 'b';
	mapi[10] = 'c';
	mapi[19] = 'd';
	mapi[50] = 'e';
	mapi[20] = 'f';

	MAP<int, char>::key_compare comp = mapi.key_comp();
	MAP<int, char>::iterator	iter1 = mapi.begin();
	MAP<int, char>::iterator	iter2 = ++mapi.begin();

	ofs << "comp(" << iter2->first << ", " << iter1->first << ")";
	ofs << std::boolalpha << " => " << comp(iter2->first, iter1->first) << std::endl;
	while (iter2 != mapi.end())
	{
		ofs << "comp(" << iter1->first << ", " << iter2->first << ")";
		ofs << std::boolalpha << " => " << comp(iter1->first, iter2->first) << std::endl;
		++iter1;
		++iter2;
	}

//----------------Value comp--------------------

	MAP<char, int> mymap;

	mymap['a'] = 150;
	mymap['b'] = 250;
	mymap['c'] = 50;
	mymap['d'] = 850;
	mymap['e'] = 750;
	mymap['f'] = 350;

	MAP<char, int>::iterator	ite1 = mymap.begin();
	MAP<char, int>::iterator	ite2 = ++mymap.begin();

	ofs << "comp(" << ite2->first << ", " << ite1->first << ")";
	ofs << std::boolalpha << " => " << mymap.value_comp()(*ite2, *ite1) << std::endl;
	while (ite2 != mymap.end())
	{
		ofs << "comp(" << ite1->first << ", " << ite2->first << ")";
		ofs << std::boolalpha << " => " << mymap.value_comp()(*ite1, *ite2) << std::endl;
		++ite1;
		++ite2;
	}
}

void	tst_operations(std::ofstream& ofs)
{
//-----------------Find---------------------

	MAP<int, std::string> mamap;

	mamap[0] = "00";
	mamap[1] = "01";
	mamap[2] = "02";
	mamap[3] = "03";

	MAP<int, std::string>::iterator it;
	MAP<int, std::string>::const_iterator cit;

	it = mamap.find(4);
	if (it != mamap.end())
		mamap.erase(4);

	it = mamap.find(10);
	if (it != mamap.end())
		mamap.erase(10);
	
	it = mamap.find(1);
	if (it != mamap.end())
		mamap.erase(1);
	
	it = mamap.find(2);
	if (it != mamap.end())
		mamap.erase(2);

	assert(mamap.size() == 2 && mamap.empty() == false);
	printAttributes(mamap, ofs);

	cit = mamap.find(1010101001);
	if (cit != mamap.end())
		mamap.erase(1010101001);
	
	cit = mamap.find(3);
	if (cit != mamap.end())
		mamap.erase(3);
	
	cit = mamap.find(0);
	if (cit != mamap.end())
		mamap.erase(0);

	assert(mamap.size() == 0 && mamap.empty() == true);

//------------------Count------------------

	MAP<char, int> map;

	map['a'] = 100;
	map['d'] = 200;
	map['f'] = 300;
	map['g'] = 400;

	printAttributes(map, ofs);

	for (char c = 'a'; c < 'i'; c++)
	{
		ofs << c;
		if (map.count(c) == 1)
			ofs << " is a element of map";
		else
			ofs << " is not a element of map";
		ofs << std::endl;
	}

//----------------Lower bound---------------

	MAP<int, std::string> lmap;

	lmap[0] = "orange";
	lmap[2] = "yellow";
	lmap[4] = "red";
	lmap[6] = "blue";
	lmap[8] = "green";
	lmap[10] = "white";

	MAP<int, std::string>::iterator lit;
	MAP<int, std::string>::iterator litc;

	for (int i = 0; i < 10; i++)
	{
		lit = lmap.lower_bound(i);
		ofs << lit->first << " " << lit->second << std::endl;
	}

	litc = lmap.lower_bound(9);
	lmap.erase(litc);
	
	assert(lmap.size() == 5);
	printAttributes(lmap, ofs);

//----------------Upper bound---------------


	MAP<int, std::string> umap;

	umap[1] = "grey";
	umap[3] = "pink";
	umap[5] = "purple";
	umap[7] = "back";
	umap[9] = "brown";
	umap[11] = "magenta";

	MAP<int, std::string>::iterator uit;
	MAP<int, std::string>::iterator cuit;

	for (int i = 1; i < 11; i++)
	{
		uit = umap.upper_bound(i);
		ofs << uit->first << " " << uit->second << std::endl;
	}

	cuit = umap.upper_bound(9);
	umap.erase(cuit);
	
	assert(umap.size() == 5);
	printAttributes(umap, ofs);

//---------------Equal range----------------

	MAP<char, double> mp;

	mp['a'] = 12.1;
	mp['b'] = 18.8;
	mp['c'] = 21.4;
	mp['d'] = 99.9;
	mp['e'] = 33.2;
	mp['f'] = 20.0;

	PAIR<MAP<char, double>::iterator, MAP<char, double>::iterator> ret;
	PAIR<MAP<char, double>::const_iterator, MAP<char, double>::const_iterator> cret;

	ret = mp.equal_range('a');
	ofs << "lower_bounds points to: ";
	ofs << ret.first->first << " " << ret.first->second << std::endl;
	ofs << "upper_bounds points to: ";
	ofs << ret.second->first << " " << ret.second->second << std::endl;
	
	cret = mp.equal_range('c');
	ofs << "lower_bounds points to: ";
	ofs << cret.first->first << " " << cret.first->second << std::endl;
	ofs << "upper_bounds points to: ";
	ofs << cret.second->first << " " << cret.second->second << std::endl;
	
	ret = mp.equal_range('e');
	ofs << "lower_bounds points to: ";
	ofs << ret.first->first << " " << ret.first->second << std::endl;
	ofs << "upper_bounds points to: ";
	ofs << ret.second->first << " " << ret.second->second << std::endl;

}

int	test_map(std::ofstream& file)
{
	file << "\e[44m\e[1;97m" << "==============MAP TEST=================" << RESET << std::endl;
	tst_constructors(file);
	tst_iterators(file);
	tst_capacity(file);
	tst_modifiers(file);
	tst_observers(file);	
	tst_operations(file);
	file << "\e[44m\e[1;97m" << "=============END MAP TEST==============" << RESET << std::endl;
	
	return (0);
}

#endif
