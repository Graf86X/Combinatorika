#include <iostream>

const int rows = 3, cols = 4;

void Theseus(int lab[3][4], int x, int y, unsigned int path[rows*cols][2], unsigned int size) {

//------------------------------------------------------------------------------------------
    //Дъно на рекусрията
//------------------------------------------------------------------------------------------

    if (x < 0 || x >= rows || y < 0 || y >= cols) return;
    if (lab[x][y] == -1) return;
    if (lab[x][y] == 2) {
        std::cout << "Put:" << std::endl;
        for (unsigned int i = 0; i < size; ++i) 
            std::cout << path[i][0] << ' ' << path[i][1] << std::endl;
        std::cout << std::endl;
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
        Theseus(lab, x + dx[i], y + dy[i], path, size);

//------------------------------------------------------------------------------------------
    //Размаркиране на минатата клетка (Backtracking)
//------------------------------------------------------------------------------------------

    lab[x][y] = 0;

}

void Find_Start(int lab[3][4]) {

    unsigned int path[rows * cols][2];
    unsigned int pathSize = 0;

    for (unsigned int x = 0; x < rows; ++x)
        for (unsigned int y = 0; y < cols; ++y)
            if (lab[x][y] == 1) {
                Theseus(lab, x, y, path, pathSize);
                return;
            }

    std::cout << "Nyama putishta";
    
}

void main() {
    
    int lab[rows][cols] = {
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 2, -1}
    };

	Find_Start(lab);
}