;;; 这里直接用暴力方法求解,ac了,耗时也不算高,时间主要浪费在将数字转换为字符串的
;;; write-to-string和计数字符串中的数字和
;;; 高效的做法应该是,只对第一个输入做write-to-string,然后之后每次往后移,都对字符串
;;; 做加法,如果有进位,则外面的被除数+1-(10^进位-1)即可

;;; 也就是说用高精度加法(字符串加法)来做效率高,但比较麻烦,这儿就不写代码了
(defun calc-digits (n)
  (let ((nstr (write-to-string n)))
    (loop
      with acc = 0
      for x across nstr
      do(incf acc (- (char-code x) 48))
      finally(return acc))))

(defun main ()
  (let ((tc (read)))
    (declare ((unsigned-byte 16) tc))
    (loop
      repeat tc
      do(let ((n (read)))
          (loop
            for i = n then (incf i)
            for sum = (calc-digits i)
            do(when (zerop (mod i sum))
                (format t "~a~%" i)
                (loop-finish)))))))

(main)
