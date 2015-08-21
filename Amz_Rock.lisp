;;; 没太明白题目意思,但是评论都说斐波拉契数列,就按斐波拉契来做了
;;; 我自己列举的数据实际上和这个数列对不上
(defun main ()
  (let ((ti (read))
        (fib (make-array 45 :element-type '(unsigned-byte 32) :initial-element 0)))
    (declare ((unsigned-byte 32) ti))
    (setf (aref fib 0) 1)
    (setf (aref fib 1) 2)
    (loop
      for i from 2 to 43 
      do(setf (aref fib i)
              (+
                (aref fib (1- i))
                (aref fib (- i 2)))))
    (loop
      repeat ti
      do(format t "~a~%" (aref fib (read))))))

(main)

