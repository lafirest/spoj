;;; 日期计算问题,手动编码难度也不大,但麻烦,这儿偷懒直接用cl自带的函数来解决
;;; 蔡勒公式知识:
;;; http://baike.baidu.com/link?url=TDHJqHdG4s6t4qQEOIWZe1Jna4UtkVgNp9lcpvNXeE5wPKGcE_rTdrpYF8HryMTu0QxO7-cYMhb69b7qpW_nwa
;;; https://en.wikipedia.org/wiki/Zeller%27s_congruence
(defvar day-name (make-array 7 :initial-element ""))

(defun main ()
  (loop for i from 0 below 7
        for x in '("Monday" "Tuesday" "Wednesday" "Thursday" "Friday" "Saturday" "Sunday")
        do(setf (aref day-name i) x))
  (let ((n (read)))
    (declare ((unsigned-byte 8) n))
    (loop
      repeat n
      do(let ((d (read))
              (m (read))
              (y (read)))
          (declare ((unsigned-byte 16) d m y))
          (format t "~A~%" (aref day-name (nth-value 6 (decode-universal-time (encode-universal-time 0 0 0 d m y 0)))))))))

(main)

