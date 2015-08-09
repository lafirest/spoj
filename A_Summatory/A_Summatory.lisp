;这个会tle,首先是求和直接使用定义的公式,没有化简
;其次每次对n都从1开始从新计算,做了很多重复操作
;后面的方案化简了公式,且进行了记忆化处理
(declaim (optimize (speed 2)))
(defun main ()
  (loop repeat (read)
     do(let ((n (read))
             (acc 0))
         (declare ((unsigned-byte 32) n))
         (loop
            for i from 1 to n
            for j from n downto 1
            do(incf acc (* j (expt i 3)))) 
         (format t "~A~%" (mod acc 1000000003)))))

(main)
