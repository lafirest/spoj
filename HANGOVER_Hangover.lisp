;;;开始以为这道题有什么高级算法,还去看了调和数列,后来发现不是,这也是个有问题的思路
;;;因为数据不大,所以这儿直接使用暴力求值就可以了
;;;可以进行的优化就是建立一个数组,从1/2开始,一直加到1/2..+1/n的结果>=5.20为止,之后
;;;通过二分查找确定输入n在数组中的位置p,p就是结果了
(defun calc(n)
  (loop for i = 2 then (incf i)
        with acc = 0
        until (>= acc n)
        do (setf acc (+ acc (/ 1 i)))
        count i into times
        finally (return times)))
        

(loop for n = (read)
      until (= n 0.00)
      do (format t "~A card(s)~%" (calc n)))
