;;; 简单的博弈游戏
;;; 根据规则被迫选择1的将输掉游戏.然后Suresh先手,Ramesh后手
;;; 列出Suresh的状态列表,
;;; 当最后选择的数字为:     获胜者为:
;;; 1 R
;;; 2 S
;;; 3 R ...
;;; 可以发现如果最后Suresh选择的数字为偶数,则他获胜,如果为奇数Ramesh获胜
;;; Suresh先手,且会选择最优的,所以当两个数字中有一个偶数时,他获胜,否则反之
(loop 
    repeat (read)
    do(let ((c1 (read))
            (c2 (read)))
        (format t "~a~%"
            (if (or 
                    (evenp c1)
                    (evenp c2))
                "Suresh"
                "Ramesh"))))
