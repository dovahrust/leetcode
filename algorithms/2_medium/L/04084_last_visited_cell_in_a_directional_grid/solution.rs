impl Solution {
    const VISITED: char = '#';

    pub fn last_visited_cell(mut grid: Vec<Vec<char>>) -> Vec<i32> {
        let rows = grid.len() as isize;
        let cols = grid[0].len() as isize;
        let (mut i, mut j): (isize, isize) = (0, 0);

        loop {
            let (ni, nj) = match grid[i as usize][j as usize] {
                'U' => (i - 1, j),
                'R' => (i, j + 1),
                'D' => (i + 1, j),
                'L' => (i, j - 1),
                _ => unreachable!(),
            };

            if ni < 0 || nj < 0 || ni >= rows || nj >= cols || grid[ni as usize][nj as usize] == Self::VISITED  { break; }

            grid[i as usize][j as usize] = Self::VISITED;
            (i, j) = (ni, nj);
        }

        vec![i as i32, j as i32]
    }
}
