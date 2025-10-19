#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	switch (n)
	{
	case 1:
		std::cout << "One";
		break;
	case 2:
		std::cout << "Two";
		break;
	default:
		std::cout << "Fail";
		break;
	}
	return 0;
}