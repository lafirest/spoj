;;;0-1背包问题,直接用的是之前party 调度的代码,没有做太大修改和优化
;;;可以优化的地方:dp-array和item-arr没必要每次都重新分配,使用全局的就可以了
;;;其次使用结构体代替cons对

;;; 比较函数,重量越小,价值越高的越好
(defun compare(i j)
  (let ((ivalue (cdr i))
        (jfun (cdr j)))
    (if (> ivalue jfun)
      i
      (if (= ivalue jfun)
        (if (< (car i) (car j))
          i
          j)
        j))))

(defun add(i j)
  (cons (+ (car i) (car j)) (+ (cdr i) (cdr j))))

;;; 0-1背包公式
;;; i = (w v)
;;;                     f(i - 1, j) 
;;; f(i, j) = optimal(                      )
;;;                     f(i - 1, j - w) + v 
;;;  
(defun get-optimal-value(curitem dp-array i j)
  (let* ((prev-optimal (aref dp-array (1- i) j))
         (item-wight (car curitem)))
    ;;; 如果当前物品的重量直接超过了背包容量,则返回上一行的最优解
    ;;; 否则按照公式选出最优的一个解
    (if (< j item-wight)
      prev-optimal  
      (compare prev-optimal (add curitem (aref dp-array (1- i) (- j item-wight)))))))

;;; 0-1背包问题说明
;;; 以物品个数为行,容量上限为列,建立求值矩阵.
;;; 对于某行i来说,其上一行对应位置(i - 1, j)为除去对应物品时的最优解
;;; 对于某列j来说,j代表着当前的背包容量,(i, j)表示背包容量为j时,1～i这几个物品的最优解
;;; 所以f(i, j)的值为:其上一行(不包括这个物品)对应容量时的最优解f(i - 1, j)和包括这个
;;; 物品时的值,两者间的最优值.
;;; 设物品i的重量为w,而当前容量为j,所以包括这个物品时的值为,上一行背包容量为j-w时的值+
;;; 物品i对应的值v,等于f(i - 1, j - w) + v.
(defun knapsack(item-arr num limit)
  (let* ((dp-array (make-array (list num (1+ limit)) :initial-element (cons 0 0)))
         (first-item (aref item-arr 0))
         (first-wight (car first-item)))
    ;;; 第一行做为初始行,单独处理
    (loop for i from 1 to limit
          do(when (>= i first-wight)
              (setf (aref dp-array 0 i) first-item)))
    ;;; 生成求值矩阵
    (loop for i from 1 below num
          do(let ((curitem (aref item-arr i)))
              (loop for j from 1 to limit
                    do(setf (aref dp-array i j) (get-optimal-value curitem dp-array i j)))))
    ;;; 返回最优解
    (aref dp-array (1- num) limit)))

(defun main ()
  (let ((n (read)))
    (declare ((unsigned-byte 8) n))
    (loop repeat n
          do(let* ((limit (read))
                  (num (read))
                  (item-arr (make-array num :element-type 'list :initial-element (cons 0 0))))
              (declare ((unsigned-byte 16) limit)
                       ((unsigned-byte 8) num))
              (loop for i from 0 below num 
                    do(setf (aref item-arr i)
                            (cons (read) (read))))
              (let ((optimal-val (knapsack item-arr num limit)))
                (format t "Hey stupid robber, you can get ~a.~%" (cdr optimal-val)))))))

(main)
