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
