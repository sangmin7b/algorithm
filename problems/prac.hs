import Control.Arrow
main :: IO ()
main = interact process
process :: String -> String 
process = 
  lines 
    >>> drop 1
    >>> map words
    >>> map (map read)
    >>> solve
    >>> show

solve :: [[Int]] -> Int
solve [vs, cs] = sum . filter (> 0) $ zipWith (-) vs cs  