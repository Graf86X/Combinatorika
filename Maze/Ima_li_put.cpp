#include <iostreaM>

char** lab_fill(char** lab, unsigned int rows, unsigned int cols) {
	for (unsigned int i = 0; i < rows; i++)
		for (unsigned int j = 0; j < cols; j++) std::cin >> lab[i][j];

	return lab;
}

bool Theseus(char** lab, int x, int y, const unsigned int& rows, const unsigned int& cols) {

//------------------------------------------------------------------------------------------
	//Дъно на рекусрията
//------------------------------------------------------------------------------------------

	if (x >= rows || x < 0 || y >= cols || y < 0) return false;
	if (lab[x][y] == '-') return false;
	if (x == rows - 1 && y == cols - 1) return true;

//------------------------------------------------------------------------------------------
	//Маркиране на пътят като минат
//------------------------------------------------------------------------------------------

	lab[x][y] = '-';

//------------------------------------------------------------------------------------------
	//Проверка за всяка посока
//------------------------------------------------------------------------------------------

	if (Theseus(lab, x+1, y, rows, cols)) return true;
	if (Theseus(lab, x, y+1, rows, cols)) return true;
	if (Theseus(lab, x - 1, y, rows, cols)) return true;
	if (Theseus(lab, x, y-1, rows, cols)) return true;

//-------------------------------------------------------------------------------------------
}

void main() {
	unsigned int n, m;
	std::cin >> n >> m;
	char** lab = new char* [n];
	for (size_t i = 0; i < n; ++i) lab[i] = new char[m];

	 lab = lab_fill(lab, n, m);

	 std::cout << Theseus(lab, 0, 0, n, m);


	for (size_t i = 0; i < n; ++i) delete[] lab[i];
	delete[] lab;
}