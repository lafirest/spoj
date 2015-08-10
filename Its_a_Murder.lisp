;;; 这道题目和求逆序数的题目使用的方法一样,都是归并排序,但是前面几次的归并排序都是用c来ac的,
;;; cl版本一直不能tle,然后c版本最初的代码还是看别人的代码实现的.所以这儿用cl来重写了份

;;; 这个是最初的合并代码,能用但是结构不清晰,没用这段代码,只是保留在这儿
(defun merge-array (arr1 arr2 arr len1 len2)
  (declare ((array (unsigned-byte 32) *) arr1 arr2 arr)
           (fixnum len1 len2))
  (loop
     with i = 0
     with j = 0
     for pos = 0 then (incf pos)
     do(cond
         ((= i len1)
          (loop for x from j below len2
             do(setf (aref arr pos) (aref arr2 x))
             do(incf pos))
          (loop-finish))
         ((= j len2)
          (loop for x from i below len1
             do(setf (aref arr pos) (aref arr1 x))
             do(incf pos))
          (loop-finish))
         (t
          (let ((vi (aref arr1 i))
                (vj (aref arr2 j)))
            (cond
              ((<= vi vj)
               (setf (aref arr pos) vi)
               (incf i))
              (t
               (setf (aref arr pos) vj)
               (incf j)))))))
  arr)

(defvar acc 0)   ;;; 结果
(declaim (optimize (speed 2)))

;;; 将两个数组合并到一个数组中
(defun merge-and-count (arr1 arr2 arr len1 len2)
  (declare ((array (unsigned-byte 32) *) arr1 arr2 arr)
           (fixnum len1 len2))
  (let ((x 0) ;;;左边数组的下标
        (y 0) ;;;右边数组的下标
        (pos 0) ;;;合并用的数组的下标
        ;;; 左边数组当前的和(比当前右边的值小的所有的数的和),如果不缓存,每次需要去左边数组的和时,都从头开始计算,会tle
        (lacc 0))

    ;;; 循环合并直到某个数组被全部取出
    (loop
       until(or (= x len1) (= y len2))
       do(let ((v1 (aref arr1 x))
               (v2 (aref arr2 y)))
           (cond
             ((< v1 v2)
              (setf (aref arr pos) v1)
              (incf x)
              (incf lacc v1))
             (t
              ;;; 将右边某个数输出时,需要给acc加上其前面所有左边的数的和
              (setf (aref arr pos) v2)
              (incf acc lacc)
              (incf y))))
       do(incf pos))

    ;;; 处理左边剩下的数据
    (loop
       for i from x below len1
       do(let ((value (aref arr1 i)))
           (setf (aref arr pos) value)
           (incf lacc value)  ;;; 这里可以去掉的,进入这个循环,则下面那个循环是不会进入了的
           (incf pos)))

    ;;; 处理右边剩下的数据(两个其实是互斥的)
    (loop
       for i from y below len2
       do(setf (aref arr pos) (aref arr2 i))
       do(incf acc lacc)
       do(incf pos)))
  arr)

;;; 递归分隔和合并数组
(defun merge-sort (arr len)
  (declare ((array (unsigned-byte 32) *) arr)
           (fixnum len))
  (if (= 1 len)
      (make-array 1 :element-type '(unsigned-byte 32) :initial-element (aref arr 0))
      (let* ((mid (ash len -1))
             (len2 (- len mid)))
        (declare (fixnum mid))
        (merge-and-count
         (merge-sort (subseq arr 0 mid) mid)
         (merge-sort (subseq arr mid len) len2)
         arr
         mid
         len2))))

(defun main ()
  (loop
     with arr = (make-array 100001 :element-type '(unsigned-byte 32) :initial-element 0)
     repeat (read)
     do(let ((n (read)))
         (declare (fixnum n))
         (if (<= n 0)
             (format t "0~%")
             (progn
               (setf acc 0)
               (loop for i from 0 below n
                  do(setf (aref arr i) (read)))
               (merge-sort arr n)
               (format t "~A~%" acc))))))

(main)
