import Data.List

-- import System.Random

{- Problem 21

>>> insertAt 'X' "abcd" 2
"aXbcd"

 -}
insertAt elem lst ind =
  reverse $
    foldl
      ( \acc (i, x) ->
          if i == ind
            then x : elem : acc
            else x : acc
      )
      []
      (zip [1 ..] lst)

{- problem 22

>>> range 4 9
[4,5,6,7,8,9]

 -}

range l r = [l .. r]

{- problem 23

>>> rnd_select "abcdefgh" 3

-}

-- -- rnd_select :: Show a => [a] -> Int -> [Char]
-- rnd_select x n = do
-- g <- getStdGen
-- return $ take n [x !! i | i <- randomRs (0, (length x) -1) g]
--
--
-- Im skipping the ones that use random numers
--

{-

Problem 26
>>>  combinations' 3 "abcdef"
["abc","abd","abe","abf","acd","ace","acf","ade","adf","aef","bcd","bce","bcf","bde","bdf","bef","cde","cdf","cef","def"]

 -}

-- Nicer solution
combinations' _ [] = [[]]
combinations' 0 _ = [[]]
combinations' n (x : xs) = with_x ++ without_x
  where
    with_x = [x : ys | ys <- combinations' (n - 1) xs]
    without_x = if n <= length xs then combinations' n xs else []

{- Problem 27
 -}

group3 :: Eq a => [Int] -> [a] -> [[[a]]]
-- group3 sizes xs = [xs]
group3 [x, y, z] xs = do
  sz_x <- combinations' x xs
  sz_y <- combinations' y (xs \\ sz_x)
  sz_z <- combinations' z ((xs \\ sz_x) \\ sz_y)
  return [sz_x, sz_y, sz_z]

{-Problem 28

 -}

lsort :: Foldable t => [t a] -> [t a]
lsort = sortBy (\a b -> compare (length a) (length b))

lfsort :: Foldable t => [t a] -> [t a]
lfsort arr = reverse [x | len <- len_arr_uniq, x <- get_all_of_len len]
  where
    len_arr = map length arr
    get_all_of_len n = filter (\x -> length x == n) arr
    len_arr_uniq = (sortBy (flip (\x y -> compare (length (get_all_of_len x)) (length (get_all_of_len y)))) . nub) len_arr
