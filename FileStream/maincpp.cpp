#include<iostream>
#include<fstream>

bool LoadFile(const char* filename)
{
	std::ifstream ist(filename);
	
	if (!ist.good())
	{
		std::cerr << filename << "파일을 찾을 수 없습니다" << std::endl;
		return false;
	}

	char ch;
	while (ist.get(ch))
	{

		if (ist.bad())
		{
			std::cerr << filename << "파일이 손상되었습니다" << std::endl;
			ist.close();
			return false;
		}
		
		if (ist.fail())
		{
			std::cerr << filename << "잘못된 파일 포멧입니다" << std::endl;
			ist.close();
			return false;
		}
		std::cout << ch;
	}

	ist.close();
	return true;
}

bool LoadFile_except(const char* filename)
{
	std::ifstream ist;
	ist.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		ist.open(filename);
		char ch;
		while (ist.get(ch))
		{
			std::cout << ch;
		}
		ist.close();
	}
	catch(std::ifstream::failure e)
	{
		std::cerr << "파일 연산 도중 예외 발생했습니다\n" << e.what() << std::endl;
		ist.close();
		return false;
	}

	return true;
}

int main()
{
	LoadFile("Data/SimpleData.txt");
	std::cout << std::endl;
	LoadFile_except("Data/SimpleData.txt");
}