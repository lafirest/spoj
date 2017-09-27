{-
 - 这是一道找规律的题,然后网上有用递归或则动态规划的,都把问题搞复杂了
 - 规律: n 
 - 偶数: n(n + 2)(2n + 1) / 8
 - 基数: (n(n + 2)(2n + 1) - 1) / 8
 - 然后可以利于div的性质合并成第一个公式
 -}
{-# LANGUAGE Strict #-}
module Main where
import System.IO
import Data.Int

main :: IO ()
main = do
    count <- readLn :: IO Int16
    go count
    where 
        go :: Int16 -> IO ()
        go 0 = return ()
        go n = do
            level <- readLn :: IO Int64
            print $ div (level * (level + 2) * (2 * level + 1)) 8
            go $ n - 1

