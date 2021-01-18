extern crate reqwest;

use std::fs::File;
use std::io::{self, BufRead, Write};
use std::thread;

fn getfilecontent(filename: &String) -> io::Result<Vec<String>> {
    let file = File::open(filename).expect("Failed To open file");
    let mut links = vec![];
    for line in io::BufReader::new(file).lines() {
        if let Ok(l) = line {
            links.push(l);
        }
    }
    Ok(links)
}

fn download(link: String) -> io::Result<()> {
    let substr = "kvi/";
    let filename = &link[(link.find(substr).expect("substr not found") + substr.len())..];
    println!("{}", filename);
    let content =
        reqwest::blocking::get(reqwest::Url::parse(&link[..]).unwrap()).expect("Error ffs");
    let contents = content.bytes().expect("Failed to convert to bytes");
    let mut file =
        File::create(filename).expect(&format!("Failed to create file {}", filename)[..]);
    file.write_all(&contents).expect("Failed");
    println!("{} downloaded", filename);
    Ok(())
}

fn input(prompt: &str) -> io::Result<String> {
    print!("{}", prompt);

    io::stdout().flush()?;
    let mut buf = String::from("");
    io::stdin().read_line(&mut buf)?;
    Ok(buf.trim().to_owned())
}

fn main() {
    let filename =
        input("Give the name of the file which has all the links: ").expect("Taking Input Failed");
    let links = getfilecontent(&filename).expect("Function call failed");
    let mut threads = vec![];
    for link in links.clone() {
        let a = thread::spawn(move || download(link.clone()).unwrap());
        threads.push(a);
    }

    for t in threads {
        t.join().unwrap();
    }
}
