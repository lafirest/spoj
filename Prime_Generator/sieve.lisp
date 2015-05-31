(defun gen-array (num)
  (let ((arr 
          (make-array num   :element-type 'boolean 
                      :initial-element t)))
    (setf (aref arr 0) nil)
    (setf (aref arr 1) nil)
    arr))


(defun sieve (left right)
  (let ((arr (gen-array right))
        (i 2))
    (loop while (<= (* i i) right)
          do (loop for c = 2 then (incf c)
                   for idx = (* i 2) then (setf idx (* i c))
                   while (< idx right)
                   do(setf (aref arr idx) nil))
          do(loop do(incf i)
                  while (and (not (aref arr i))
                             (<= (* i i)))))
    (loop for x from left below right 
          when (aref arr x)
          do (format t "~A~%" x))))


