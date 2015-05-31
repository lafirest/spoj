;;; 这里采用预先读入正行字符串,然后通过操作符进行分割,缓存操作,
;;; 读取到下一个操作时,处理上一个操作
;;; 还可以先逐个read,获得一个list,取firest作为起始值,依次取出操作和
;;; 下一个操作数
(defun parse(str)
  (loop for x across str
        with start = 0
        with res = nil
        with op = nil
        count 1 into pos
        when (member x '(#\+ #\- #\* #\/ #\=))
        do (let ((val (parse-integer (subseq str start (1- pos)))))
             (setf start (1+ pos))
             (cond 
               (res 
                (setf res (funcall op res val))
                (setf op nil))
               (t 
                (setf res val)))
             (cond
               ((char= x #\+) (setf op #'+))
               ((char= x #\-) (setf op #'-))
               ((char= x #\*) (setf op #'*))
               ((char= x #\/) (setf op 
                                    #'(lambda(x y) 
                                        (floor (/ x y)))))
               (t (return (if op
                            (funcall op res val)
                            res)))))))

;;; 每行输入后面有个空行!
(dotimes (x (read))
  (read-line)
  (format t "~A~%" (parse (read-line))))










