;;; 等比数列的应用
;;; 使用快速求幂算法,速度能提高更多(但也可能sbcl的expt就是这么实现的)
;;; blog.jobbole.com/74468/
(defmacro sum (a1 q n)
  `(/ (* ,a1 (- 1 (expt ,q ,n))) (- 1 ,q)))

(defun main ()
  (loop
    for n of-type (unsigned-byte 32) = (read)
    for l of-type (unsigned-byte 32) = (read)
    until(= 0 n l)
    do(let ((s (sum n n l)))
        (format t "~a~%" (mod s 1000000007)))))

(main)
