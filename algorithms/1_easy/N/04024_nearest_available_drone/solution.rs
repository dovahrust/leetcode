impl Solution {
    pub fn nearest_drone(drones: Vec<Vec<i32>>, target: Vec<i32>) -> i32 {
        let mut res: Option<(usize, i32)> = None;
        let (tx, ty) = (target[0], target[1]);

        for (i, d) in drones.iter().enumerate() {
            let (dx, dy, dr) = (d[0], d[1], d[2]);

            let dist = (tx - dx).abs() + (ty - dy).abs();

            if dist <= dr {
                match res {
                    None => {
                        res = Some((i, dist));
                    },
                    Some((_, res_dist)) => {
                        if dist < res_dist {
                            res = Some((i, dist));
                        }
                    }
                }
            }
        }

        match res {
            None => -1,
            Some((idx, _)) => idx.try_into().unwrap(),
        }
    }
}
