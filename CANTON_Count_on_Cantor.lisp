;;;Complexity: O(n) time – O(1) space
;;;
;;;Each diagonal has a value (the sum of the numerator and the denominator) and a sense of “reading” it (even values go up, odd values go down).
;;;First find the diagonal where the number we’re looking for is. We’ll obtain the denominator (the numerator will be 1). 
;;;Then, add or substract (depending on the sense) the offset to the good position.
;;;这道题目的重点在于每行的对角线都标明了当前这行的个数,所以对于一个数n,通过从1开始累加到
;;;i,sum(1..i) >= n时,解就在这行.假设每行都是从左边开始的,则sum(1 .. i)是这行最后一个元素,
;;;sum(1 .. i) - 1就得到了,n的解在这行的位置,而这行第一个元素的down都等于1,一次递减,因此解的
;;;down部分为(- i pos),而up都是从1开始的,因此up部分为(+ 1 pos).而当i为奇数时,每行是从右边开始
;;;的,因此需要对调下解的位子
(defun result (i up down)
  (if (oddp i)
    (cons down up)
    (cons up down)))

(defun calc(n)
  (loop for i = 1 then (incf i)
        sum i into sum 
        do(cond 
            ((= sum n)
             (return (result i i 1)))
            ((> sum n)
             (let ((pos (- sum n)))
               (return (result i (- i pos) (1+ pos) )))))))

(loop repeat (read)
      do(let* ((n (read))
               (value (calc n)))
          (format t "TERM ~A IS ~A/~A~%" n (car value) (cdr value))))
