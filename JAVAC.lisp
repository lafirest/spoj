;;;WRONG 运行时错误,具体原因不明
(defun parse (str)
  (loop for x across str
        with len = (length str)
        with stype = nil
        with start = 0
        with res = ""
        count 1 into pos
        do (cond 
             ((upper-case-p x)
              (if (and stype 
                         (eql stype 'cpp))
                (return "Error!")
                (setf stype 'java))
              (when (= pos 1)
                (return "Error!"))
              (setf res
                    (format nil "~A~A_~C" res (subseq str start (1- pos)) (char-downcase x)))
              (setf start pos))
             ((char= x #\_)
              (if (and stype 
                       (eql stype 'java))
                (return "Error!")
                (setf stype 'cpp))
              (when (= pos len)
                (return "Error!"))
              (let ((next (aref str pos)))
                (if (alpha-char-p next)
                  (setf res
                        (format nil "~A~A~C" res 
                                (subseq str start (1- pos)) 
                                (char-upcase next)))
                  (return "Error!")))
              (setf start (+ 1 pos))))
        finally (return (format nil "~A~A" res (subseq str start pos)))))

(loop for str = (read-line) 
      until (string= str "")
      do (format t "~A~%" (parse str)))

