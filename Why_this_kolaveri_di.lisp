;;; 约瑟夫问题的变形,要比之前做过的难
;;; https://en.wikipedia.org/wiki/Josephus_problem
(defun f (n k)
  (if (= n 1)
    1
    (1+ (mod (+ (f (1- n) (1+ k)) k) n))))

(defun main ()
  (loop
    repeat (read)
    do(let ((n (read)))
        (declare ((unsigned-byte 32) n))
        (format t "~a~%" (f n 0)))))

(main)
