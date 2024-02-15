use std::io::{self, Write};

fn main() {
    loop {
        println!("请选择功能：\n1.摄氏度转换华氏度\n2.华氏度转换摄氏度\n0.退出");

        let mut choice = String::new();
        let mut temp = String::new();

        //  选项读取
        io::stdin().read_line(&mut choice).expect("Read_Error");
        let choice: u8 = match choice.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };
        println!();

        //  非法输入检测
        if choice == 0 {
            break;
        } else if choice != 1 && choice != 2 {
            println!("输入有误");
            continue;
        }

        //  温度读取
        print!("请输入温度值：");
        io::stdout().flush().unwrap();

        io::stdin().read_line(&mut temp).expect("Read_Error");
        let mut temp: f64 = match temp.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };
        println!();

        //  转换
        if choice == 1 {
            temp = 32.0 + temp * 1.8;
        } else if choice == 2 {
            temp = (temp - 32.0) / 1.8;
        }

        //  结果输出
        println!("转换后的温度为：{:1}\n", temp);
    }

    println!("程序已关闭");
}
