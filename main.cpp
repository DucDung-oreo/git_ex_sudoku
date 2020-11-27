void print_sudoku(std::vector<std::vector<int>> sudoku);
bool Feasible(std::vector<std::vector<int>> sudoku, int x, int y,int k);
std::vector<std::vector<int>> solverSudoku(std::vector<std::vector<int>> sudoku, int x, int y){
    if (y==9){
        if(x==8){
            print_sudoku(sudoku);
        }
        else solverSudoku(sudoku, x+1, 0);
    }
    else if (sudoku[x][y] == 0){
        for (int k =1; k <10; k++){
            if (Feasible(sudoku, x, y, k)){
                sudoku[x][y] = k;
                solverSudoku(sudoku, x, y+1);
                sudoku[x][y] = 0;
            }
        }
    }    
    else{
        solverSudoku(sudoku,x,y+1);
    }    
}
bool Feasible(std::vector<std::vector<int>> sudoku, int x, int y,int k){
    // check if sudoku[x][y] is feasible at colomn y
    for(int i = 0; i < 9; i++){ 
        if (sudoku[x][i] == k){
            return false;
        }
    }
    // check if sudoku[x][y] is feasible at row x
    for(int i = 0; i < 9; i++){
        if (sudoku[i][y] == k){
            return false;
        }
    }
    // check if sudoku[x][y] is feasible at square 
    int a = x/3; int b = y/3;
    for(int i = 3*a; i < 3*a + 3; i++){
        for(int j = 3*b; j < 3*b + 3; j++){
            if (sudoku[i][y] == k){
            return false;
            }
        }
    return true;
    }
}
void print_sudoku(std::vector<std::vector<int>> sudoku){
    for(int i = 0; i < 9; i++){
        cout << "[";
        for(int j = 0; j < 9; j++){
            cout << sudoku[i][j] << ",";
        }
        cout << "]" << endl;
    }
}
