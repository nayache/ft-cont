/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:51:12 by nayache           #+#    #+#             */
/*   Updated: 2022/02/24 16:10:32 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/containers/stack.hpp"
#include "test.hpp"
#include <stack>
#include <cassert>

int	main(void)
{
	//-----------EMPTY()----------//

	std::cout << YELLOW << "empty() testing.." << RESET << std::endl;
	
	STACK<int> emptyStack;
	STACK<int> noEmptyStack;

	noEmptyStack.push(10);

	assert(emptyStack.empty() == true);
	assert(noEmptyStack.empty() == false);

	noEmptyStack.pop();
	emptyStack.push(3);

	assert(emptyStack.empty() == false);
	assert(noEmptyStack.empty() == true);

	std::cout << GREEN << "empty() success" << RESET << std::endl;
	
	//-----------SIZE()-----------//

	std::cout << YELLOW << "size() testing.." << RESET << std::endl;
	
	STACK<int> stack;

	assert(stack.size() == 0);

	stack.push(1);
	stack.push(1);
	stack.push(1);
	
	assert(stack.size() == 3);
	
	std::cout << GREEN << "size() success" << RESET << std::endl;

	//---------TOP()-------------//

	std::cout << YELLOW << "top() testing.." << RESET << std::endl;
	
	STACK<std::string> stackTop;

	stackTop.push("first push");
	
	assert(stackTop.top() == "first push");

	stackTop.push("second push");
	stackTop.push("third push");
	
	assert(stackTop.top() == "third push");

	stackTop.pop();

	assert(stackTop.top() == "second push");

	std::cout << GREEN << "top() success" << RESET << std::endl;
	
	//------------PUSH()------------//

	std::cout << YELLOW << "push() testing.." << RESET << std::endl;
	
	STACK<int> stck;

	for (int i = 0; i < 10; i++)
	{
		stck.push(i);
		assert(stck.top() == i);
	}
	
	assert(stck.size() == 10);

	stck.push(10);
	stck.push(20);
	stck.push(30);
	stck.push(40);
	stck.push(50);

	assert(stck.size() == 15);
	assert(stck.top() == 50);
	
	std::cout << GREEN << "push() success" << RESET << std::endl;

	//-----------POP()-----------//
	
	std::cout << YELLOW << "pop() testing.." << RESET << std::endl;

	STACK<int> stacky;

	stacky.push(11);
	stacky.push(22);
	stacky.push(33);
	stacky.push(44);
	stacky.push(55);

	stacky.pop();
	assert(stacky.size() == 4);
	assert(stacky.top() == 44);

	while (stacky.empty() == false)
		stacky.pop();

	assert(stacky.size() == 0);
	
	std::cout << GREEN << "pop() success" << RESET << std::endl;

	//-----------RELATIONAL-OPERATORS-------//

	std::cout << YELLOW << "relational operators() testing.." << RESET << std::endl;
	
	STACK<int> test1;
	STACK<int> test2;

	for (int i = 0; i < 5; i++)
	{
		test1.push(i);
		test2.push(i);
	}
	assert(test1 == test2);
	assert(test1 <= test2);
	assert(test1 >= test2);
	assert(!(test1 != test2));
	assert(!(test1 < test2));
	assert(!(test1 > test2));

	test1.pop();

	assert(!(test1 == test2));
	assert(!(test1 >= test2));
	assert(!(test1 > test2));
	assert(test1 < test2);
	assert(test1 <= test2);
	assert(test1 != test2);

	std::cout << GREEN << "relational operators() success.." << RESET << std::endl;
	
	return (0);
}
