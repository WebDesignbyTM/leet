struct Solution;

const MAX_POS: usize = 100001;

impl Solution {
    pub fn daily_temperatures(temperatures: Vec<i32>) -> Vec<i32> {
        let mut res: Vec<usize> = Vec::new();
        let mut relevant_tmps: Vec<(i32, usize)> = Vec::new();
        let mut final_res: Vec<i32> = Vec::new();

        relevant_tmps.push((temperatures[temperatures.len()-1], temperatures.len() - 1));
        res.push(MAX_POS);

        for i in (0..temperatures.len()-1).rev() {
            for j in (0..relevant_tmps.len()).rev() {
                if temperatures[i] < relevant_tmps[j].0 {
                    res.push(relevant_tmps[j].1 - i);
                    relevant_tmps.push((temperatures[i], i));
                    break;
                }
                else {
                    relevant_tmps.remove(j);
                }
            }

            if relevant_tmps.len() == 0 {
                relevant_tmps.push((temperatures[i], i));
                res.push(MAX_POS);
            }
        }

        for e in &mut res {
            if *e == MAX_POS {
                *e = 0;
            }
        }

        for i in (0..res.len()).rev() {
            final_res.push(res[i] as i32);
        }

        final_res
    }
}

fn main() {
    println!("{:?}", Solution::daily_temperatures(vec![73,74,75,71,69,72,76,73]));
}