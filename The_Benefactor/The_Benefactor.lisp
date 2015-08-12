;;; 第5个版本是最终版本,lisp版本的错误是不应该使用dfs,因为图有50000个顶点,用
;;; dfs很轻松就能栈溢出了 
(defvar vertex (make-array 50001 :element-type 'list :initial-element nil))
(defvar vis (make-array 50001 :element-type '(unsigned-byte 16) :initial-element 0))

(defvar maxv 0)
(defvar color 1)
(defvar maxver 1)

(defun dfs (pos len)
  (declare ((unsigned-byte 16) pos len))
  (when (/= color (aref vis pos))
    (when (> len maxv)
      (setf maxv len)
      (setf maxver pos))
    (setf (aref vis pos) color)
    (let ((nlist (aref vertex pos)))
      (if nlist
          (dolist (x nlist)
            (dfs (car x) (+ len (cdr x))))))))

(defun main ()
  (loop
     repeat (read)
     do (let ((n (read)))
          (declare ((unsigned-byte 16) n))
          (loop
             for i from 1 below n
             for v1 of-type (unsigned-byte 16) = (read)
             for v2 of-type (unsigned-byte 16) = (read) 
             for len of-type (unsigned-byte 16) = (read)
             do(progn
                 (push (cons v2 len) (aref vertex v1))
                 (push (cons v1 len) (aref vertex v2))))
          (setf maxv 0)
          (setf maxver 0)
          (dfs 1 0)
          (incf color)
          (dfs maxver 0)
          (incf color)
          (format t "~A~%" maxv)
          (loop for i from 1 to n
             do(setf (aref vertex i) nil)))))

(main)
