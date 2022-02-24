#include "stack.hpp"
#include "includes/vector.hpp"
#include <stack>
#include <vector>

int	main()
{
	ft::stack<int> test;	
	ft::stack<int> test2;	

	test.push(42);
	test.push(93);
	test.push(10);
	test2.push(42);
	test2.push(93);
	test2.push(11);
	std::cout << test.size() << " " << test.empty() << std::endl;
	if (test <= test2)
		std::cout << "equal" << std::endl;
	while (!test.empty())
	{
		std::cout << test.top() << std::endl;
		test.pop();
	}
	std::cout << test.size() << " " << test.empty() << std::endl;

/*	ft::vector<int> tst;

	tst.push_back(42);
	tst.pop_back();
	try {
		std::cout << tst.at(0);
	}
	catch(std::exception& e)
	{

	}*/
	return (0);
}
