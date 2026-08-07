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
    fn dfs(node_rc_opt: Option<&Rc<RefCell<TreeNode>>>, data: &mut Vec<(i16, i16, i32)>, rows: i16, cols: i16) {
        if let Some(node_rc) = node_rc_opt {
            let node = node_rc.borrow();
            data.push((cols, rows, node.val));
            Self::dfs(node.left.as_ref(), data, rows + 1, cols - 1);
            Self::dfs(node.right.as_ref(), data, rows + 1, cols + 1);
        }
    }

    pub fn vertical_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut data: Vec<(i16, i16, i32)> = Vec::new();
        Self::dfs(root.as_ref(), &mut data, 0, 0);

        data.sort_unstable();

        if data.is_empty() {
            return Vec::default();
        }

        let mut res: Vec<Vec<i32>> = Vec::with_capacity(data.len());
        res.push(vec![data[0].2]);
        for i in 1..data.len() {
            if data[i].0 == data[i - 1].0 {
                res.last_mut().unwrap().push(data[i].2);
            } else {
                res.push(vec![data[i].2]);
            }
        }

        res
    }
}
