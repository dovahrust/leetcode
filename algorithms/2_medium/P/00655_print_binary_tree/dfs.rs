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
    fn dfs_height(node_rc_opt: Option<&Rc<RefCell<TreeNode>>>) -> u32 {
        if let Some(node_rc) = node_rc_opt {
            let node = node_rc.borrow();
            return 1 + Self::dfs_height(node.left.as_ref())
                       .max(Self::dfs_height(node.right.as_ref()))
        }

        0
    }

    fn fill_res(node_rc_opt: Option<&Rc<RefCell<TreeNode>>>, res: &mut [Vec<String>], level: usize, lo: isize, hi: isize) {
        if let Some(node_rc) = node_rc_opt {
            let node = node_rc.borrow();
            let mid = lo + (hi - lo) / 2;
            res[level][mid as usize] = format!("{}", node.val);
            Self::fill_res(node.left.as_ref(), res, level + 1, lo, mid - 1);
            Self::fill_res(node.right.as_ref(), res, level + 1, mid + 1, hi);
        }
    }

    pub fn print_tree(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<String>> {
        let rows = Self::dfs_height(root.as_ref());
        let cols = 2_u32.pow(rows) - 1;
        let mut res = vec![vec![String::default(); cols as usize]; rows as usize];

        Self::fill_res(root.as_ref(), &mut res, 0, 0, cols as isize - 1);

        res
    }
}
