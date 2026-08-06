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
    fn dfs(node_rc_opt: Option<&Rc<RefCell<TreeNode>>>, stack: &mut Vec<u8>, res: &mut Vec<u8>) {
        if let Some(node_rc) = node_rc_opt {
            let node = node_rc.borrow();
            assert!(node.val >= 0 && node.val <= 25);
            stack.push(node.val as u8 + b'a');
            if node.left.is_none() && node.right.is_none() {
                if res.is_empty() || stack.iter().rev().cmp(res.iter().rev()).is_lt() {
                    res.clone_from(stack);
                }
            }
            Self::dfs(node.left.as_ref(), stack, res);
            Self::dfs(node.right.as_ref(), stack, res);
            stack.pop();
        }
    }

    pub fn smallest_from_leaf(root: Option<Rc<RefCell<TreeNode>>>) -> String {
        let mut res: Vec<u8> = Vec::new();
        let mut stack: Vec<u8> = Vec::new();

        Self::dfs(root.as_ref(), &mut stack, &mut res);

        res.reverse();

        String::from_utf8(res).unwrap()
    }
}
