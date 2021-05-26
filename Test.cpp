#include "BinaryTree.hpp"
#include "doctest.h"
#include <iostream>
#include <string>

using namespace ariel;

TEST_CASE("build a tree") {
    BinaryTree<int> bt;
    CHECK_NOTHROW(bt.add_root(1));
    CHECK_NOTHROW(bt.add_left(1, 2));
    CHECK_NOTHROW(bt.add_right(1, 3));
    CHECK_NOTHROW(bt.add_left(2, 4));
    CHECK_NOTHROW(bt.add_left(3, 6));
    CHECK_NOTHROW(bt.add_right(2, 5));
    CHECK_NOTHROW(bt.add_left(4, 8));
    CHECK_NOTHROW(bt.add_right(3, 7));
    CHECK_NOTHROW(bt.add_right(6, 9));
    CHECK_NOTHROW(bt.add_right(7, 10));



}

TEST_CASE("string tree") {
    BinaryTree<char> bt;
    CHECK_NOTHROW(bt.add_root('a'));
    CHECK_NOTHROW(bt.add_left('a', 'b'));
    CHECK_NOTHROW(bt.add_right('a', 'c'));
    CHECK_NOTHROW(bt.add_left('b', 'd'));
    CHECK_NOTHROW(bt.add_right('b', 'e'));
    CHECK_NOTHROW(bt.add_left('c', 'f'));
    CHECK_NOTHROW(bt.add_right('c', 'g'));
    CHECK_NOTHROW(bt.add_left('d', 'h'));
    CHECK_NOTHROW(bt.add_right('d', 'i'));
    CHECK_NOTHROW(bt.add_left('e', 'j'));
    CHECK_NOTHROW(bt.add_right('e', 'k'));

}
