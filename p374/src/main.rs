struct Solution;

fn guess(n: i32) -> i32 {
    return 1;
}

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * unsafe fn guess(num: i32) -> i32 {}
 */
impl Solution {
    unsafe fn guessNumber(n: i32) -> i32 {
        let mut low: i32 = 1;
        let mut high: i32 = n;

        while low != high {
            let target: i32 = low + (high - low) / 2;
            let result: i32 = guess(target);
            if result < 0 {
                high = high - 1;
            }
            else if result > 0 {
                low = target + 1;
            }
            else {
                low = target;
                high = target;
            }
        }

        low
    }
}

fn main() {
    unsafe {
        println!("{:?}", Solution::guessNumber(1));
    }
}