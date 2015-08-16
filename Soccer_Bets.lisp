;;; 集合类问题,将没有被淘汰的放入team,被淘汰了的放入lost中去
(defvar team)
(defvar lost (make-hash-table :test 'equal))

(defun main()
  (let ((c (read)))
    (declare ((unsigned-byte 8) c))
    (loop
      repeat c
      do(setf team nil)
      do(clrhash lost)
      do(loop
          repeat 16
          do(let ((t1 (symbol-name (read)))
                  (t2 (symbol-name (read)))
                  (g1 (read))
                  (g2 (read)))
              (declare (simple-string t1 t2)
                       ((unsigned-byte 16) g1 g2))
              (let ((w t1)
                    (l t2))
                (when (> g2 g1)
                  (setf w t2)
                  (setf l t1))

                (setf (gethash l lost) t)
                (setf team (delete l team))

                (when (not
                        (or
                          (gethash w lost)
                          (member w team)))
                  (push w team))))

          finally (format t "~a~%" (car team))))))

(main)
