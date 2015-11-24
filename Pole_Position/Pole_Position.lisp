(defvar arr (make-array 1001 :element-type 'fixnum :initial-element 0))

(defun main ()
  (loop
    for pos = 1
    for suc = t
    for n = (read)
    until (zerop n)
    do(loop
        repeat n
        do(let* ((num (read))
                 (inc (read))
                 (rpos (+ pos inc)))
            (incf pos)
            (when suc
              (if (or (< rpos 1)
                      (> rpos n)
                      (/= 0 (aref arr rpos)))
                (setf suc nil)
                (setf (aref arr rpos) num))))
        finally(progn
                 (if suc
                   (loop for i from 1 to (1- n)
                         do(format t "~a " (aref arr i))
                         finally (format t "~a~%" (aref arr n)))
                   (format t "-1~%"))
                 (loop for i from 1 to n
                       do(setf (aref arr i) 0))))))

