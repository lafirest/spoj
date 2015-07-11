;;;算法很简单,读取所有数据后排序,然后从第一个开始算选出k个后的差,
;;;遍历完整个数组,找出最小的一个差就可以了
;;;common lisp tle,找了份c++代码,算法一样ac了.
;;;lisp代码能优化的地方是:只使用一个数组,不每次重新生成,这样的话需要
;;;自己写一个待范围的sort函数
(declaim (optimize (speed 3)))
(defun chose-min (arr n k)
  (if (= k 1)
    0
    (let ((distance (1- k)))
      (loop with minimum = 1000000000  
            for i from 0 to (- n k)
            do (let ((value (- (aref arr (+ i distance))
                               (aref arr i))))
                 (when (< value minimum)
                   (setf minimum value)))
            finally (return minimum)))))

(loop repeat (read)
      for n = (read)
      for k = (read)
      do(let ((arr (make-array n :element-type 'integer)))
          (loop for i from 0 below n
                do (setf (aref arr i) (read)))
          (format t "~A~%" (chose-min (sort arr #'<) n k))))
