;;;完全不懂欧拉函数,公式从网上找的
;;;lisp版本会超时,c版本能ac
(defun euler (num)
  (let ((res num))
    (loop for x from 2 below (1+ (floor (sqrt num)))
          when (zerop (rem num x))
          do (progn
               (setf res (* (/ res  x) (1- x)))
               (loop while (zerop (rem num x))
                     do (setf num (floor (/ num x))))))
    (if (> num 1)
      (floor (* (/ res num) (1- num)))
      res)))

(dotimes (x (read))
  (format t "~A~%" (euler (read))))
