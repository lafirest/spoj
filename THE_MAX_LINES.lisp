;;;思路:ab边最长时,得到的s最大,而ab<2r=2,设ab=2,则ac=0.25
;;;     当ab趋近d(2r)时,ac趋近0.25,所以s=(2r)^2 + 0.25
;;;     且任何整数都是1的倍数,所以直接替换就可以了
;;;     重点是浮点数的精度,需要用coerce将数转换为double
(dotimes (x (read))
  (format t "Case ~A: ~,2F~%" (1+ x) (+ 0.25 (coerce (* 4 (expt (read) 2)) 'long-float))))


