#include <iostream>

const int rows = 3, cols = 4;

void Theseus(int lab[rows][cols], int x, int y, unsigned int size, unsigned int& min_size, unsigned int path[rows*cols][2], unsigned int min_path[rows*cols][2]) {

//------------------------------------------------------------------------------------------
    //Дъно на рекусрията
//------------------------------------------------------------------------------------------

    if (x < 0 || x >= rows || y < 0 || y >= cols) return;
    if (lab[x][y] == -1) return;
    if (size > min_size) return;
    if (lab[x][y] == 2) {
        if (size < min_size) {
            min_size = size;
            for (unsigned int i = 0; i < size; ++i) {
                min_path[i][0] = path[i][0];
                min_path[i][1] = path[i][1];
            }
        }
        return;

    }

//------------------------------------------------------------------------------------------
    //Маркиране като посетено и записване на пътят
//------------------------------------------------------------------------------------------

    lab[x][y] = -1;
    path[size][0] = x;
    path[size][1] = y;
    size++;

//------------------------------------------------------------------------------------------
    //Проверка във всички посоки
//------------------------------------------------------------------------------------------

    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };

    for (unsigned int i = 0; i < 4; ++i)
        Theseus(lab, x + dx[i], y + dy[i], size, min_size, path, min_path);

//------------------------------------------------------------------------------------------
    //Размаркиране на минатата клетка (Backtracking)
//------------------------------------------------------------------------------------------

    lab[x][y] = 0;
}

void Find_Start(int lab[rows][cols]) {

    unsigned int min_size = rows*cols, path[rows * cols][2], min_path[rows * cols][2];

    for (int x = 0; x < rows; ++x)
        for (int y = 0; y < cols; ++y)
            if (lab[x][y] == 1) {
                Theseus(lab, x, y, 0, min_size, path, min_path);
                break;
            }

    if (min_path == 0) std::cout << "Nyama put!";
    else {
        std::cout << "Put s minimalna duljina " << min_size << ':' << std::endl;
        for (unsigned int i = 0; i < min_size; ++i)
            std::cout << path[i][0] << ' ' << path[i][1] << std::endl;
    }

}

void main() {

    int lab[rows][cols] = {
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 2, -1}
    };

    Find_Start(lab);
}