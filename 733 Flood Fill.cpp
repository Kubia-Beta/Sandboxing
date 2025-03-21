class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // create a tracking vector from vector<vector<int>>
        vector<vector<bool>> accessedSquares(image.size(), vector<bool>(image[0].size(), false));
        // grab our bounds for checking
        int rowBoundIndex = image.size() - 1;
        int colBoundIndex = image[0].size() - 1;
        int targetColor = image[sr][sc]; // This is the value we change
        // change the starting color of the pixel at image[i][j]
        image[sr][sc] = color;
        // change paintedSquares[i][j] to 1
        accessedSquares[sr][sc] = true;
        
        // recurse right case
        if (sr+1 <= rowBoundIndex){ 
            floodFillRecurse(image, accessedSquares, targetColor, rowBoundIndex, colBoundIndex, color, sr+1, sc);
        }
        // recurse left case
        if (sr-1 >= 0){ 
            floodFillRecurse(image, accessedSquares, targetColor, rowBoundIndex, colBoundIndex, color, sr-1, sc);
        }
        // recurse down case
        if (sc+1 <= colBoundIndex){ 
            floodFillRecurse(image, accessedSquares, targetColor, rowBoundIndex, colBoundIndex, color, sr, sc+1);
        }
        // recurse up case
        if (sc-1 >= 0){ 
            floodFillRecurse(image, accessedSquares, targetColor, rowBoundIndex, colBoundIndex, color, sr, sc-1);
        }

        return image;
    }

    void floodFillRecurse(vector<vector<int>> &image, vector<vector<bool>> &accessedSquares, int targetColor, 
    int rowBoundIndex, int colBoundIndex, int color, int sr, int sc) {
        // guard clause for already accessed squares
        if (true == accessedSquares[sr][sc]){
            return;
        }
        accessedSquares[sr][sc] = true; // Set this to true now that we are going to perform operations on it
        // move on to square painting
        if (image[sr][sc] == targetColor){ // if there is a match
            image[sr][sc] = color; // change the color
        } else {
            return;
        }

        // our recursive call checks that we have not accessed the square first to ensure that every square is accessed only once
        if (sr+1 <= rowBoundIndex && false == accessedSquares[sr+1][sc]){ // recurse right case
            floodFillRecurse(image, accessedSquares, targetColor, rowBoundIndex, colBoundIndex, color, sr+1, sc);
        }

        if (sr-1 >= 0 && false == accessedSquares[sr-1][sc]){ // recurse left case
            floodFillRecurse(image, accessedSquares, targetColor, rowBoundIndex, colBoundIndex, color, sr-1, sc);
        }

        if (sc+1 <= colBoundIndex && false == accessedSquares[sr][sc+1]){ // recurse down case
            floodFillRecurse(image, accessedSquares, targetColor, rowBoundIndex, colBoundIndex, color, sr, sc+1);
        }

        if (sc-1 >= 0 && false == accessedSquares[sr][sc-1]){ // recurse up case
            floodFillRecurse(image, accessedSquares, targetColor, rowBoundIndex, colBoundIndex, color, sr, sc-1);
        }

        return;
    }
};