;;;TLE
;;;http://www.cp.eng.chula.ac.th/~piak/teaching/algo/algo2008/count-inv.htm
;;;这里是使用归并排序的算法,计算逆序列的个数.因为在不断的构建链表,所以效率很低,
;;;C语言版本使用数组和下标进行操作的
(defun count-length (lst)
  (labels ((count-length2 (head lst)
             (cond 
               ((null lst)
                1)
               ((> (car lst) head)
                (1+ (length lst)))
               (t 
                (count-length2 head (cdr lst))))))
    (count-length2 (car lst) (cdr lst))))

(defun merge-and-count2 (left right counter acc)
  (cond 
    ((null left)
     (values counter (append acc right)))
    ((null right)
     (values counter (append acc left)))
    (t
     (let ((lf (car left))
           (rf (car right)))
       (cond
         ((<= lf rf)
          (merge-and-count2 (cdr left) right counter (append acc (list lf))))
         (t
          (merge-and-count2 left (cdr right) (+ (count-length left) counter) (append acc (list rf)))))))))

(defun merge-and-count (left right)
  (merge-and-count2 left right 0 'nil))

(defun split2 (lst n acc)
  (cond 
    ((or 
       (zerop n)
       (null lst))
     (values acc lst))
    (t
     (split2 (cdr lst) (1- n) (append acc (list (car lst)))))))

(defun split (lst n)
  (split2 lst n 'nil))

(defun sort-and-count (lst)
  (if (<= (length lst) 1)
    (values 0 lst)
    (multiple-value-bind (left right)
      (split lst (truncate (/ (length lst) 2)))
      (multiple-value-bind (lcount llist)
        (sort-and-count left)
        (multiple-value-bind (rcount rlist)
          (sort-and-count right)
          (multiple-value-bind (mcount mlist)
            (merge-and-count llist rlist)
            (values (+ lcount rcount mcount) mlist)))))))

(dotimes (x (read))
  (read-line)
  (loop repeat (read)
        collect (read) into result
        finally (return (format t "~A~%" (sort-and-count result)))))


