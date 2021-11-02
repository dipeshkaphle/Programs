isPrime :: Int -> Bool
isPrime n = not (any (\x -> n `mod` x == 0) [2 .. (n - 1)])

myGcd x y = if x == 0 then y else gcd y (x `mod` y)

coprime x y = gcd x y == 1

totient n = length [x | x <- [1 .. (n - 1)], coprime x n]
