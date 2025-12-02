use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn min_subarray(nums: Vec<i32>, p: i32) -> i32 {
        let mut remainders: HashMap<i64, usize> = HashMap::new();
        let mut best: usize = nums.len();
        let mut current_sum: i64 = 0;
        let mut current_key: i64;
        let mut res: i32;

        for i in 0..nums.len() {
            current_sum += nums[i] as i64;
            current_key = current_sum % p as i64;

            if current_key == 0 {
                best = if best > nums.len() - i - 1 { nums.len() - i - 1 } else { best };
            }

            if remainders.contains_key(&current_key) {
                best = if best > i - remainders.get(&current_key).unwrap() - 1 { i - remainders.get(&current_key).unwrap() - 1 } else { best };
            }
            remainders.insert(current_key, i);
        }

        if current_sum % p as i64 == 0 {
            res = 0;
        }
        else {
            res = best as i32;
        }

        if res == nums.len() as i32 {
            res = -1;
        }

        res 
    }
}

fn main() {
    println!("{}", Solution::min_subarray(vec![4,5,8,5,4], 7));
}