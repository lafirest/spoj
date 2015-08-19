;;; 很简单的二分搜索,但一直超时,使用了各种优化方法,最后还是tle,改用c实现了
(declaim (optimize (speed 2)))
(defvar *max* 1000000)
(defvar trees (make-array *max* :element-type '(unsigned-byte 32) :initial-element 0))

(defun main ()
  (let ((n (read))
        (m (read))
        (left 0)
        (right 0))
    (declare ((unsigned-byte 32) n m left right))

    (loop
      for i from 0 below n
      do(let ((v (read)))
          (declare ((unsigned-byte 32) v))
          (setf (aref trees i) v)))

    (sb-impl::sort-vector trees 0 n #'> nil)
    (setf left (aref trees (1- n)))
    (setf right (aref trees 0))

    (loop
      while(< left right)
      for mid = (floor (+ left right) 2)
      do(let ((smallp nil))
          (declare ((unsigned-byte 32) mid))
          (loop
            with acc = 0
            for i from 0 below n
            do(let ((len (aref trees i)))
                (when (<= len mid)
                  (loop-finish))

                (incf acc (- len mid))
                (when (>= acc m)
                  (setf smallp t)
                  (loop-finish))))
          (if smallp
            (setf left (1+ mid))
            (setf right mid)))
      finally (format t "~a~%" (1- left)))))

(main)
