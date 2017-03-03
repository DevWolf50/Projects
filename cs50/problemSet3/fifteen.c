/**
 * Ive created the key functions for the the game of fifteen
 *
 */



/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */
void init(void)
{
    int tileCount = d * d - 1;
    for ( int i = 0; i < d; i++) {

        for ( int j = 0; j < d; j++) {

            board[i][j] = tileCount;

            tileCount--;
        }
    }

    if ( d % 2 == 0 ) {
        int temp;
        temp = board[d - 1 ][ d - 2];
        board[d - 1][d - 2] = board[d - 1][ d - 3];
        board[d - 1][d - 3] = temp;

    }

}

/**
 * Prints the board in its current state.
 */
void draw(void)
{

    for ( int i = 0; i < d ; i++) {

        for ( int j = 0; j < d; j++) {

            printf("%i ", board[i][j]);
        }

        printf("\n\n");
    }

}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 *
 * @param   int     tile    The tile the user wants to move
 * @param   int[]   space   Space keeps track of where the space is on the board
 * @return  bool
 */
bool move(int tile, int space[])
{
    //check the tile to the left of the space tile so we can swap the space tile with the tile the user wanted
    if ( board[ space[0] ][ space[1] + 1 ] == tile ) {

        board[ space[0] ][ space[1] + 1 ] = 0;

        board[ space[0] ][ space[1] ] = tile;
        space[1]++;

        return true;

    //check the tile to the right of the space tile so we can swap the space tile with the tile the user selected
    }else if ( board[ space[0] ][ space[1] - 1] == tile ) {

        board[ space[0] ][ space[1] - 1 ] = 0;

        board[ space[0] ][space[1] ] = tile;
        space[1]--;

        return true;

    //check the tile to the top of the space tile so we can swap the space tile with the tile the user selected
    }else if ( board[ space[0] + 1 ][ space[1] ] == tile ) {

        board[ space[0] + 1 ][ space[1] ] = 0;

        board[ space[0] ][space[1] ] = tile;
        space[0]++;

        return true;

    //check the tile to the bottom of the space tile so we can swap the space tile with the tile the user selected
    }else if ( board[ space[0] - 1 ][ space[1] ] == tile ) {

        board[ space[0] - 1 ][ space[1] ] = 0;

        board[ space[0] ][space[1] ] = tile;
        space[0]--;

        return true;

    } else {
        //the tile does not border the space tile
        return false;
    }
}

/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
bool won(void)
{
    return checkForWin(0);
}

bool checkForWin(int tile) {
    //IF we got to the 2nd to last tile then we won
    if (tile >= d * d - 2) {
        return true;
    }

    //Start with the first tile on the board and check to see if it equals the next tile + 1
    if ( board[ ( tile + 1 ) / d ][  (tile + 1 ) % d ] == board[ tile / d ][ tile % d ] + 1) {
        return checkForWin(tile = tile + 1);
    } else {
       return false;
    }


}
