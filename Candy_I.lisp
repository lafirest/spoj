;;;WRONG:错误
;;;和C++代码一样,但是不能Acc.
(defun calc-move-times (numlist sum x)
  (let ((avg (/ sum  x)))
    (loop for e in numlist
          if (< e avg)
          count (- avg e) into move
          finally (return move))))

(loop for x = (read) 
      until (= -1 x)
      do(let* ((numlist (loop for y from 1 to x
                         collect (read) into numlist
                        finally (return numlist)))
               (sum (apply #'+ numlist)))
          (if (zerop (rem sum x))
            (format t "~A~%" (calc-move-times numlist sum x))
            (format t "-1~%"))))

