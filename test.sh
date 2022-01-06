#!/bin/bash

REV=$(tput rev)
NC=$(tput sgr0)

echo "         ${REV}ft::vector${NC}"
echo ""
clang++ -Wall -Wextra -Werror test_vector.cpp -std=c++98 -D VECTOR=ft::vector
./a.out
echo "         ${REV}ft::vector finish${NC}";
echo ""
sudo cp .log .log1
clang++ -Wall -Wextra -Werror test_vector.cpp -std=c++98 -D VECTOR=std::vector
echo "         ${REV}std::vector${NC}";
echo ""
./a.out
echo "         ${REV}std::vector finish${NC}";
echo "diff .log .log1"
diff .log .log1
