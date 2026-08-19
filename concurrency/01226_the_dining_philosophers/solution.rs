use std::sync::{Mutex, Arc};

const CNT: usize = 5;

struct DiningPhilosophers {
    mtxs: [Mutex<()>; CNT],
}

impl DiningPhilosophers {
    fn new() -> Self {
        Self {
            mtxs: std::array::from_fn(|_| Mutex::new(()))
        }
    }

    // Callbacks are like LeetCode: each used exactly once
    fn wants_to_eat<F1, F2, F3, F4, F5>(
        &self,
        philosopher: i32,
        pick_left_fork: F1,
        pick_right_fork: F2,
        eat: F3,
        put_left_fork: F4,
        put_right_fork: F5,
    )
    where
        F1: FnOnce(),
        F2: FnOnce(),
        F3: FnOnce(),
        F4: FnOnce(),
        F5: FnOnce(),
    {
        let (lower_fork, upper_fork) = if philosopher == 0 {
            (0, CNT - 1)
        } else {
            ((philosopher as usize) - 1, philosopher as usize)
        };

        let l = self.mtxs[lower_fork].lock().unwrap();
        let u = self.mtxs[upper_fork].lock().unwrap();
        pick_left_fork();
        pick_right_fork();
        eat();
        put_left_fork();
        put_right_fork();
    }
}
