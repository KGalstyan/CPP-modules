#include <iostream>

int main(int argc, char **argv)
{
	if(argc <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return(0);
	}
	for(int j = 1; argv[j]; j++)
	{
		for(int i = 0; argv[j][i]; i++)
		{
			if(argv[j][i] >= 'a' && argv[j][i] <= 'z')
				argv[j][i] = toupper(argv[j][i]);
			std::cout << argv[j][i];
		}
	}
	std::cout << std::endl;
	return(0);
}
