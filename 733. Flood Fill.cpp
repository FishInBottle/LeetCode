class Solution {
public:
    int x_size, y_size;

    void fillColor(vector<vector<int>>& image, int x, int y, int target_color,
                   int new_color) {
        if ((x < 0) || (x >= x_size) || (y < 0) || (y >= y_size) ||
            (target_color != image[x][y]))
            return;

        /* Check this pixel
        1. Fill it if it's not equal new_color
        2. Escape if it's equal new_color to avoid infinite loop here
         */
        if (new_color == image[x][y]) {
            return;
        } else {
            image[x][y] = new_color;
        }

        /* Check pixels around this pixel */
        fillColor(image, x - 1, y, target_color, new_color);
        fillColor(image, x, y - 1, target_color, new_color);
        fillColor(image, x + 1, y, target_color, new_color);
        fillColor(image, x, y + 1, target_color, new_color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int target_color = image[sr][sc];
        x_size = image.size();
        y_size = image[0].size();

        fillColor(image, sr, sc, target_color, color);
        return image;
    }
};