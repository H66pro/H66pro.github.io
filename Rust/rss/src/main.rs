use colored::*;
use std::time::Instant;

fn main() {
    let start_time = Instant::now();

    let s = String::from("hello world");
    let fs = first_word(&s);

    println!("first word: {}", fs.green());

    let elapsed_time = start_time.elapsed();
    println!("Running time: > {:?}", elapsed_time);
}

fn first_word(s: &String) -> String {
    let mut s1 = s.clone();
    let mut n = 0;
    for (i, item) in s1.chars().enumerate() {
        // println!("{}", item);
        if item == ' ' {
            n = i;
            break;
        }
    }

    while s1.len() != n {
        s1.pop();
    }

    s1
}
