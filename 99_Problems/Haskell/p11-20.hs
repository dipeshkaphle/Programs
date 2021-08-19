{- Problem 11

>>> encodeModified "aaaabccaadeeee"
[Multiple 4 'a',Single 'b',Multiple 2 'c',Multiple 2 'a',Single 'd',Multiple 4 'e']

 -}

import Data.Sequence (mapWithIndex)

data Occ a b = Single b | Multiple a b deriving (Show)

groupSameTogether lst =
  reverse $
    foldl
      ( \acc (x, x') ->
          if x == x'
            then (x' : head acc) : tail acc
            else [x'] : acc
      )
      [[head lst]]
      input
  where
    input = zip lst (tail lst)

encodeModified lst =
  map
    ( \x ->
        if length x == 1
          then Single (head x)
          else Multiple (length x) (head x)
    )
    (groupSameTogether lst)

{- Problem 12

>>> decodeModified [Multiple 4 'a', Single 'b', Multiple 4 'c']
"aaaabcccc"

 -}

f (Single c) = [c]
f (Multiple n c) = replicate n c

decodeModified [] = []
decodeModified (x : xs) =
  let new_x = f x
      new_xs = decodeModified xs
   in new_x ++ new_xs

{- Problem 13

>>> encodeDirect "aaaabccaadeeee"
[Multiple 4 'a',Single 'b',Multiple 2 'c',Multiple 2 'a',Single 'd',Multiple 4 'e']

 -}

encodeDirect s = reverse $ encodeDirect' s [] '@'

encodeDirect' [] acc _ = acc
encodeDirect' (x : xs) acc last_c =
  if last_c == x
    then
      ( case head acc of
          Single c -> encodeDirect' xs (Multiple 2 c : tail acc) x
          Multiple y c -> encodeDirect' xs (Multiple (y + 1) c : tail acc) x
      )
    else encodeDirect' xs (Single x : acc) x

{- Problem  14

>>> dupli [1,2,3]
[1,1,2,2,3,3]

 -}

dupli :: [b] -> [b]
dupli = concatMap (replicate 2)

{- Problem 15

>>> repli "abc" 3
"aaabbbccc"

 -}

repli lst n = concatMap (replicate n) lst

{- Problem 16

>>> dropEvery "abcdefghik" 3

 -}

dropEvery s n =
  reverse $
    foldl
      ( \acc (i, x) ->
          if mod i n == 0
            then acc
            else x : acc
      )
      []
      (zip [1 ..] s)

{- Probblem 17

>>>  split "abcdefg" 3

 -}

split lst n = let (l, r) = g lst n in (reverse l, reverse r)

g lst n =
  foldl
    ( \(l, r) (i, x) ->
        if i > n
          then (l, x : r)
          else (x : l, r)
    )
    ([], [])
    (zip [1 ..] lst)

{- Problem 18

 -}

slice lst l r =
  reverse $
    foldl
      ( \acc (i, x) ->
          if (i >= l) && (i <= r)
            then x : acc
            else acc
      )
      []
      (zip [1 ..] lst)

{-
 -
 -}
