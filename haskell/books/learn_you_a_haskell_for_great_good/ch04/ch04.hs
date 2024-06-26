lucky :: (Integral a) => a -> String
lucky 7 = "LUCKY NUMBER 7!"
lucky x = "Sorry, you're out of luck, pal!"

sayMe :: (Integral a) => a -> String
sayMe 1 = "One!"
sayMe 2 = "Two!"
sayMe 3 = "Three!"
sayMe 4 = "Four!"
sayMe 5 = "Five!"
sayMe x = "Not between 1 and 5"

factorial :: (Integral a) => a -> a
factorial 0 = 1
factorial n = n * factorial (n - 1)

-- Intentionally non-exhaustive!
charName :: Char -> String
charName 'a' = "Albert"
charName 'b' = "Broseph"
charName 'c' = "Cecil"

-- Initial implementation (note the number of function calls):
-- addVectors :: (Num a) => (a, a) -> (a, a) -> (a, a)
-- addVectors a b = (fst a + fst b, snd a + snd b)

-- Fewer function calls using pattern matching (succinct!):
addVectors :: (Num a) => (a, a) -> (a, a) -> (a, a)
addVectors (x1, y1) (x2, y2) = (x1 + x2, y1 + y2)

-- Homebrew implementations of fst and snd:
first :: (a, b, c) -> a
first (x, _, _) = x

second :: (a, b, c) -> b
second (_, y, _) = y

-- Extract the third value from our tuple:
third :: (a, b, c) -> c
third (_, _, z) = z

-- Homebrew implementaion of head:
head' :: [a] -> a
head' [] = error "Can't call head on an empty list, dummy!"
head' (a : _) = a

tell :: (Show a) => [a] -> String
tell [] = "The list is empty!"
tell [x] = "The list has one element: " ++ show x
tell [x, y] =
  "The list has two elements: " ++ show x ++ " and " ++ show y
tell (x : y : _) =
  "This list is long. The first two elements are: "
    ++ show x
    ++ " and "
    ++ show y

length' :: (Num b) => [a] -> b
length' [] = 0
length' (_ : xs) = 1 + length' xs

{- HLINT ignore "Use foldr" -}
sum' :: (Num a) => [a] -> a
sum' [] = 0
sum' (x : xs) = x + sum' xs

capital :: String -> String
capital "" = "Empty string, whoops!"
capital all@(x : xs) = "The first letter of " ++ all ++ " is " ++ [x]

basicBmiTell :: (RealFloat a) => a -> String
basicBmiTell bmi
  | bmi <= 18.5 = "You're underweight, you emo, you!"
  | bmi <= 25.0 = "You're supposedly normal. Pffft, I bet you're ugly!"
  | bmi <= 30.0 = "You're fat! Lose some weight, fatty!"
  | otherwise = "You're a whale, congratulations!"

ryBmiTell :: (RealFloat a) => a -> a -> String
ryBmiTell weight height
  | weight / height ^ 2 <= 18.5 =
      "You're underweight, you emo, you!"
  | weight / height ^ 2 <= 25.0 =
      "You're supposedly normal. Pffft, I bet you're ugly!"
  | weight / height ^ 2 <= 30.0 =
      "You're fat! Lose some weight, fatty!"
  | otherwise =
      "You're a whale, congratulations!"

max' :: (Ord a) => a -> a -> a
max' a b
  | a > b = a
  | otherwise = b

myCompare :: (Ord a) => a -> a -> Ordering
myCompare a b
  | a > b = GT
  | a == b = EQ
  | otherwise = LT

dryBmiTell :: (RealFloat a) => a -> a -> String
dryBmiTell weight height
  | bmi <= 18.5 = "You're underweight, you emo, you!"
  | bmi <= 25.0 = "You're supposedly normal. Pffft, I bet you're ugly!"
  | bmi <= 30.0 = "You're fat! Lose some weight, fatty!"
  | otherwise = "You're a whale, congratulations!"
  where
    bmi = weight / height ^ 2

superDryBmiTell :: (RealFloat a) => a -> a -> String
superDryBmiTell weight height
  | bmi <= skinny = "You're underweight, you emo, you!"
  | bmi <= normal = "You're supposedly normal. Pffft, I bet you're ugly!"
  | bmi <= fat = "You're fat! Lose some weight, fatty!"
  | otherwise = "You're a whale, congratulations!"
  where
    bmi = weight / height ^ 2
    skinny = 18.5
    normal = 25.0
    fat = 30.0

-- Pattern matching:
-- (skinny, normal, fat) = (18.5, 25.0, 30.0)

initials :: String -> String -> String
initials firstname lastname = [f] ++ ". " ++ [l] ++ "."
  where
    (f : _) = firstname
    (l : _) = lastname

calcBmis :: (RealFloat a) => [(a, a)] -> [a]
calcBmis xs = [bmi w h | (w, h) <- xs]
  where
    bmi weight height = weight / height ^ 2

cylinder :: (RealFloat a) => a -> a -> a
cylinder r h =
  let sideArea = 2 * pi * r * h
      topArea = pi * r ^ 2
   in sideArea + 2 * topArea

caseHead :: [a] -> a
caseHead xs = case xs of
  [] -> error "No head for empty lists!"
  (x : _) -> x

describeList :: [a] -> String
describeList xs =
  "The list is " ++ case xs of
    [] -> "empty."
    [x] -> "a singleton list."
    xs -> "a longer list."

describeList' :: [a] -> String
describeList' xs = "The empty list is " ++ what xs
  where
    what [] = "empty."
    what [x] = "a singleton list."
    what xs = "a longer list."
