getIntList :: IO [Int]
getIntList = map read . words <$> getLine

main:: IO ()
main = do 
    n <- readLn :: IO Int
    vs <- getIntList
    cs <- getIntList

    let ans = sum . filter (> 0) $ zipWith (-) vs cs
    print ans 