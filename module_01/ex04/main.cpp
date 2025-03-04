#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	if(argc != 4){
		std::cout << "Wrong count arguments" << std::endl;
		return(1);
	}
	const std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream input_file(filename);
	if(!input_file){
		std::cout << "Can't open file" << std::endl;
		return(1);
	}
	std::string line;
	std::ofstream out_file(std::string(filename + ".replace"));
	size_t len;
	while(!input_file.eof())
	{
		std::getline(input_file, line);
		len = line.find(s1);
		while (len != std::string::npos) {
			line.erase(len, s1.length());
        	line.insert(len, s2);
        	len = line.find(s1, len + s2.length());
		}
		out_file << line;
		out_file << "\n";
	}
	return(0);
}
