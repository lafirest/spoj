;;; 这个代码会tle
(declaim (optimize (speed 2)))
(defvar *array* (make-array 100000 :element-type 'fixnum :initial-element 0))

;;; 这个快排是从rosettacod上面抄的,效率可能有问题
(defun quicksort (len)
  (labels ((swap (a b) (rotatef (aref *array* a) (aref *array* b)))
           (sub-sort (left right)
                     (when (< left right)
                       (let ((pivot (aref *array* right))
                             (index left))
                         (loop for i from left below right
                               when (<= (aref *array* i) pivot)
                               do (swap i (prog1 index (incf index))))
                         (swap right index)
                         (sub-sort left (1- index))
                         (sub-sort (1+ index) right)))))
    (sub-sort 0 (1- len))))

;;; 从第一个位置开始,按照间距x来计算能够放下的奶牛的数量
(defun greed (x n c &aux (need (1- c)))
  (loop with acc = 0
        with i = 0
        for j from 1 below n 
        when (<= (+ (aref *array* i) x)
                 (aref *array* j))
        do (progn 
             (setf i j)
             (incf acc))
        until (>= acc need)
        finally (return (>= acc need))))

(defun main ()
  (loop repeat (read)
        do (let ((n (read))
                 (c (read)))
             ;;; 读取输入
             (loop for i from 0 below n
                   do (setf (aref *array* i) (read)))

             ;;; 对输入排序
             (quicksort n)

             ;;; 设最大间隔为s,则s >= 0
             ;;; 输入序列中的最大距离为in - i0,需要c-1个间隔
             ;;; 则s <= (in - i0) / (c - 1),使用二分查找来寻找最大的值
             (let ((right (floor (/ (- (aref *array* (1- n))
                                       (aref *array* 0))
                                    (1- c))))
                   (left 0))
               (loop while (<= left right)
                     for mid = (ash (+ right left) -1)
                     if (greed mid n c)
                     ;;; mid 能够放下,则mid <= s <=right,left向右移动
                     do (setf left (1+ mid))
                     else 
                     ;;; 不能方向,则left <= s <= mid,right向左移动
                     do (setf right (1- mid)))
               (format t "~A~%" (1- left))))))

(main)


