fn main() {
    for n in 1..101 {
        match n {
            n if n % 15 == 0 => println!("FizzBuzz"),
            n if n % 5 == 0 => println!("Buzz"),
            n if n % 3 == 0 => println!("Fizz"),
            _ => println!("{0}", n),
        }
    }
}
