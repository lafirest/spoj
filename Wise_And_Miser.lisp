;;;我的第一道动态规划问题
;;;每一步的最有解依赖于上个状态的值
;;;这个程序可以用迭代来做,而不用做成递归,但递归实现更方便理解
;;;这里还有很大的优化空间,同一位置的最优解将被求值多次,第一次求值后
;;;用数组记下来,将可以大幅度优化,不过那样就成了迭代实现了
(declaim (optimize (speed 3) (debug 0)))
(defun calc-min(arr x y l)
  (declare (type fixnum x y l))
  (if (zerop x)
    (aref arr x y)
    (+ (aref arr x y)
       (cond
         ((zerop y)
          (min (calc-min arr (1- x) 0 l)
               (calc-min arr (1- x) 1 l)))
         ((= y l)
          (min (calc-min arr (1- x) l l)
               (calc-min arr (1- x) (1- l) l)))
         (t
          (min
            (calc-min arr (1- x) y l)
            (calc-min arr (1- x) (1+ y) l)
            (calc-min arr (1- x) (1- y) l)))))))

(defun calc-array-min (arr x y)
  (declare (type fixnum x y))
  (apply #'min (loop for p from 0 to y 
                     collect (calc-min arr x p y))))

(defun test()
  (let* ((x (read))
         (y (read))
         (arr (make-array (list x y) 
                          :element-type 'fixnum 
                          :initial-element 0)))
    (declare (type fixnum x y ))
    (loop for x1 from 0 below x
          do (loop for y1 from 0 below y
                   do(setf (aref arr x1 y1) (read))))
    (format t "~A~%" (calc-array-min arr (1- x) (1- y)))))

(test)
