(defvar hash (make-hash-table :test 'equal))
(defun breaking(num)
  (loop with x = num
        with r = 0
        until (zerop x)
        do(progn
            (setf r (+ r (expt (rem x 10) 2)))
            (setf x (floor (/ x 10))))
        finally (return r)))

(defun is-happy(num)
  (loop for x = (breaking num) then (breaking x)
        count 1 into c
        when (= x 1)
        do (return c)
        do (if (gethash x hash nil)
            (return -1)
            (setf (gethash x hash ) t))))

(format t "~A~%" (is-happy (read)))
