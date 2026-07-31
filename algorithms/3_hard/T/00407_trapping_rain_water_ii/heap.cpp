typedef ptrdiff_t isize;

constexpr size_t dir_len = 4;
constexpr isize directions[dir_len][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

class Solution {
    struct Cell {
        int height;
        int16_t i;
        int16_t j;

        Cell(const int height, const int16_t i, const int16_t j) {
            this->height = height;
            this->i = i;
            this->j = j;
        }

        bool operator<(const Cell& other) const {
            return height > other.height;
        }
    };

public:
    static int trapRainWater(const vector<vector<int>>& height_map) {
        assert(height_map.size() <= 200 && height_map.size() > 0);
        assert(height_map[0].size() <= 200 && height_map[0].size() > 0);
        const isize rows = std::ssize(height_map);
        const isize cols = std::ssize(height_map[0]);

        auto heap = priority_queue<Cell>();
        auto is_visited = vector<uint8_t>(rows * cols, 0);

        for (isize i = 0; i < rows; i += 1) {
            for (isize j = 0; j < cols; j += 1) {
                if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                    is_visited[i * cols + j] = 1;
                    heap.push(Cell(height_map[i][j], static_cast<int16_t>(i), static_cast<int16_t>(j)));
                }
            }
        }

        int sum = 0;

        while (!heap.empty()) {
            const Cell cell = heap.top();
            heap.pop();

            const isize j = cell.j;
            const isize i = cell.i;
            const int height = cell.height;

            for (const auto [dx, dy] : directions) {
                const int16_t ni = i + dx;
                const int16_t nj = j + dy;

                if (ni >= rows || nj >= cols || ni < 0 || nj < 0 || is_visited[ni * cols + nj] == 1) {
                    continue;
                }

                const int nheight = height_map[ni][nj];
                sum += std::max(0, height - nheight);
                is_visited[ni * cols + nj] = 1;
                heap.push(Cell(std::max(nheight, height), static_cast<int16_t>(ni), static_cast<int16_t>(nj)));
            }
        }

        return sum;
    }
};
