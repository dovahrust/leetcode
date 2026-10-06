impl Solution {
    pub fn score_validator(events: Vec<String>) -> Vec<i32> {
        let mut cnt: i32 = 0;
        let mut score: i32 = 0;

        for e in events {
            match e.as_bytes() {
                b"W" => cnt += 1,
                b"WD" | b"NB" => score += 1,
                _ => score += e.parse::<i32>().expect("invalid input"),
            }

            if cnt == 10 { break; }
        }

        vec![score, cnt]
    }
}
