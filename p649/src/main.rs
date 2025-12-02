use std::collections::VecDeque;

struct Solution;

impl Solution {
    pub fn predict_party_victory(senate: String) -> String {
        let mut dire: VecDeque<usize> = VecDeque::new();
        let mut dire_senator: usize;
        let mut radiant: VecDeque<usize> = VecDeque::new();
        let mut radiant_senator: usize;
        let mut idx: usize = 0;

        for c in senate.chars() {
            if c == 'R' {
                radiant.push_back(idx);
            }
            else {
                dire.push_back(idx);
            }
            idx += 1;
        }

        while dire.len() != 0 && radiant.len() != 0 {
            dire_senator = dire.pop_front().unwrap();
            radiant_senator = radiant.pop_front().unwrap();

            if dire_senator < radiant_senator {
                dire.push_back(idx);
            }
            else {
                radiant.push_back(idx);
            }

            idx += 1;
        }

        if radiant.len() != 0 {
            String::from("Radiant")
        }
        else {
            String::from("Dire")
        }
    }
}

fn main() {
    println!("{:?}", Solution::predict_party_victory(String::from("RDD")));
}