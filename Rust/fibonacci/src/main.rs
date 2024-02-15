use std::io;

fn main() {
    println!("您想查看第几个斐波那契数？");

    //  读入 n
    let mut n = String::new();
    io::stdin().read_line(&mut n).expect("Read Error");
    let n: usize = match n.trim().parse() {
        Ok(num) => num,
        Err(_) => {
            println!("程序错误");
            0
        }
    } - 1;

    //  计算
    let mut num: Vec<usize> = vec![1, 1];
    let mut count: usize = 1;
    while count < n {
        let next = num[count - 1] + num[count];
        num.push(next);
        count += 1;
    }

    //  结果
    println!("第{}个斐波那契数是{}", n + 1, num[n]);
}
