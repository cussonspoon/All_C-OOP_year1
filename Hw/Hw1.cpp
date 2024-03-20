#include <iostream>
#include <array>
#include <random>
#include <algorithm>

void generate_maze(std::array<std::array<char, 15>, 15>& maze) {
    std::array<char, 2> random_element = {'#', ' '};
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 1);

    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            if (i == 0 && (j != 0 && j != 14)) {
                maze[i][j] = '#';
            } else if (i == 14 && (j != 0 && j != 14)) {
                maze[i][j] = '#';
            } else if (j == 0 || j == 14) {
                maze[i][j] = '#';
            } else {
                maze[i][j] = random_element[dis(gen)];
            }
        }
    }

    std::uniform_int_distribution<int> entrance_dis(1, 13);
    std::uniform_int_distribution<int> exit_dis(1, 13);

    int entrance_col = entrance_dis(gen);
    int exit_col = exit_dis(gen);

    maze[0][entrance_col] = ' ';
}

void solve_maze(std::array<std::array<char, 15>, 15>& maze){
    for (int j = 0 ; j < 15 ; j++){
        if (maze[0][j] == ' '){
            maze[0][j] = '.';
        }
    }
    auto it = std::find(maze[0].begin(), maze[0].end(), '.');
    int index_of_previous_path = std::distance(maze[0].begin(), it);
    for (int i = 1; i < 15 ; i++){
        if (maze[i][index_of_previous_path] == ' '){
            maze[i][index_of_previous_path] = '.';
        }
        else if (maze[i-1][index_of_previous_path+1] == ' '){
            while (true){
            if (maze[i-1][index_of_previous_path+1] == '#'){
                break;
            }
            maze[i-1][index_of_previous_path+1] = '.';
            index_of_previous_path++;
            }
        }
        else if (maze[i-1][index_of_previous_path-1] == ' '){
            while (true){
            if (maze[i-1][index_of_previous_path-1] == '#'){
                break;
            }
            maze[i-1][index_of_previous_path-1] = '.';
            index_of_previous_path--;
        }
        }
        else{
            maze[i][index_of_previous_path] = '.';
        }
        if (maze[i][index_of_previous_path] == ' '){
            maze[i][index_of_previous_path] = '.';
        }
        if (maze[i][index_of_previous_path] == '#'){
            maze[i][index_of_previous_path] = '.';
        }
    }

}




int main() {
    std::array<std::array<char, 15>, 15> maze;

    generate_maze(maze);

    solve_maze(maze);

    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            std::cout << maze[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
