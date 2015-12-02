;;; 连乘中有一项为0,则结果为0，所以这里没必要算出所有的数和所有过程
(let ((n (read))
      (cn! 1)
      (r 1))
  (declare
    (fixnum n)
    ((unsigned-byte 64) cn! r))
  (if (>= n 587117)
    (setf r 0)
    (loop for i from 2 to n
          do(setf cn! (mod (* cn! i) 109546051211)
                  r (mod (* r cn!) 109546051211))
          if(zerop r)
          do(loop-finish)))
  (print r))

