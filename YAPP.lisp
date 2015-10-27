;;; 不知道题目是什么意思,github上的代码是求2的幂,就这样写了.不能直接用expt,
;;; 因为n的值可能非常大,这里用的是递归求幂,实际上用迭代更好
(defun pow (n)
  (if (zerop n)
    1
    (let* ((rs (pow (floor n 2)))
           (r (* rs rs (if (oddp n) 2 1))))
      (if (>= r 1000000007)
        (mod r 1000000007)
        r))))

(defun main ()
  (let ((c (read)))
    (loop
      repeat c
      do(let ((n (read)))
          (format t "~a~%" (pow (1- n)))))))
(main)
