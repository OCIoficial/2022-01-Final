use std::{
    env,
    error::Error,
    fs::File,
    io::{BufRead, BufReader},
};

#[derive(Eq, PartialEq)]
enum Ans {
    Failed,
    Success(Vec<usize>),
    Err,
}

impl Ans {
    fn read<R: BufRead>(mut buf: R) -> Ans {
        let mut line = String::new();
        if let Err(_) = buf.read_line(&mut line) {
            return Ans::Err;
        }
        if line.trim() == "FALLIDA" {
            return Ans::Failed;
        }
        if let Ok(vec) = line.split_whitespace().map(|x| x.parse()).collect() {
            Ans::Success(vec)
        } else {
            Ans::Err
        }
    }
}

fn check(sol: Vec<usize>, mut v: i32, power: Vec<i32>) -> bool {
    if sol.len() != power.len() {
        return false;
    }

    for i in sol {
        let i = i - 1;
        if i > power.len() || power[i] > v {
            return false;
        }
        v += 1;
    }
    return true;
}

fn read_ints<R: BufRead>(mut buf: R) -> Vec<i32> {
    let mut line = String::new();
    buf.read_line(&mut line).unwrap();
    line.split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect()
}

fn main() -> Result<(), Box<dyn Error>> {
    let args: Vec<String> = env::args().collect();

    let mut fin = BufReader::new(File::open(&args[1])?);
    let fcorrect = BufReader::new(File::open(&args[2])?);
    let fans = BufReader::new(File::open(&args[2])?);

    let nv = read_ints(&mut fin);
    let _n = nv[0];
    let v = nv[1];
    let power = read_ints(&mut fin);

    let correct = Ans::read(fcorrect);
    let ans = Ans::read(fans);

    if correct == Ans::Failed {
        if ans == Ans::Failed {
            println!("1.0");
        } else {
            println!("0.0");
        }
    } else {
        if let Ans::Success(vec) = ans {
            println!("{}", if check(vec, v, power) { "1.0" } else { "0.0" });
        } else {
            println!("0.0");
        }
    }

    Ok(())
}
