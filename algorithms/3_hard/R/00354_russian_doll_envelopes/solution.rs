impl Solution {
    pub fn max_envelopes(mut envelopes: Vec<Vec<i32>>) -> i32 {
        envelopes.sort_unstable_by(|a, b| {
            if a[0] == b[0] {
                b[1].cmp(&a[1])
            } else {
                a[0].cmp(&b[0])
            }
        });

        let mut lis: Vec<i32> = Vec::with_capacity(envelopes.len());

        for e in envelopes {
            let pos = lis.binary_search(&e[1]).unwrap_or_else(|x| x);

            if pos == lis.len() {
                lis.push(e[1]);
            } else {
                lis[pos] = e[1];
            }
        }

        lis.len().try_into().unwrap()
    }
}
