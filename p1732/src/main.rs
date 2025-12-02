struct Solution;

impl Solution {
    pub fn largest_altitude(gain: Vec<i32>) -> i32 {
        let mut max: i32 = 0;
        let mut alt: i32 = 0;

        for change in gain {
            alt += change;
            if alt > max {
                max = alt;
            }
        }

        max
    }
}

fn main() {
    println!("{:?}", Solution::largest_altitude(vec![-4,-3,-2,-1,4,3,2]));
}