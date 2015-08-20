;;; 二项式系数的问题,不懂其中的数学原理,直接套用的公式
;;; https://en.wikipedia.org/wiki/Binomial_coefficient#Generalization_to_multinomials
;;; 需要提高提高数学能力了,不然以后就学不动了
;;; 这里的factorial其实可以预先处理成数组的,但这儿数据量小,没必要做预处理
(defun factorial (n)
  (declare ((unsigned-byte 8) n))
  (loop
    with acc = 1
    for i from 2 to n
    do(setf acc (* acc i))
    finally(return acc)))

(defun main ()
  (loop
    for n of-type (unsigned-byte 8) = (read nil nil 127)
    until (= n 127)
    do(let ((k (read)))
        (declare ((unsigned-byte 8) k))
        (loop
          with fn = (factorial n)
          for i from 0 below k
          do(setf fn (/ fn (factorial (read))))
          finally(format t "~a~%" fn)))))

(main)
