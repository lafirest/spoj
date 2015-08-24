;;; tle... c版本0.04s ac
(defun main ()
  (loop
     for n of-type (unsigned-byte 32) = (read)
     until(zerop n)
     do(let ((units 0)
             (acc 0))
         (loop
            repeat n
            for v of-type (signed-byte 16) = (read)
            do(progn
                (incf units (abs acc))
                (incf acc v)))
         (format t "~a~%" units))))

(main)
