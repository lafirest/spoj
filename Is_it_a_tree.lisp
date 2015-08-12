;;; 看评论可以用一个访问数组来判断是否是图,然后我就尝试用访问数组来实现,结果
;;; 一个wa,想了下都没法解决,然后就改用现在这种方法
;;; 这道题目是判断一个图是否是树,要判断3点:
;;; 1.根据图的定义m = 1 - n
;;; 2.不是循环图
;;; 3.所有节点必须是连通的
;;; 单纯用访问数组,没想出来怎么有效的判断是连通和是否有循环节点,然后基于上面3个判断
;;; 使用并查集最优了,但我不会并查集算法,还可以构造图然后做bfs和dfs,但最晚才这么做了一次
;;; 不想用这么做.然后...我想出了这种方法
;;; 这里用的是染色法,如果两个edge都没有被染色,则染色,然后用一个hash存颜色->edge list的映射,
;;; 一个hash存edge->color的映射;如果其中一个有,则给没有颜色的染上相同的颜色;如果两个颜色一样,
;;; 则说明循环了;如果两个颜色不一样,合并两个然后
;;; 因为颜色合并是线性的O(n),所以这中算法的效率不算高,但也能接受
(defvar edge-color (make-hash-table))
(defvar color-list (make-hash-table))
(defvar color 1)

(defun main ()
  (let ((n (read))
        (m (read))
        (istree t))
    (declare ((unsigned-byte 16) n m))
    (when (/= m (1- n))
      (setf istree nil))
    (loop
       for i from 0 below m
       do(let* ((vertex (read))
                (edge (read))
                (vcolor (gethash vertex edge-color 0))
                (ecolor (gethash edge edge-color 0)))
           (declare ((unsigned-byte 16) vertex edge))
           (when istree
             (cond
               ((= 0 vcolor ecolor)
                (setf (gethash vertex edge-color) color)
                (setf (gethash edge edge-color) color)
                (setf (gethash color color-list) (list vertex edge))
                (incf color))
               ((zerop vcolor)
                (setf (gethash vertex edge-color) ecolor)
                (let ((elist (gethash ecolor color-list)))
                  (setf (gethash ecolor color-list)
                        (cons vertex elist))))
               ((zerop ecolor)
                (setf (gethash edge edge-color) vcolor)
                (let ((vlist (gethash vcolor color-list)))
                  (setf (gethash vcolor color-list)
                        (cons edge vlist))))
               ((= vcolor ecolor)
                (setf istree nil))
               (t
                (let* ((mincolor (min vcolor ecolor))
                       (maxcolor (max vcolor ecolor))
                       (minlist (gethash mincolor color-list))
                       (maxlist (gethash maxcolor color-list)))
                  (setf (gethash mincolor color-list)
                        (append minlist maxlist))
                  (remhash maxcolor color-list)
                  (dolist (x maxlist)
                    (setf (gethash x edge-color) mincolor))))))))
    (when (/= (hash-table-count color-list) 1)
      (setf istree nil))
    (format t "~A~%" (if istree "YES" "NO"))))

(main)
