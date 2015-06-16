;;; 读取输入后对每个点做bfs
;;; 时间复杂度太大了,超时
(defvar *array* (make-array '(182 182) :element-type 'character :initial-element #\0))
;;;(defvar *distance* (make-array '(182 182) :element-type '(unsigned-byte 8) :initial-element 0))

(defun find-pos (points i j m n)
  (if (endp points)
    nil
    (let* ((hd (car points))
           (i1 (+ i (car hd)))
           (j1 (+ j (cdr hd))))
      (if (or 
            (>= i1 m) 
            (>= j1 n)
            (< i1 0)
            (< j1 0))
        (find-pos (cdr points) i j m n)
        (if (char= (aref *array* i1 j1) #\1)
          (return-from find-pos (cons i1 j1))
          (find-pos (cdr points) i j m n))))))


(defun bfs (i j m n md)
  ;;; 搜索的距离从0到md
  (loop for d from 0 to md 
        ;;; i = [0,d] [-d, 0]
        ;;; j = +[d - i] -[d - i]
        do (loop for i1 from 0 to d
                 do(let ((i2 (- i1))
                         (j1 (- d i1))
                         (j2 (- i1 d))
                         (pos nil))
                     (if (= i1 i2)
                       (if (= j1 j2)
                         (setf pos (find-pos (list (cons i1 j1)) i j m n))
                         (setf pos (find-pos (list (cons i1 j1) (cons i1 j2)) i j m n)))
                       (if (= j1 j2)
                         (setf pos (find-pos (list (cons i1 j1) (cons i2 j1)) i j m n))
                         (setf pos (find-pos (list (cons i1 j1) (cons i1 j2) (cons i2 j1) (cons i2 j2)) i j m n))))
                     (if pos 
                       (return-from bfs (+ (abs (- (car pos) i)) (abs (- (cdr pos) j)))))))))

(defun main ()
  (loop repeat (read)
        do (let* ((m (read))
                  (n (read))
                  (md (* m n)))
             ;;; 读取数组
             (loop for i from 0 below m
                   do (let ((str (read-line)))
                        (loop for j from 0 below n
                              do (setf (aref *array* i j) (aref str j)))))

             ;;; 遍历数组对每个点做bfs
             (loop for i from 0 below m
                   do (loop for j from 0 below n
                            do (format t "~A " (bfs i j m n md)))
                   do (format t "~%")))))

(main)
