;这个会tle,估计是因为y到后面变成大数了
(declaim (optimize (speed 2)))
(defvar arr (make-array 1000001 :element-type '(unsigned-byte 64) :initial-element 0))

(defun main ()
  (setf (aref arr 1) 1)
  (loop
     with acc = 1
     with y = 3
     with z = 3
     for i from 2 to 1000000
     do(progn
         (incf acc (* y y))
         (when (>= acc 1000000003)
           (setf acc (mod acc 1000000003)))
         (setf (aref arr i) acc)
         (incf y z)
         (incf z)))
  (loop repeat (read)
     do(let ((n (read)))
         (declare ((unsigned-byte 32) n))
         (format t "~A~%" (aref arr n)))))
         

(main)
