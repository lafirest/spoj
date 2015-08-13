;;; 这是一道染色问题,cl的版本一直nezc,表示不理解
;;; 这个版本的实现方法是:从一个没染色的点开始搜索,每搜索一次点都设置访问表示,如果
;;; 搜索到了一个被标示了的点,说明要么是返回到搜索链表中的某个元素,要么和某个已经染色
;;; 了的链表连通,第一种的话分配一个新染色,第二种则使用已经染了的色,对搜索链表染色
;;; 这个版本会nezc,开始以为是栈溢出了,就有了版本2
(defvar grid (make-array '(1001 1001) :element-type 'character :initial-element #\0))
(defvar visited (make-array '(1001 1001) :element-type 'boolean :initial-element nil))
(defvar colorarr (make-array '(1001 1001) :element-type '(unsigned-byte 32) :initial-element 0))

(defvar gcolor 0)
(defvar link nil)

(defun new-color ()
  (incf gcolor)
  gcolor)

(defun mark-color (color)
  (dolist (pair link)
    (setf (aref colorarr (car pair) (cdr pair)) color))) 

(defun to-color (i j n m)
  (setf link nil)
  (let ((x i)
        (y j))
    (loop
       do(let ((color (aref colorarr x y))
               (isvisited (aref visited x y)))
           (when isvisited
             (if (zerop color)
                 (mark-color (new-color))
                 (mark-color color))
             (loop-finish))

           (setf (aref visited x y) t)

           (push (cons x y) link)
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
               (mark-color (new-color))
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
       do(let ((line (read-line)))
           (loop
              for j from 0 below m
              do(setf (aref grid i (1+ j)) (char line j)))))
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
