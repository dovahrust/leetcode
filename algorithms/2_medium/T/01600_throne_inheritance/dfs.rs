use std::collections::HashMap;

struct ThroneInheritance {
    data: Vec<(String, bool, Vec<usize>)>,
    hashmap: HashMap<String, usize>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl ThroneInheritance {

    fn new(king_name: String) -> Self {
        let data = vec![(king_name.clone(), true, Vec::new())];
        let mut hashmap: HashMap<String, usize> = HashMap::new();
        hashmap.insert(king_name, 0);
        Self {
            data: data,
            hashmap: hashmap,
        }
    }
    
    fn birth(&mut self, parent_name: String, child_name: String) {
        let idx: usize = self.hashmap[&parent_name];
        let child_id = self.data.len();
        self.data.push((child_name.clone(), true, Vec::new()));
        self.hashmap.insert(child_name, child_id);
        self.data[idx].2.push(child_id);
    }
    
    fn death(&mut self, name: String) {
        let idx: usize = self.hashmap[&name];
        self.data[idx].1 = false;
    }
    
    fn get_inheritance_order(&self) -> Vec<String> {
        let mut res: Vec<String> = Vec::new();
        self.dfs(0, &mut res);
        res
    }

    fn dfs(&self, curr: usize, res: &mut Vec<String>) {
        if self.data[curr].1 {
            res.push(self.data[curr].0.clone());
        }
        for &child in &self.data[curr].2 {
            self.dfs(child, res);
        } 
    }
}

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * let obj = ThroneInheritance::new(kingName);
 * obj.birth(parentName, childName);
 * obj.death(name);
 * let ret_3: Vec<String> = obj.get_inheritance_order();
 */
