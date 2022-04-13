#!/bin/bash

REV=$(tput rev)
NC=$(tput sgr0)

echo "\033[35m-----Start testing for vector-----\033[38m\n${NC}"

echo "         ${REV}std::vector${NC}"
echo ""
clang++ -Wall -Wextra -Werror test_vector.cpp -std=c++98 -D VECTOR=std::vector
./a.out
echo "         ${REV}std::vector finish${NC}";
echo ""
cp log log1
clang++ -Wall -Wextra -Werror test_vector.cpp -std=c++98 -D VECTOR=ft::vector
echo "         ${REV}ft::vector${NC}";
echo ""
./a.out
echo "         ${REV}ft::vector finish${NC}";
echo "diff .log .log1"
diff log log1
echo "\033[35m-----End testing for vector-----\033[38m\n\n${NC}"

echo "\033[35m-----Start testing for stack-----\033[38m\n${NC}"
echo "         ${REV}std::stack${NC}"
echo ""
clang++ -Wall -Wextra -Werror test_stack.cpp -std=c++98 -D STACK=std::stack
./a.out
echo "         ${REV}std::stack finish${NC}";
echo ""
clang++ -Wall -Wextra -Werror test_stack.cpp -std=c++98 -D STACK=ft::stack
echo "         ${REV}ft::stack${NC}";
echo ""
./a.out
echo "         ${REV}ft::stack finish${NC}";
echo ""
echo "\033[35m-----End testing for stack-----\033[38m\n${NC}"
