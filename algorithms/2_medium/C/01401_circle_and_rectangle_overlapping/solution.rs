impl Solution {
    pub fn check_overlap(r: i32, cx: i32, cy: i32, rx1: i32, ry1: i32, rx2: i32, ry2: i32) -> bool {
        let closest_x = rx1.max(rx2.min(cx));
        let closest_y = ry1.max(ry2.min(cy));

        let (dx, dy) = (cx - closest_x, cy - closest_y);

        (dx * dx) + (dy * dy) <= r * r
    }
}
