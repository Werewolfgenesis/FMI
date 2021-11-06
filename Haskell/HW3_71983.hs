data BTree a = Empty | Node a (BTree a) (BTree a)
t1 :: BTree Char
t1 = Node 'a' (Node 'c' (Node 'f' Empty Empty) (Node 'd' Empty Empty)) 
              (Node 'b' Empty (Node 'e' Empty Empty))
t2 :: BTree Char 
t2 = Node 'a' (Node 'c' (Node 'd' Empty Empty) Empty) 
              (Node 'b' Empty Empty)
t5 :: BTree Int
t5 = Node 8 (Node 3 (Node 1 Empty Empty) (Node 4 Empty Empty))
            (Node 10 (Node 9 Empty Empty) (Node 14 Empty Empty))
t6 :: BTree Int
t6 = Node 8 (Node 3 (Node 1 Empty Empty) (Node 4 Empty Empty))
            (Node 10 (Node 5 Empty Empty) (Node 14 Empty Empty))

--Task 1
--Pattern matching solution
containsWord::BTree Char -> String ->  Bool
containsWord Empty _ = False
containsWord (Node n Empty Empty) (x:xs) = if(n == x) then containsWord Empty xs 
containsWord (Node n leftT Empty) word = if((elem word (genWords leftT)) == True) then False 
else True
containsWord (Node n Empty rightT) word = if((elem word (genWords rightT)) == True) then False
else True
containsWord (Node n leftT rightT) word = if((elem word (genWords leftT ++ genWords rightT)) == True) then False 
else True --func to check if the list of words of the tree contains a given word


--Task 2 
--Pattern matching solution
genWords::BTree Char ->[String]
genWords Empty = []
genWords (Node n leftT rightT) = createList (Node n leftT rightT) ++ genWords leftT ++ genWords rightT
            where
                createList Empty = []
                createList (Node n Empty Empty) = [[n]]
                createList (Node n leftT Empty) = map (n:) (createList leftT)
                createList (Node n Empty rightT) = map (n:) (createList rightT)
                createList (Node n leftT rightT) = map (n:) (createList leftT ++ createList rightT) --create list of elements of the tree

--Task 3
--Pattern matching solution
allContain::[BTree Char] -> [String]
allContain [] = []
allContain list = createList generateList (head generateList)
              where
                generateList = map genWords list--func to generate a list from the initial one
                intersectionList list1 list2 = [y | y <- list1, x <- list2, y == x]--func to find the intersection set of two lists
                createList [] string = string
                createList (p:ps) string = createList ps (intersectionList p string)--func to create list of all words containing a string

--Task 5
--Pattern matching solution
isBinarySearchTree::BTree Int ->Bool
isBinarySearchTree Empty = True
isBinarySearchTree (Node n Empty Empty) = True
isBinarySearchTree (Node n Empty rightT) = (isBigger (generateElems rightT) n) && 
                                            isBinarySearchTree rightT
isBinarySearchTree (Node n leftT Empty) = (isSmaller (generateElems leftT) n) && 
                                            isBinarySearchTree leftT
isBinarySearchTree (Node n leftT rightT) = (isSmaller (generateElems leftT) n) && 
                                            (isBigger (generateElems rightT) n) && 
                                            isBinarySearchTree rightT && 
                                            isBinarySearchTree leftT

generateElems::BTree Int->[Int] --func to generate all the elems of the tree
generateElems Empty = []
generateElems (Node n Empty Empty) = [n]
generateElems (Node n leftT Empty) = n:generateElems leftT
generateElems (Node n Empty rightT) = n:generateElems rightT
generateElems (Node n leftT rightT) = n:(generateElems leftT ++ generateElems leftT)

isSmaller::[Int] -> Int ->Bool --func to check if a list of elems is smaller than element
isSmaller [] _ = True
isSmaller xs compareVar = filter (<compareVar) xs == xs

isBigger::[Int]->Int->Bool--func to check if a list of elems is bigger that element
isBigger [] _ = True
isBigger xs compareVar = filter (>=compareVar) xs == xs

main::IO()
main = do print (genWords t1)
          print (containsWord t1 "af")
          print (containsWord t1 "acd")
          print (allContain [t1,t2])
          print (isBinarySearchTree t5)
          print (isBinarySearchTree t6)