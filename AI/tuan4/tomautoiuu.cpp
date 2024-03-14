    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <fstream>
    #include <limits.h>
    using namespace std;
    int m;

    int color = 1;
    vector<vector<int>> Matrix;

    void docfile()
    {
        fstream input("./data/color3.txt", ios::in);
        input >> m;

        Matrix.resize(m, vector<int>(m, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                input >> Matrix[i][j];
            }
        }
        input.close();
    }

    // Hàm tìm đỉnh có bậc lớn nhất chưa được tô màu
    int getMaxDegreeVertex(const vector<int> &degrees, const vector<int> &colors)
    {
        int max_degree = -1;
        int max_vertex = -1;
        for (int i = 0; i < degrees.size(); ++i)
        {
            if (degrees[i] > max_degree && colors[i] == -1)
            {
                max_degree = degrees[i];
                max_vertex = i;
            }
        }
        return max_vertex;
    }

    int getSaturation(const vector<vector<int>> &adjacencyMatrix, const vector<int> &colors, int v)
    {
        int saturation = 0;
        for (int i = 0; i < adjacencyMatrix.size(); ++i)
        {
            if (adjacencyMatrix[v][i] && colors[i] != -1)
            {
                saturation++;
            }
        }
        return saturation;
    }

    // Hàm áp dụng thuật toán DSATUR để tô màu đồ thị
    int dsatur(const vector<vector<int>> &adjacencyMatrix, vector<int> &colors, vector<int> &degrees)
    {
        int num_vertices = adjacencyMatrix.size();
        colors.assign(num_vertices, -1);
        degrees.assign(num_vertices, 0);

        // Tính bậc của mỗi đỉnh
        for (int i = 0; i < num_vertices; ++i)
        {
            for (int j = 0; j < num_vertices; ++j)
            {
                degrees[i] += adjacencyMatrix[i][j];
            }
        }

        int max_color = -1;
        while (true)
        {
            int v = getMaxDegreeVertex(degrees, colors);
            if (v == -1)
                break;

            vector<int> available_colors(num_vertices, 0);
            for (int i = 0; i < num_vertices; ++i)
            {
                if (adjacencyMatrix[v][i] && colors[i] != -1)
                {
                    available_colors[colors[i]] = 1;
                }
            }

            int max_saturation = -1;
            for (int i = 0; i < num_vertices; ++i)
            {
                if (available_colors[i] == 0)
                {
                    int saturation = getSaturation(adjacencyMatrix, colors, v);
                    if (saturation > max_saturation)
                    {
                        max_saturation = saturation;

                        max_color = i;
                    }
                }
            }
            colors[v] = max_color;
        }
        int max = INT_MIN;
        for (int i : colors)
        {
            if (i > max)
                max = i;
        }
        return max+1;
    }

    int main()
    {
        vector<int> colors;
        vector<int> degrees;
        docfile();
        int num_colors = dsatur(Matrix, colors, degrees);
        // In ra số màu cần thiết
        cout << "Number of colors required: " << num_colors << endl;

        return 0;
    }
