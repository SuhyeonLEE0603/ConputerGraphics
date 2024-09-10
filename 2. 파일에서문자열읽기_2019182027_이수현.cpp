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
	//std::cout << "파일의 이름을 입력하시오" << std::endl;
	//std::cin >> s;

	std::ifstream in{ s };

	if (!in)
	{
		std::cout << "파일명이 잘못됐습니다" << std::endl;
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

		std::cout << "명령어를 입력하시오" << std::endl;
		std::cin >> c;

		std::string new_string{};
		std::string change_word{};
		
		std::vector<std::string>::iterator it;
		
		switch (c)
		{

		case 'c':
			// 대문자로 시작되는 단어를 찾아 그 단어를 다른 색으로 출력하고, 몇 개 있는지를 계산하여 출력한다.
			// 다시 누르면 원래대로 출력한다.(완)
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
				std::cout << "찾은 단어의 수 : " << n << std::endl;
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
				std::cout << "찾은 단어의 수 : " << n << std::endl;
				std::system("pause");
			}
			break;

		case 'd':
			// 문장 한 줄 전체를 거꾸로 출력하기.
			// 다시 누르면 원래대로 출력한다.
			// (완)
			++d_count;

			std::cout << "몇 번째 줄을 출력하겠습니까?" << std::endl;
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
			// 3문자 후 2 개의 @ 문자 삽입하기.
			// 다시 누르면 원래대로 출력한다

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
			// 공백을 기준으로 모든 단어들을 거꾸로 출력하기.
			// 다시 누르면 원래대로 출력한다.
			// (완)

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
			// 문자 내부의 특정 문자를 다른 문자로 바꾸기 (바꿀 문자와 새롭게 입력할 문자 입력 받음)
			// 다시 누르면 원래대로 출력한다
			
			++g_count;

			if (g_count % 2 == 1)
			{
				std::cout << "바꿀 단어를 입력하시오" << std::endl;
				std::cin >> change_word;

				std::cout << "새롭게 입력할 문자를 입력하시오" << std::endl;
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
			// 각 줄의 단어의 개수를 출력한다.
			break;
		case 'r':
			// 한 문장의 단어의 개수에 따라 오름차순으로 정렬하여 문장들을 출력한다.
			// 다시 누르면 내림차순으로 출력한다.
			// 다시 누르면 원래대로 출력한다. 즉, 오름차순 → 내림차순 → 원래대로 → 오름차순
			break;
		case 's':
			// 명령어와 단어를 입력하면 입력받은 문장들을 모두 출력하면서 그 단어를 찾아 다른 색으로 출력하고, 몇 개 있는지를 계산하여 출력한다.
			// 대소문자 구분하지 않는다
			break;
		case 'q':
			return 0;

		}
	}
}