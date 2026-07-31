use std::collections::BinaryHeap;

#[derive(Eq, PartialEq)]
struct Cell {
    height: i32,
    i: i16,
    j: i16,
}

impl Ord for Cell {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        other.height.cmp(&self.height)
    }
}

impl PartialOrd for Cell {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        Some(self.cmp(other))
    }
}

impl Solution {
    const DIRECTIONS: [(isize, isize); 4]= [(-1, 0), (0, -1), (1, 0), (0, 1)];

    pub fn trap_rain_water(height_map: Vec<Vec<i32>>) -> i32 {
        assert!(height_map.len() <= 200 && height_map.len() > 0);
        assert!(height_map[0].len() <= 200 && height_map[0].len() > 0);
        let rows = height_map.len() as isize;
        let cols = height_map[0].len() as isize;
        let mut heap:BinaryHeap<Cell> = BinaryHeap::new();
        let mut is_visited = vec![false; (rows * cols) as usize];

        for i in 0..rows {
            for j in 0..cols {
                if i == 0 || i == rows - 1 || j == 0 || j == cols - 1 {
                    is_visited[(i * cols + j) as usize] = true;
                    heap.push(Cell{height: height_map[i as usize][j as usize], i: i as i16, j: j as i16});
                }
            }
        }

        let mut sum = 0_i32;

        while let Some(cell) = heap.pop() {
            let i = cell.i as isize;
            let j = cell.j as isize;
            let height = cell.height;

            for (dx, dy) in Self::DIRECTIONS {
                let ni = i + dx;
                let nj = j + dy;

                if ni >= rows || nj >= cols || ni < 0 || nj < 0 || is_visited[(ni * cols + nj) as usize] {
                    continue;
                }

                let nheight = height_map[ni as usize][nj as usize];
                sum += (height - nheight).max(0);
                is_visited[(ni * cols + nj) as usize] = true;
                heap.push(Cell{height: nheight.max(height), i: ni as i16, j: nj as i16});
            }
        }

        sum
    }
}
