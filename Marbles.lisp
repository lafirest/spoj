;;;WRONG:超时,同样的算法用C++ AC了.
;;;公式就是排列组合的:C(n,k) = n! / k!(n-k)!
;;;因为要去掉重复的倍数,所以还需要C/(n/k) = (n-1)! / (k-1)!(n-k)!
;;;第一版是按照阶乘和排列公式使用递归求解,然后运行时错误,应该是栈空间不够
;;;这一版使用迭代代替递归,虽然超时了,但是思路是对的
(defun main()
  (declare (optimize (speed 3) (safety 0) (debug 0)))
  (dotimes (x (read))
    (let ((n1 (read))
          (k1 (read)))
      (format t "~A~%" 
              (let ((n (1- n1))
                    (k (1- k1)))
                (loop for x from 0 below k
                      with r = 1
                      do (setf r (* r (/ (- n x) (- k x))))
                      finally (return r)))))))

