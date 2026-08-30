impl Solution {
    pub fn is_valid_serialization(preorder: String) -> bool {
        let bytes =  preorder.as_bytes();
        let mut balance = 1_usize;

        for part in preorder.split(',') {
            if balance == 0 {
                return false;
            }

            if part == "#" {
                balance -= 1;
            } else {
                balance += 1;
            }
        }

        balance == 0
    }
}
