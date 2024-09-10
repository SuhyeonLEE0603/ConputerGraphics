#include <iostream>
#include <random>

std::default_random_engine dre;
std::default_random_engine dre2;
std::uniform_int_distribution<int> uid{0, 1};
std::uniform_int_distribution<int> uidxy{0, 3};

const short SIZE = 4;

short matrix1[SIZE][SIZE];
short matrix2[SIZE][SIZE];

void print_matrix(short matrix[SIZE][SIZE]) 
{
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void make_matrix()
{
	// matrix1
	{

		for (int i = 0; i < SIZE; ++i) {
			for (int j = 0; j < 4; ++j) {
				matrix1[i][j] = uid(dre);
			}
		}

		for (int i = 0; i < 2; ++i) {
			matrix1[uidxy(dre)][uidxy(dre2)] = 2;
		}

		std::cout << "첫번째 행렬" << std::endl;
		print_matrix(matrix1);
	} 
	std::cout << std::endl;
	
	// matrix2
	{
		std::cout << "두번째 행렬" << std::endl;

		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				matrix2[i][j] = uid(dre);
			}
		}

		for (int i = 0; i < 2; ++i) {
			matrix2[uidxy(dre)][uidxy(dre2)] = 2;
		}


		print_matrix(matrix2);
	} 
	std::cout << std::endl;

}

int determinant_3x3(int matrix[3][3]) {
	return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
		matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
		matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

int determinant_4x4(short matrix[4][4]) {
	int det = 0;
	for (int i = 0; i < 4; ++i) {
		int submatrix[3][3];
		for (int row = 1; row < 4; ++row) {
			for (int col = 0; col < 4; ++col) {
				if (col < i) {
					submatrix[row - 1][col] = matrix[row][col];
				}
				else if (col > i) {
					submatrix[row - 1][col - 1] = matrix[row][col];
				}
			}
		}

		int cofactor = (i % 2 == 0 ? 1 : -1) * matrix[0][i] * determinant_3x3(submatrix);
		det += cofactor;
	}
	return det;
}

int main()
{
	make_matrix();

	char c;
	// 결과 행렬
	short result[SIZE][SIZE];
	short e_count = 0;


	// 명령어 입력 받기
	while (true) {
		std::cout << "명령어를 입력하세요" << std::endl;
		std::cin >> c;

		// 행렬 초기화
		for (int i = 0; i < SIZE; ++i) {
			for (int j = 0; j < SIZE; ++j) {
				result[i][j] = 0;
			}
		}


		switch (c)
		{
		case 'm':
			// (완)
			for (int i = 0; i < SIZE; ++i) {
				for (int j = 0; j < SIZE; ++j) {
					for (int k = 0; k < SIZE; ++k) {
						result[i][j] += matrix1[i][k] * matrix2[k][j];
					}
				}
			}
			print_matrix(result);
			break;
		case 'a':
			// (완)
			for (int i = 0; i < SIZE; ++i) {
				for (int j = 0; j < SIZE; ++j) {
					result[i][j] = matrix1[i][j] + matrix2[i][j];
				}
			}
			print_matrix(result);
			break;
		case 'd':
			// (완)
			for (int i = 0; i < SIZE; ++i) {
				for (int j = 0; j < SIZE; ++j) {
					result[i][j] = matrix1[i][j] - matrix2[i][j];
				}
			}
			print_matrix(result);
			break;
		case 'r':
			// (미완)
			std::cout << "첫번째 행렬의 행렬식 = ";
			std::cout << determinant_4x4(matrix1) << std::endl;
			
			std::cout << "두번째 행렬의 행렬식 = ";
			std::cout << determinant_4x4(matrix1) << std::endl;

			break;
		case 't':
			// (완)
			std::cout << "첫번째 행렬의 전치행렬" << std::endl;
			for (int i = 0; i < SIZE; ++i) {
				for (int j = 0; j < SIZE; ++j) {
					result[i][j] = matrix1[j][i];
				}
			}
			print_matrix(result);

			std::cout << "두번째 행렬의 전치행렬" << std::endl;
			for (int i = 0; i < SIZE; ++i) {
				for (int j = 0; j < SIZE; ++j) {
					result[i][j] = matrix2[j][i];
				}
			}

			print_matrix(result);
			break;
		case 'e':
			// (완)
			++e_count;

			if (e_count % 2 == 0)
			{
				std::cout << "첫번째 행렬" << std::endl;
				for (int i = 0; i < SIZE; ++i) {
					for (int j = 0; j < SIZE; ++j) {
						if (matrix1[i][j] % 2 == 1) std::cout << matrix1[i][j] << " ";
						else std::cout << "X ";
					}
					std::cout << std::endl;
				}

				std::cout << "두번째 행렬" << std::endl;
				for (int i = 0; i < SIZE; ++i) {
					for (int j = 0; j < SIZE; ++j) {
						if (matrix2[i][j] % 2 == 1) std::cout << matrix2[i][j] << " ";
						else std::cout << "X ";
					}
					std::cout << std::endl;
				}
				break;
			}
			else
			{

				std::cout << "첫번째 행렬" << std::endl;
				for (int i = 0; i < SIZE; ++i) {
					for (int j = 0; j < SIZE; ++j) {
						if (matrix1[i][j] % 2 == 0) std::cout << matrix1[i][j] << " ";
						else std::cout << "X ";
					}
					std::cout << std::endl;
				}

				std::cout << "두번째 행렬" << std::endl;
				for (int i = 0; i < SIZE; ++i) {
					for (int j = 0; j < SIZE; ++j) {
						if (matrix2[i][j] % 2 == 0) std::cout << matrix2[i][j] << " ";
						else std::cout << "X ";
					}
					std::cout << std::endl;
				}

				break;
			}

		case 's':
			// (완)
			make_matrix();
			break;
		case 'q':
			// (완)
			std::cout << "프로그램 종료" << std::endl;
			return 0;
		case '1':
			std::cout << "첫번째 행렬" << std::endl;
			for (int i = 0; i < SIZE; ++i) {
				for (int j = 0; j < SIZE; ++j) {
					result[i][j] = matrix1[i][j] * 1;
				}
			}
			print_matrix(result);

			std::cout << "두번째 행렬" << std::endl;
			for (int i = 0; i < SIZE; ++i) {
				for (int j = 0; j < SIZE; ++j) {
					result[i][j] = matrix2[i][j] * 1;
				}
			}
			print_matrix(result);
			break;

		case '2':
			std::cout << "첫번째 행렬" << std::endl;
			for (int i = 0; i < SIZE; ++i) {
				for (int j = 0; j < SIZE; ++j) {
					result[i][j] = matrix1[i][j] * 2;
				}
			}
			print_matrix(result);

			std::cout << "두번째 행렬" << std::endl;
			for (int i = 0; i < SIZE; ++i) {
				for (int j = 0; j < SIZE; ++j) {
					result[i][j] = matrix2[i][j] * 2;
				}
			}
			print_matrix(result);
			break;
		case '3':
			std::cout << "첫번째 행렬" << std::endl;
			for (int i = 0; i < SIZE; ++i) {
				for (int j = 0; j < SIZE; ++j) {
					result[i][j] = matrix1[i][j] * 3;
				}
			}
			print_matrix(result);

			std::cout << "두번째 행렬" << std::endl;
			for (int i = 0; i < SIZE; ++i) {
				for (int j = 0; j < SIZE; ++j) {
					result[i][j] = matrix2[i][j] * 3;
				}
			}
			print_matrix(result);
			break;
		case '4':
			std::cout << "첫번째 행렬" << std::endl;
			for (int i = 0; i < SIZE; ++i) {
				for (int j = 0; j < SIZE; ++j) {
					result[i][j] = matrix1[i][j] * 4;
				}
			}
			print_matrix(result);

			std::cout << "두번째 행렬" << std::endl;
			for (int i = 0; i < SIZE; ++i) {
				for (int j = 0; j < SIZE; ++j) {
					result[i][j] = matrix2[i][j] * 4;
				}
			}
			print_matrix(result);
			break;
		case '5':
			std::cout << "첫번째 행렬" << std::endl;
			for (int i = 0; i < SIZE; ++i) {
				for (int j = 0; j < SIZE; ++j) {
					result[i][j] = matrix1[i][j] * 5;
				}
			}
			print_matrix(result);

			std::cout << "두번째 행렬" << std::endl;
			for (int i = 0; i < SIZE; ++i) {
				for (int j = 0; j < SIZE; ++j) {
					result[i][j] = matrix2[i][j] * 5;
				}
			}
			print_matrix(result);
			break;
		case '6':
			std::cout << "첫번째 행렬" << std::endl;
			for (int i = 0; i < SIZE; ++i) {
				for (int j = 0; j < SIZE; ++j) {
					result[i][j] = matrix1[i][j] * 6;
				}
			}
			print_matrix(result);

			std::cout << "두번째 행렬" << std::endl;
			for (int i = 0; i < SIZE; ++i) {
				for (int j = 0; j < SIZE; ++j) {
					result[i][j] = matrix2[i][j] * 6;
				}
			}
			print_matrix(result);
			break;
		case '7':
			std::cout << "첫번째 행렬" << std::endl;
			for (int i = 0; i < SIZE; ++i) {
				for (int j = 0; j < SIZE; ++j) {
					result[i][j] = matrix1[i][j] * 7;
				}
			}
			print_matrix(result);

			std::cout << "두번째 행렬" << std::endl;
			for (int i = 0; i < SIZE; ++i) {
				for (int j = 0; j < SIZE; ++j) {
					result[i][j] = matrix2[i][j] * 7;
				}
			}
			print_matrix(result);
			break;
		case '8':
			std::cout << "첫번째 행렬" << std::endl;
			for (int i = 0; i < SIZE; ++i) {
				for (int j = 0; j < SIZE; ++j) {
					result[i][j] = matrix1[i][j] * 8;
				}
			}
			print_matrix(result);

			std::cout << "두번째 행렬" << std::endl;
			for (int i = 0; i < SIZE; ++i) {
				for (int j = 0; j < SIZE; ++j) {
					result[i][j] = matrix2[i][j] * 8;
				}
			}
			print_matrix(result);
			break;

		case '9':
			std::cout << "첫번째 행렬" << std::endl;
			for (int i = 0; i < SIZE; ++i) {
				for (int j = 0; j < SIZE; ++j) {
					result[i][j] = matrix1[i][j] * 9;
				}
			}
			print_matrix(result);

			std::cout << "두번째 행렬" << std::endl;
			for (int i = 0; i < SIZE; ++i) {
				for (int j = 0; j < SIZE; ++j) {
					result[i][j] = matrix2[i][j] * 9;
				}
			}
			print_matrix(result);
			break;
		}
	}

}