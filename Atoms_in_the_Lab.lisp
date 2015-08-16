;;; 很简单的一道题,直接使用公式判断即可
(setf *read-default-float-format* 'double-float)

(defun main ()
  (let ((p (read)))
    (declare ((unsigned-byte 16) p))
    (loop
      repeat p
      do(let ((n (read))
              (k (read))
              (m (read)))
          (declare ((unsigned-byte 64) n k m))
          (if (>= n m)
            (format t "0~%")
            (let ((x (log (/ m n) k)))
              (format t "~a~%" (floor x))))))))

(main)
