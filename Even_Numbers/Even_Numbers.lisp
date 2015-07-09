(defun bit-reverse (n)
  (read-from-string (concatenate 'string "#B" (reverse (format nil "~B" n)))))

(defun main ()
  (loop repeat (read)
        do(let ((n (read)))
            (format t "~D~%"
                    (if (oddp n)
                      n
                      (bit-reverse n))))))
