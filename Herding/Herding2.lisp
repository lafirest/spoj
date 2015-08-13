;;; 这个版本是去掉了搜索链表,做两次搜索,第一次搜索决定使用什么颜色,第二次进行染色,
;;; 可能出现run time error的地方都考虑了,结果还是会nezc
(defvar grid (make-array '(1001 1001) :element-type 'character :initial-element #\0))
(defvar visited (make-array '(1001 1001) :element-type 'boolean :initial-element nil))
(defvar mvisited (make-array '(1001 1001) :element-type 'boolean :initial-element nil))
(defvar colorarr (make-array '(1001 1001) :element-type '(unsigned-byte 32) :initial-element 0))

(defvar gcolor 0)

(defun new-color ()
  (incf gcolor)
  gcolor)

(defun mark-color (i j n m color)
  (let ((x i)
        (y j))
    (loop 
       do(let ((isvisited (aref mvisited x y)))
           (when isvisited
             (loop-finish))
           
           (setf (aref mvisited x y) t)
           (setf (aref colorarr x y) color)

           (let ((direct (aref grid x y)))
             (case direct
               (#\S
                (incf x))
               (#\N
                (decf x))
               (#\E
                (incf y))
               (#\W
                (decf y)))
             (when (or
                    (zerop x)
                    (> x n)
                    (zerop y)
                    (> y m))
               (loop-finish)))))))

(defun to-color (i j n m)
  (let ((x i)
        (y j))
    (loop
       do(let ((color (aref colorarr x y))
               (isvisited (aref visited x y)))
           (when isvisited
             (if (zerop color)
                 (mark-color i j n m (new-color))
                 (mark-color i j n m color))
             (loop-finish))

           (setf (aref visited x y) t)

           (let ((direct (aref grid x y)))
             (case direct
               (#\S
                (incf x))
               (#\N
                (decf x))
               (#\E
                (incf y))
               (#\W
                (decf y)))
             (when (or
                    (zerop x)
                    (> x n)
                    (zerop y)
                    (> y m))
               (mark-color i j n m (new-color))
               (loop-finish)))))))

(defun colored (n m)
  (loop
     for i from 1 to n
     do(loop
          for j from 1 to m
          do(when (zerop (aref colorarr i j))
              (to-color i j n m)))))

(defun main ()
  (let ((n (read))
        (m (read)))
    (declare ((unsigned-byte 16) n m))
    (loop
       for i from 1 to n
       do(loop
            with j = 0
            until (>=  j m)
            do(let ((char (read-char)))
                (when (member char '(#\S #\N #\E #\W))
                  (setf (aref grid i (1+ j)) char)
                  (incf j)))))
    (colored n m)
    (format t "~A~%" gcolor)))

(defun test (n)
  (when (zerop n)
    (return-from test))
  
  (let ((n (min (max 1 (random 1001))))
        (m (min (max 1 (random 1001))))
        (ca #(#\S #\N #\E #\W)))
    (loop for i from 1 to n
       do(loop for j from 1 to m
            do(setf (aref grid i j) (svref ca (random 4)))))
    (colored n m)
    (format t "~A~%" gcolor)
    (setf gcolor 0)
    (loop for i from 1 to n
       do(loop for j from 1 to m
            do(progn
                (setf (aref grid i j) #\0)
                (setf (aref visited i j) nil)
                (setf (aref colorarr i j) 0)))))
  (test (1- n)))

(defun print-color (n m)
  (loop for i from 1 to n
     do(progn
         (loop for j from 1 to m
            do(format t "~a " (aref colorarr i j)))
         (format t "~%"))))

(main)
