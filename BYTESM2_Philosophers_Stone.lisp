;;;TLE...
;;;这是一个DP问题,直观的解法就是从最后一行开始倒推出最优解
;;;但是这样效率低,很对位置上的值被反复计算了
(declaim (optimize (speed 3) (debug 0) (safety 0)))
(defun calc-max (arr x y r)
  (+ (aref arr x y)
     (cond
       ((zerop x)
        0)
       ((zerop y)
        (max 
          (calc-max arr (1- x) (1+ y) r)
          (calc-max arr (1- x) y r)))
       ((= y r)
        (max 
          (calc-max arr (1- x) (1- y) r)
          (calc-max arr (1- x) y r)))
       (t
        (max
          (calc-max arr (1- x) (1- y) r)
          (calc-max arr (1- x) (1+ y) r)
          (calc-max arr (1- x) y r))))))

(defun get-max (arr c r)
  (loop with maxv = 0
        for x from 0 to r
        do (let ((cxValue (calc-max arr c x r)))
             (when (> cxValue maxv)
               (setf maxv cxValue)))
        finally (return maxv)))

(dotimes (x (read))
  (let* ((c (read))
         (r (read))
         (arr (make-array (list c r) :element-type 'integer)))
    (loop for x from 0 below c
          do (loop for y from 0 below r
                   do(setf (aref arr x y) (read))))
    (format t "~A~%" (get-max arr (1- c) (1- r)))))
