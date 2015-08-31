;;; 这里用的是扩展欧几里德算法,原理是贝祖定理
;;; https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
;;; https://en.wikipedia.org/wiki/B%C3%A9zout%27s_identity  贝祖定理
(defmacro check (a b c)
  `(zerop (mod ,c (gcd ,a ,b))))

(defun main ()
  (loop
    with tn of-type (unsigned-byte 32) = (read)
    for i from 1 to tn 
    do(let ((a (read))
            (b (read))
            (c (read)))
        (declare ((unsigned-byte 32) a b c))
        (format t "Case ~A: ~A~%" i (if (check a b c) "Yes" "No")))))

(main)
