#[derive(Clone, Copy, Default)]
struct Entity {
    is_fill: bool,
    key: i32,
    freq: i32, 
}

#[inline(always)] 
fn update_freqs(freqs: &mut [Entity], key: i32, amount: i32) {
    let freqs_len = freqs.len();
    let mut idx = (key as usize) % freqs_len;
    while freqs[idx].is_fill {
        if freqs[idx].key == key {
            break;
        }
        idx += 1;
        if idx == freqs_len {
            idx = 0;
        }
    }

    freqs[idx].key = key;
    freqs[idx].is_fill = true;
    freqs[idx].freq += amount;
}

#[inline(always)] 
fn get_freq(freqs: &[Entity], key: i32) -> i32 {
    let freqs_len = freqs.len();
    let mut idx = (key as usize) % freqs_len;
    while freqs[idx].is_fill {
        if freqs[idx].key == key {
            break;
        }
        idx += 1;
        if idx == freqs_len {
            idx = 0;
        }
    }

    freqs[idx].freq
}

impl Solution {
    pub fn max_subarray_length(nums: Vec<i32>, k: i32) -> i32 {
        assert!(k >= 1 && (k as usize) <= nums.len() && nums.len() <= 100_000);

        let len = nums.len();
        let mut freqs = vec![Entity::default(); 2 * len];
        let mut lo = 0_usize;
        let mut max = 0_usize;
        for hi in 0..len {
            update_freqs(&mut freqs, nums[hi], 1);
            while get_freq(&freqs, nums[hi]) > k {
                update_freqs(&mut freqs, nums[lo], -1);
                lo += 1;
            }
            max = max.max(hi - lo + 1);
        }

        max as i32
    }
}
