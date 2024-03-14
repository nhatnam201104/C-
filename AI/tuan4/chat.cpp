#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> colors(1000, 0);
struct Vertex
{
    int id;
    int degree;
    Vertex(int i, int d) : id(i), degree(d) {}
    bool operator<(const Vertex &other) const
    {
        return degree > other.degree;
    }
};

vector<vector<int>> c; // Ma trận kề
int n;                 // Số đỉnh của đồ thị

int welshPowell()
{
    // Tạo một vector các đỉnh kèm theo bậc của chúng
    vector<Vertex> vertices;
    for (int i = 0; i < n; ++i)
    {
        int degree = 0;
        for (int j = 0; j < n; ++j)
            if (c[i][j])
                ++degree;
        vertices.push_back(Vertex(i, degree));
    }
    stable_sort(vertices.begin(), vertices.end());
    for (auto i : vertices)
    {
        cout << i.degree << " "<<" "<<i.id<<"\n";
    }

    // Sắp xếp các đỉnh theo thứ tự giảm dần của bậc, giữ nguyên thứ tự ban đầu nếu có bậc bằng nhau

    // Vector để lưu màu của mỗi đỉnh

    int color = 1; // Màu hiện tại
    bool all_colored, can_color;

    // Vòng lặp chính để tô màu
    while (true)
    {
        all_colored = true;

        // Duyệt qua các đỉnh
        for (vector<Vertex>::iterator it = vertices.begin(); it != vertices.end(); ++it)
        {
            Vertex vertex = *it;

            // Nếu đỉnh chưa được tô màu
            if (!colors[vertex.id])
            {
                can_color = true;

                // Kiểm tra xem đỉnh có thể được tô màu với màu hiện tại hay không
                for (int i = 0; i < n; ++i)
                {
                    if (c[vertex.id][i] && colors[i] == color)
                    {
                        can_color = false;
                        break;
                    }
                }

                // Nếu đỉnh có thể được tô màu, gán màu và đánh dấu là chưa tô màu hết
                if (can_color)
                {
                    colors[vertex.id] = color;
                    all_colored = false;
                }
            }
        }

        // Nếu tất cả các đỉnh đã được tô màu, thoát khỏi vòng lặp
        if (all_colored)
            break;

        // Chuyển sang màu tiếp theo
        ++color;
    }

    // cout<<"\n";
    // cout<<"\n";
    // for (auto i:colors)
    // {
    //     cout<<colors[i]<<"\n";
    // }
    // cout<<"\n";
    // cout<<"\n";
    return color; // Trả về số màu sử dụng
}

int main()
{
    fstream inFile("data/color2.txt", ios::in); // Tên tệp đầu vào
    ofstream outFile("output.txt");             // Tên tệp đầu ra

    if (!inFile)
    {
        cerr << "Không thể mở tệp đầu vào!" << endl;
        return 1;
    }

    // Đọc số đỉnh từ tệp
    inFile >> n;

    // Khởi tạo ma trận kề và đọc dữ liệu từ tệp
    c.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            inFile >> c[i][j];

    // Gọi hàm tô màu Welsh-Powell
    int num_colors = welshPowell();

    // Xuất kết quả ra tệp
    outFile << "Số màu cần: " << num_colors << endl;
    for (int i = 0; i < n; ++i)
        outFile << "Đỉnh " << i + 1 << " có màu: " << colors[i] << endl;

    // Đóng các tệp
    inFile.close();
    outFile.close();

    return 0;
}
