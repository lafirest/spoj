;;;http://www.spoj.com/problems/ACODE/
;;;http://blog.csdn.net/suxinpaul/article/details/8007162
;;;http://www.spoj.com/problems/INVCNT/
(defun num(arr start end)
  (cond 
    ((> start end) 1)
    ((= start end) 
     (if (char= #\0 (aref arr start))
       0
       1))
    (t
     (let* ((mid (truncate (/ (+ start end) 2)))
           (half (aref arr mid)))
       (if (or 
             (char= half #\0)
             (char> half #\2)
             (and (char= half #\2) 
                  (char> (aref arr (1+ mid)) #\6)))
         (* (num arr start mid) (num arr (1+ mid) end))
         (+ 
           (* (num arr start mid) (num arr (1+ mid) end))
           (* (num arr start (1- mid)) (num arr (+ 2 mid) end))))))))

(loop for str = (read-line) 
      until (string= str "0")
      do (format t "~A~%" (num str 0 (1- (length str)))))
