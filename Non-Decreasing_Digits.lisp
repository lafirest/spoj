;;; f(n) = 10f(n-1) - sigma(1, n) n belong S(n-1)
;;; 这是一道数学,我只能推出n的求值公式,但是sigma(1,n)没法推出公式,
;;; 所以这儿采取了另外一种方式,算出N的集合中每个元素,然后累加,N中的
;;; 每个集合的推导如下
;;; S[n] = f(n-1), S[n-1] = S[n] - S(n-1)[n] ... S[1] = S[2] - S(n-1)[2]
(defun sum (n)
  (case n
    (1 (values 10 #(0 0 0 0 0 0 0 0 0 0)))  ;;; 1 在这儿只是加速用
    (2 (values 55 #(1 2 3 4 5 6 7 8 9 10))) ;;; 返回n对应的和(也就是下一个序列的最后一个值)和n对应的集合 
    (t
      (let ((acc 0)
            (Sn (make-array 10)))
        (multiple-value-bind (VSn PrvVec) (sum (1- n))
          (incf acc Vsn)
          (setf (aref Sn 9) VSn)
          (loop for i from 8 downto 0
                do(setf (aref Sn i)
                        (- (aref Sn (1+ i))
                           (aref PrvVec (1+ i))))
                do(incf acc (aref Sn i))))
        (values acc Sn)))))

(defun main ()
  (loop repeat (read)
        do (let ((pos (read))
                 (n (read)))
             (format t "~A ~A~%" pos (sum n)))))

(main)

