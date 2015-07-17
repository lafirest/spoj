;;;很简单的一道题目,求出最大内径的值,和出去最大内径所在的pair外最大
;;;的外径值,如果内径大于外经就ok.最近连续挂了好几道dp了,唉
(defun main ()
  (loop repeat (read)
     do(let ((pos -1)
             (maxi 0)
             (maxo 0)
             (maxot 0))
         (loop for i from 1 to (read)
            do(let ((ir (read))
                    (or (read)))
                (cond
                  ((> ir maxi)
                   (setf maxi ir)
                   (setf pos i)
                   (when (> maxot maxo)
                     (setf maxo maxot))
                   (setf maxot or))
                  (t
                   (when (> or maxo)
                     (setf maxo or))))))
              (if (> maxi maxo)
                  (format t "~A~%" pos)
                  (format t "-1~%")))))
(main)

