{-
 - 规律: 
 - 1 
 - 7    1 + 6
 - 19   1 + 6 + 12
 - 37   1 + 6 + 12 + 18
 - 所以f(x) = 1 + 6(1 + 2 + 3 + .. + x - 1)
 -          = 1 + 6(n(n - 1) / 2)
 -          = 1 + 3n(n - 1)
 -}
{-# LANGUAGE MultiWayIf #-}
{-# LANGUAGE Strict     #-}
module Main where
import           Data.Int
import           System.IO
import           Text.Printf

main :: IO ()
main = go
    where
        go :: IO ()
        go = do
            n <- readLn :: IO Int64
            if n == -1
                then return ()
                else do
                    check 1 n
                    go

{-      使用 1 + 6 + 12 + 18 ... 公式
        check :: Int64 -> Int64 -> Int64 -> IO ()
        check sum i n =
            if | sum < n -> check (sum + 6 * i) (i + 1) n
               | sum == n -> printf "Y\n"
               | otherwise -> printf "N\n"
-}

        -- 使用化简后的公式
        check :: Int64 -> Int64 -> IO ()
        check i n = do
            let r = 3 * i * (i - 1) + 1
            if |r > n -> printf "N\n"
               |r == n -> printf "Y\n"
               |otherwise -> check (i + 1) n

