bool checkCell(std::vector<std::string>* field, int x, int y) {
    if ((*field)[y][x] != '#' && (*field)[y][x] != 'X') {
        if ((*field)[y][x] == 'E') return true;
        else (*field)[y][x] = 'C';
    }
    return false;
}

bool is_can_exit_from_maze(std::vector<std::string> field, int startRow, int startCol) {
    bool exitFound = false;
    field[startRow][startCol] = 'C';
    while(true) {
        bool foundToCheck = false;
        for (int y = 1; y < field.size() - 1; y++) {
            for (int x = 1; x < field[0].length() - 1; x++) {
                if (field[y][x] == 'C') {
                    foundToCheck = true;
                    // Left
                    exitFound = checkCell(&field, x-1, y);
                    if (exitFound) break;

                    // Right
                    exitFound = checkCell(&field, x+1, y);
                    if (exitFound) break;

                    // Up
                    exitFound = checkCell(&field, x, y-1);
                    if (exitFound) break;

                    // Down
                    exitFound = checkCell(&field, x, y+1);
                    if (exitFound) break;

                    field[y][x] = 'X';
                }
            }
            if (exitFound) break;
        }
        if (!foundToCheck || exitFound) break;
    }
    return exitFound;
}
