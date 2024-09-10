#include <iostream>
#include <Windows.h>
#include <fstream>
#include <random>
#include <vector>

std::uniform_int_distribution<int> uidlength{3, 5};
std::uniform_int_distribution<int> uidcolor{0, 15};
std::default_random_engine dre;

std::string make_random_string(int length) 
{
	std::string s;
	std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789~!#$%^&*()_+";
	
	int charactersLength = characters.size();
	
	std::uniform_int_distribution<int> uidchar{ 0, charactersLength };

	for (int i = 0; i < length; ++i) {
		s += characters[uidchar(dre)];
	}

	return s;
}

void print_all(std::vector<std::string> v)
{
	for (auto& s : v)
	{
		std::cout << s << ' ';
	}

	std::cout << std::endl;
}

void make_datafile()
{
	std::ofstream out{ "data.txt" };

	std::vector<std::string> v;

	std::string s;

	for (int i = 0; i < 110; ++i)
	{
		if ((i % 10 == 0) && (i != 0))
		{
			v.emplace_back("\n");
			continue;
		}
		s = make_random_string(uidlength(dre));
		v.emplace_back(s);
	}

	for (int i = 0; i < v.size(); ++i)
	{
		out << v[i] << ' ';
	}
	
}

int main()
{
	make_datafile();

	std::string s{ "data.txt" };
	//std::cout << "������ �̸��� �Է��Ͻÿ�" << std::endl;
	//std::cin >> s;

	std::ifstream in{ s };

	if (!in)
	{
		std::cout << "���ϸ��� �߸��ƽ��ϴ�" << std::endl;
	}

	std::vector<std::string> v;

	while (in >> s)
	{
		v.emplace_back(s);
	}


	char c;

	short c_count = 0;
	short d_count = 0;
	short e_count = 0;
	short f_count = 0;
	short g_count = 0;
	short h_count = 0;
	short r_count = 0;
	short s_count = 0;
	int alpha_count = 0;

	int n;
	int text_color;

	while (true)
	{
		std::system("cls");
		print_all(v);

		std::cout << "��ɾ �Է��Ͻÿ�" << std::endl;
		std::cin >> c;

		std::string new_string{};
		std::string change_word{};
		
		std::vector<std::string>::iterator it;
		
		switch (c)
		{

		case 'c':
			// �빮�ڷ� ���۵Ǵ� �ܾ ã�� �� �ܾ �ٸ� ������ ����ϰ�, �� �� �ִ����� ����Ͽ� ����Ѵ�.
			// �ٽ� ������ ������� ����Ѵ�.(��)
			++c_count;
			n = 0;

			text_color = uidcolor(dre);

			if (c_count % 2 == 1)
			{
				for (std::string& s : v)
				{
					auto first_char = s.begin();
					if (isupper(*first_char))
					{
						++n;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text_color);
						std::cout << s << std::endl;
					}
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				std::cout << "ã�� �ܾ��� �� : " << n << std::endl;
				std::system("pause");
			}
			else
			{
				for (std::string& s : v)
				{
					auto first_char = s.begin();
					if (isupper(*first_char))
					{
						++n;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						std::cout << s << std::endl;
					}
				}
				std::cout << "ã�� �ܾ��� �� : " << n << std::endl;
				std::system("pause");
			}
			break;

		case 'd':
			// ���� �� �� ��ü�� �Ųٷ� ����ϱ�.
			// �ٽ� ������ ������� ����Ѵ�.
			// (��)
			++d_count;

			std::cout << "�� ��° ���� ����ϰڽ��ϱ�?" << std::endl;
			std::cin >> n;

			if (d_count % 2 == 1)
			{
				std::reverse(v.begin() + 10 * (n - 1), v.begin() + 10 * n);

				for (int i = 10 * (n - 1); i < 10 + 10 * (n - 1); ++i)
				{
					std::cout << v[i] << " ";
				}

				std::cout << std::endl;
				std::system("pause");

			}
			else
			{
				std::reverse(v.begin() + 10 * (n - 1), v.begin() + 10 * n);

				for (int i = 10 * (n - 1); i < 10 + 10 * (n - 1); ++i)
				{
					std::cout << v[i] << " ";
				}

				std::cout << std::endl;
				std::system("pause");
			}
			break;
		case 'e':
			// 3���� �� 2 ���� @ ���� �����ϱ�.
			// �ٽ� ������ ������� ����Ѵ�

			++e_count;

			alpha_count = 0;

			if (e_count % 2 == 1)
			{
				for (auto& s : v)
				{
					for (int i = 0; i < s.size(); ++i)
					{
						++alpha_count;
						if (alpha_count % 3 == 0)
						{
							new_string += "@@";
						}
						new_string += s[i];
					}
					s = new_string;

					++alpha_count;
					std::cout << s << " ";
				}

				std::cout << std::endl;
				std::system("pause");

			}
			else
			{
				for (auto& s : v)
				{
					for (int i = 0; i < s.size(); ++i)
					{
						++alpha_count;
						if (alpha_count % 3 == 0)
						{
							s.erase(alpha_count, 2);
						}
					}

					++alpha_count;
					std::cout << s << " ";
				}

				std::cout << std::endl;
				std::system("pause");
			}
			break;
		case 'f':
			// ������ �������� ��� �ܾ���� �Ųٷ� ����ϱ�.
			// �ٽ� ������ ������� ����Ѵ�.
			// (��)

			++f_count;

			if (f_count % 2 == 1)
			{
				for (int i = 0; i < v.size(); ++i)
				{
					s = v[i];
					std::reverse(s.begin(), s.end());
					v[i] = s;
					std::cout << s << " ";
				}
				std::cout << std::endl;
				std::system("pause");
			}
			else
			{
				for (int i = 0; i < v.size(); ++i)
				{
					s = v[i];
					std::reverse(s.begin(), s.end());
					v[i] = s;
					std::cout << s << " ";
				}
				std::cout << std::endl;
				std::system("pause");
			}
			

			break;
		case 'g':
			// ���� ������ Ư�� ���ڸ� �ٸ� ���ڷ� �ٲٱ� (�ٲ� ���ڿ� ���Ӱ� �Է��� ���� �Է� ����)
			// �ٽ� ������ ������� ����Ѵ�
			
			++g_count;

			if (g_count % 2 == 1)
			{
				std::cout << "�ٲ� �ܾ �Է��Ͻÿ�" << std::endl;
				std::cin >> change_word;

				std::cout << "���Ӱ� �Է��� ���ڸ� �Է��Ͻÿ�" << std::endl;
				std::cin >> new_string;

				it = std::find_if(v.begin(), v.end(), [change_word](const std::string s) {
					return s == change_word;
					});

				std::system("pause");
			}
			else
			{

			}


			break;
		case 'h':
			// �� ���� �ܾ��� ������ ����Ѵ�.
			break;
		case 'r':
			// �� ������ �ܾ��� ������ ���� ������������ �����Ͽ� ������� ����Ѵ�.
			// �ٽ� ������ ������������ ����Ѵ�.
			// �ٽ� ������ ������� ����Ѵ�. ��, �������� �� �������� �� ������� �� ��������
			break;
		case 's':
			// ��ɾ�� �ܾ �Է��ϸ� �Է¹��� ������� ��� ����ϸ鼭 �� �ܾ ã�� �ٸ� ������ ����ϰ�, �� �� �ִ����� ����Ͽ� ����Ѵ�.
			// ��ҹ��� �������� �ʴ´�
			break;
		case 'q':
			return 0;

		}
	}
}