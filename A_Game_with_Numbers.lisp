;;; 这道题是查看网上其他解题报告知道怎样做的
;;; 自己用递归的方式来做,可以解出来,但是遇到大
;;; 树会栈溢出
;;; 这一一道博弈论的题目，可以先前面暴力一下，易得小于十的为必胜态，
;;; 十的时候必败，然后11到19又必胜，而且发现只要各位为零且这个数不为零就必败。
;;; 再依次验证上百，上千的数。。
(defun willwin(num)
  (if (and
        (zerop (mod num 10))
        (/= num 0))
    (format t "~A~%" 2)
    (format t "1~%~A~%" (mod num 10))))

(willwin (read))
