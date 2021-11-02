-- https://wiki.haskell.org/99_questions/1_to_10
import Data.List
{- Problem  1
>>> myLast [1,2,3,4]
Just 4

>>> myLast [1,2,3,5,6 ]
Just 6

 -}
import Distribution.Types.TestSuiteInterface (TestSuiteInterface)

myLast :: [p] -> Maybe p
myLast [] = Nothing
myLast [x] = Just x
myLast (x : xs) = myLast xs

{- Problem 2
>>> myButLast ['a'..'z']
Just 'y'

>>> myButLast [1,2,3,4]
Just 3

-}

myButLast [] = Nothing
myButLast [x, y] = Just x
myButLast (x : xs) = myButLast xs

{-Problem 3

>>> elementAt [1,2,3] 2
Just 2

-}

elementAt :: (Eq t, Num t) => [a] -> t -> Maybe a
elementAt [] _ = Nothing
elementAt (x : xs) 1 = Just x
elementAt (x : xs) k = elementAt xs (k -1)

{- Problem 4

>>> myLength [1,2,3]
3

 -}

myLength xs = foldr (\x -> (+) 1) 0 xs

{- Problem 5

>>> myReverse [1,2,3,4]
[4,3,2,1]

 -}

myReverse = reverse

{- P6

>>> isPallindrome [1,2,3,2,1]
True

 -}

isPallindrome lst = lst == reverse lst

{- Problem 7

>>> myFlatten (Elem 5)
[5]

>>> myFlatten (List [Elem 1, List [Elem 2, List [Elem 3, Elem 4], Elem 5]])
[1,2,3,4,5]

>>> myFlatten (List [])
[]

 -}

data NestedList a = Elem a | List [NestedList a]

myFlatten :: NestedList a -> [a]
myFlatten (Elem a) = [a]
myFlatten (List []) = []
myFlatten (List x) = concatMap myFlatten x

{- Problem 8

>>> compress "aaaabccaadeeee"

 -}

compress lst = reverse $ foldl (\acc (x, x') -> if x == x' then acc else x' : acc) [(head lst)] input
  where
    input = zip lst (tail lst)

{- Problem 9

>>> pack ['a', 'a', 'a', 'a', 'b', 'c', 'c', 'a', 'a', 'd', 'e', 'e', 'e', 'e']
["aaaa","b","cc","aa","d","eeee"]

 -}

pack lst =
  reverse $
    foldl
      ( \acc (x, x') ->
          if x == x'
            then ((x' : head acc) : tail acc)
            else ([x'] : acc)
      )
      [[head lst]]
      input
  where
    input = zip lst (tail lst)

{- Problem 10

>>> encode "aaaabccaadeeee"
[(4,'a'),(1,'b'),(2,'c'),(2,'a'),(1,'d'),(4,'e')]

-}
encode lst = map (\x -> (length x, head x)) (pack lst)
