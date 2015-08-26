;;;寻找最小旋转角度 * 旋转1度需要的时间
;;;对角度排序.如果以最小的角度为起点,最大的角度为终点,二者的差为可能解之一
;;;从第2个点开始,依次选为起点,因为是一个圆,所以前一个点就是终点,经过一轮比较
;;;后选出的最小角度就是解了.至于为什么乘以12,因为:旋转1圈要72分,即1分钟5度,
;;;1度12秒
(defvar arr (make-array 1010 :element-type 'float :initial-element 0.0))

(defun main ()
  (loop
    repeat (read)
    do(let ((n (read))
            (minv 999.0))
        (declare ((unsigned-byte 16) n))
        (loop
          for i from 0 below n
          do(read)
          do(setf (aref arr i) (read)))
        (sb-impl::sort-vector arr 0 n #'<  nil)
        (setf minv (- (aref arr (1- n)) (aref arr 0)))
        (loop 
          for i from 1 below n
          for j from 0 below (1- n) 
          do(let ((tv (+ (- 360 (aref arr i)) (aref arr j))))
              (when (< tv minv)
                (setf minv tv))))
        (format t "~a~%" (ceiling (* 12 minv))))))

(main)
