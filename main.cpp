#include <iostream>
#include "DList.h"

int main()
{
	util::List<int> li;
	for (int i = 0; i < 3; i++)
	{
		li.PushBack(i + 1);
	}

	for (util::List<int>::Iterator it = li.Begin(); it != li.End(); ++it)
	{
		std::cout << *it << std::endl;
	}
}