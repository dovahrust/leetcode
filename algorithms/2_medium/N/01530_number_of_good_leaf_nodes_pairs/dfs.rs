// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    fn dfs(node_rc_opt: Option<&Rc<RefCell<TreeNode>>>, distance: usize, res: &mut i32) -> Option<Vec<i32>> {
        match node_rc_opt {
            Some(node_rc) => {
                let node = node_rc.borrow();
                let l_opt = Self::dfs(node.left.as_ref(), distance, res);
                let r_opt = Self::dfs(node.right.as_ref(), distance, res);

                match (l_opt, r_opt) {
                    (None, None) => {
                        let mut vec = vec![0_i32; distance + 1];
                        vec[0] = 1;
                        Some(vec)
                    },
                    (None, Some(mut vec)) | (Some(mut vec), None) => {
                        for i in (1..=distance).rev() {
                            vec[i] = vec[i - 1];
                        }
                        vec[0] = 0;
                        Some(vec)
                    },
                    (Some(mut l), Some(r)) => {
                        for i in 0..=distance {
                            for j in 0..=distance {
                                if i + j + 2 <= distance {
                                    *res = *res + l[i] * r[j];
                                } 
                            }
                        }

                        for i in (1..=distance).rev() {
                            l[i] = l[i - 1] + r[i - 1];
                        }
                        l[0] = 0;

                        Some(l)
                    }
                }
            },
            None => None,
        }
    }

    pub fn count_pairs(root: Option<Rc<RefCell<TreeNode>>>, distance: i32) -> i32 {
        let mut res: i32 = 0;
        Self::dfs(root.as_ref(), distance as usize, &mut res);
        res
    }
}
