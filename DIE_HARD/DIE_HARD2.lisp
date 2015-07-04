(defun get-times (h a)
  (loop with acc = 0
        while (and (> h 0) (> a 0))
        do(progn
            (incf h 3)
            (incf a 2)
            (incf acc)
            (cond 
              ((and (> h 5)
                    (> a 10)
                    (decf h 5)
                    (decf a 10)))
              (t
                (decf h 20)
                (incf a 5)))
            (when (and (> h 0)
                       (> a 0))
              (incf acc)))
        finally (return acc)))

(defun main ()
  (loop repeat (read)
        do(format t "~A~%" (get-times (read) (read)))))

(main)
