(defvar first-line (make-array 101 :element-type 'signed-byte))

(let ((first-num (read)))
  (loop for i from 1 to first-num
        do(setf (aref first-line i) (read)))
  (let ((second-num (read)))
    (loop for i from 1 to second-num
          do(let ((m (read)))
              (when (and (<= i first-num)
                         (= (aref first-line i) m))
                (format t "~D~%" i))))))
