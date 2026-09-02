fn main() {
    let tests = vec![
        vec![-2,1,-3,4,-1,2,1,-5,4],
        vec![1],
        vec![5,4,-1,7,8],
    ];

    for test in tests {
        let result = max_sub_array(test.clone());
        println!("The maximum subarray sum of {:?} is {}", test, result);
    }
}

fn max_sub_array(nums: Vec<i32>) -> i32 {
    let mut max_sum = nums[0];
    let mut current_sum = nums[0];

    for &num in nums.iter().skip(1) {
        current_sum = current_sum.max(current_sum + num);
        max_sum = max_sum.max(current_sum);
    }

    max_sum
}