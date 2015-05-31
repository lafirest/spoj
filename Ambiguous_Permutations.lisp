(defvar hash (make-hash-table :test 'equal))

(defun is-ambiguous (col)
  (loop for pos from 1 to col
        with res = t
        do(let* ((val (read))
                 (posval (gethash pos hash nil)))
            (when res
              (if (not posval)
                (setf (gethash val hash) pos)
                (if (/= val posval)
                  (setf res nil)))))
        finally(return res)))

(loop for col = (read)
      until (zerop col)
      do(progn 
         (if (is-ambiguous col)
          (format t "ambiguous~%")
          (format t "not ambiguous~%"))
         (clrhash hash)))
