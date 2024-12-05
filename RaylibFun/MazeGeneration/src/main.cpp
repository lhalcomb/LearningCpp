#include <iostream>
#include <vector>
#include <raylib.h>
#include <random>
#include "../Headers/Cell.hpp"



//Constant 
#define DIMENSION 400
#define ROWS (20)
#define COLS (20)

//Source file for Maze Generator


using namespace std;

vector<vector<Cell>> createMazeGrid(){
    vector<vector<Cell>> grid;
    for(int j = 0; j < ROWS; j++){
        vector<Cell> rows;
        for(int i = 0; i < COLS; i++){
            rows.push_back(Cell(i, j));
        }
        grid.push_back(rows);
    }

    return grid;
}

void renderMazeGrid(vector<vector<Cell>> &grid, int cellSize){
    for (auto& row: grid){
        for(auto& cell: row){
            cell.render(cellSize);
        }
    }
}

void removeWall(Cell& current, Cell& next){

    if (current.getCol() < next.getCol()){
        current.removeWallHelper(1); //right
        next.removeWallHelper(3); //left
    }
    else if (current.getCol() > next.getCol()){
        current.removeWallHelper(3); // left
        next.removeWallHelper(1); // right
    }
    else if (current.getRow() < next.getRow()){
        current.removeWallHelper(2); //bottom
        next.removeWallHelper(0); //top
    }
    else if (current.getRow() > next.getRow()){
        current.removeWallHelper(0); //bottom
        next.removeWallHelper(2); // top
    }
}

int main(){


    InitWindow(DIMENSION, DIMENSION, "Maze Generator");
    SetTargetFPS(10);

    

    vector<vector<Cell>> grid = createMazeGrid(); //The grid of cell objects
    Cell& current = grid[0][0];
    current.visit();
    
    
    //renderMazeGrid(grid, 40); //Render those cell objects here
    Cell* next = current.checkNeighbors(grid, current.getRow(), current.getCol()); 

    while (!WindowShouldClose()){

        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        renderMazeGrid(grid, 40); //Render those cell objects here 
        current.highlightCell(40);

       
        
        if (next != nullptr){
             //Step 1
            
            next->visit();

            //Step 3
            removeWall(current, *next);
            //Step 4
            current = *next; 
            next = current.checkNeighbors(grid, current.getRow(), current.getCol());
            
        }
 
        EndDrawing();
    }


    CloseWindow();

}