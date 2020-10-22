dict = [("M",1000),("CM",900),("D",500),("CD",400),("C",100),("XC",90),("L",50),("XL",40),("X",10),("IX",9),("V",5),("IV",4),("I",1)]

second = snd

joinStrs = foldl (\acc x -> acc ++ x) ""

calc 0 acc arr =  return acc
calc n acc (x:xs)= calc (n `mod` (second x)) (acc ++ (joinStrs $ replicate (n `div` (second x)) (fst x))) xs
main = do
    num <- getLine
    let toRoman n = calc n "" dict
    ans <- toRoman (read num)
    putStrLn ans
