(defun test()
  (let ((flist '())
        (ffhash (make-hash-table)))
    (dotimes (x (read))
      (push (read) flist)
      (dotimes (y (read))
        (setf (gethash (read) ffhash) t)))
    (loop for f in flist
          do(setf (gethash f ffhash) nil))
    (format t "~A" (loop for x being the hash-value in ffhash 
                           when x
                           count x))))

(test)
