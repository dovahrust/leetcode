struct Entity {
    child: [u32; 26],
    is_end: bool,
}

struct StreamChecker {
    trie: Vec<Entity>,
    idxs: Vec<u32>,
    swaps: Vec<u32>,
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl StreamChecker {

    fn new(words: Vec<String>) -> Self {
        assert!(words.len() <= 2000);
        let mut trie = vec![Entity { child: [0; 26], is_end: false }];
        for w in words {
            assert!(w.len() <= 200 && w.len() >= 1);
            let mut curr: u32 = 0;

            for b in w.into_bytes() {
                assert!(b >= b'a' && b <= b'z');
                if trie[curr as usize].child[(b - b'a') as usize] == 0 {
                    trie[curr as usize].child[(b - b'a') as usize] = trie.len() as u32;
                    curr = trie.len() as u32;
                    trie.push(Entity { child: [0; 26], is_end: false });
                } else {
                    curr = trie[curr as usize].child[(b - b'a') as usize];
                }
            }

            trie[curr as usize].is_end = true;
        }
        Self {
            trie: trie,
            idxs: Vec::default(),
            swaps: Vec::default(),
        }
    }

    fn query(&mut self, letter: char) -> bool {
        let letter = letter as u8;
        assert!(letter >= b'a' && letter <= b'z');
        self.swaps.clear();
        if self.trie[0].child[(letter - b'a') as usize] != 0 {
            self.swaps.push(self.trie[0].child[(letter - b'a') as usize]);
        }

        for &idx in &self.idxs {
            if self.trie[idx as usize].child[(letter - b'a') as usize] != 0 {
                self.swaps.push(self.trie[idx as usize].child[(letter - b'a') as usize]);
            }
        }

        let mut res = false;
        for &idx in &self.swaps {
            if self.trie[idx as usize].is_end {
                res = true;
                break;
            }
        }

        std::mem::swap(&mut self.idxs, &mut self.swaps);
        res
    }
}

/**
 * Your StreamChecker object will be instantiated and called as such:
 * let obj = StreamChecker::new(words);
 * let ret_1: bool = obj.query(letter);
 */
