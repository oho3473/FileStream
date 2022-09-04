#include<iostream>
#include<fstream>

bool LoadFile(const char* filename)
{
	std::ifstream ist(filename);
	
	if (!ist.good())
	{
		std::cerr << filename << "������ ã�� �� �����ϴ�" << std::endl;
		return false;
	}

	char ch;
	while (ist.get(ch))
	{

		if (ist.bad())
		{
			std::cerr << filename << "������ �ջ�Ǿ����ϴ�" << std::endl;
			ist.close();
			return false;
		}
		
		if (ist.fail())
		{
			std::cerr << filename << "�߸��� ���� �����Դϴ�" << std::endl;
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
		std::cerr << "���� ���� ���� ���� �߻��߽��ϴ�\n" << e.what() << std::endl;
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