;;; 遍历链表,求出左花括号、右花括号的个数
;;; 有四种情况:
;;; 1.只有右括号,}}}},这时结果为(/ racc 2)
;;; 2.只有左括号,}}}},结果为(/ lacc 2)
;;; 3、4:同时保护左括号和有括号,其中}{的操作
;;; 数为0,即从}{变化为{}
;;; 3.左括号数为偶数,由于题目给出的都算平衡表,所以左括号为偶数时,右括号也为偶数,结果为(+ (/ lacc 2) (/ racc 2))
;;; 4.左括号数为基数,此时左右都需要划出一个括号进行匹配,操作数为2,所以结果为
;;; (+ 2 (/ (1- lacc) 2) (/ (1- racc) 2)) -> 
;;;     (+ 2 (/ (- (+ lacc racc) 2) 2)) -> 
;;;         (/ (+ lacc racc) 2) + 1
;;; 1、2、3可以进行合并统一用(+ (/ lacc 2) (/ racc 2)),不过这样结构更清晰些
(defun calc (lst lacc racc)
  (if (endp lst)
    (cond 
      ((zerop lacc)
       (/ racc 2))
      ((zerop racc)
       (/ lacc 2))
      ((evenp lacc)
       (+ (/ lacc 2) (/ racc 2)))
      (t
       (1+ (/ (+ lacc racc) 2))))
    (let ((head (car lst)))
      (if (char= head #\{)
        (calc (cdr lst) (1+ lacc) racc)
        (calc (cdr lst) lacc (1+ racc))))))

;;; 这里使用一个栈,如果{之后匹配到了一个},则将其从栈中移除
;;; 其他情况包括,{{、}}、}{都进行入栈处理.等所有符合都读取
;;; 完后,计算平衡需要的操作次数
(loop for line = (read-line)
      for num = 1 then (incf num)
      until (char= (aref line 0) #\-)
      do(loop with stack = nil
              ;;; 这里是个坑,每行的最后有个回车符,需要去掉
              for i from 0 below (1- (length line))  
              do(let ((v (char line i)))
                  (if (null stack)
                    (push v stack)
                    (if (char= v #\{)
                      (push v stack)
                      (if (char= (car stack) #\{)
                        (pop stack)
                        (push v stack)))))
              finally (return (format t "~A. ~A~%" num (calc stack 0 0)))))

