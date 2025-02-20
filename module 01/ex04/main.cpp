#include <iostream>

int main(int argc, char **argv)
{
	if(argc != 4){
		std::cout << "Wrong count arguments" << std::endl;
		return(1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::istream input_file(filename);
	if(!input_file){
		std::cout << "Can't open file" << std::endl;
		return(1);
	}
	// while(!input_file.eof())
	// {

	// }
	return(0);
}
