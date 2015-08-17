;;; 简单的dp
(defvar inf #X7FFF)
(defvar dp (make-array '(22 5) :element-type '(unsigned-byte 16) :initial-element inf))

(defun main ()
  (let ((ti (read)))
    (declare ((unsigned-byte 8) ti))
    (loop
      repeat ti
      do(let ((n (read)))
          (declare ((unsigned-byte 8) n))
          (loop
            for i from 1 to n
            do(loop
                for j from 1 to 3
                do(setf (aref dp i j) (read))))
          (loop
            for i from 2 to n
            do(incf (aref dp i 1) 
                    (min 
                      (aref dp (1- i) 2) 
                      (aref dp (1- i) 3))) 
            do(incf (aref dp i 2)
                    (min
                      (aref dp (1- i) 1)
                      (aref dp (1- i) 3)))
            do(incf (aref dp i 3) 
                    (min 
                      (aref dp (1- i) 1)
                      (aref dp (1- i) 2))))
          (loop
            with minv = inf
            for i from 1 to 3
            when (< (aref dp n i) minv)
            do(setf minv (aref dp n i))
            finally (format t "~a~%" minv))))))

(main)
