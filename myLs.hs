import System.Process
import System.Posix.Files
import System.Directory
import System.FilePath
import System.FilePath.Posix
import System.Environment
import GHC.IO.Handle.FD
import GHC.IO.Handle
import Data.List
import Control.Exception

check func fp = do
    stat <- getSymbolicLinkStatus fp
    res <- try (evaluate (func stat)) :: IO (Either SomeException (Bool))
    case res of
        Left e -> return False
        Right something -> return something

getAll' func [] = return ()
getAll' func (y:ys) = do
    x <- func y
    hFlush stdout
    case x of
        True -> putStrLn y
        _    -> return ()
    getAll' func ys


main = do
    dir <- getCurrentDirectory
    fp's <- getDirectoryContents $ dir
    str <- (getArgs)
    let fileFunc = getAll' (check (\x ->  not $ isDirectory x))
        dirFunc = getAll' (check (\x ->  isDirectory x))
        fp = sort fp's
    case (str !! 0) of
        "files" -> fileFunc (filter (\x-> (head x) /= '.') fp)
        "dirs" -> dirFunc (filter (\x-> (head x) /= '.') fp)
        "allFiles" -> fileFunc (fp)
        "allDirs" -> dirFunc (fp)
        otherwise -> putStrLn "Invalid Argument"
    return ()
