;;;超时
(declaim (optimize (speed 3)))
(defun gen-array (left right)
  (declare (type integer left right))
  (let ((num (1+ (- right left)))) 
    (make-array num :element-type 'boolean 
                :initial-element t)))

(defun sieve (left right)
  (declare (type integer left right))
  (let ((arr (gen-array left right)))
    (loop for i = 2 then (incf i)
          while (<= (* i i) right)
          do(let* ((less (* (floor (/ left i)) i)))
              (loop for j = less then (incf j i)
                    while(<= j right)
                    when (and (/= j i)
                              (>= j left))
                    do(progn
                        (setf (aref arr (- j left)) nil)))))
    (loop for x from 0 below (1+ (- right left)) 
          when(and (aref arr x)
                   (/= (+ left x) 1))
          do(format t "~A~%" (+ left x)))))

(dotimes (_ (read))
  (sieve (read) (read))
  (format t "~%"))
