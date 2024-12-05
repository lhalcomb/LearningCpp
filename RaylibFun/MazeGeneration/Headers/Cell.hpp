#ifndef CELL_HPP
#define CELL_HPP

#include <vector>


using namespace std;
class Cell{
    private: 
        int row, column; //position of the cell
        bool visited;
        std::array<bool, 4> walls; 

    public:
        Cell(int row, int column);


        int getRow();
        int getCol();

        bool isVisited();

        void visit();

        void render(int cellSize);

        void removeWallHelper(int wallSide);
        Cell* checkNeighbors(vector<vector<Cell>>& grid, int row, int col);

        void highlightCell(int cellSize);


        ~Cell();
};

#endif
