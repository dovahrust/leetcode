impl Solution {
    pub fn aggregate_time_series(series1: Vec<Vec<i32>>, series2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let (len1, len2) = (series1.len(), series2.len());
        let mut res = Vec::with_capacity(len1 + len2);
        let (mut i1, mut i2) = (0_usize, 0_usize);

        while i1 < len1 && i2 < len2 {
            let time_min = series1[i1][0].min(series2[i2][0]);
            let val = series1[i1][1] + series2[i2][1];
            res.push(vec![time_min, val]);

            if series1[i1][0] == time_min {
                i1 += 1;
            }

            if series2[i2][0] == time_min {
                i2 += 1;
            }
        }

        for v in series1.into_iter().skip(i1)  {
            res.push(v);
        }

        for v in series2.into_iter().skip(i2)  {
            res.push(v);
        }

        res
    }
}
