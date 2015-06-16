;;; blog.csdn.net/hcbbt/article/details/38144395
;;; 读取输入时将为1的项数据记作0,并且放入队列中,为0的记作*max*
;;; 更新队列中的元素的上下左右四个方向上的值,更新的条件是:
;;; 1.对应的格子没有越界
;;; 2.对应的格子上的还是初值或则比当前格子+1要大
;;; 将更新了的格子放入队列中(因为这个格子更新了,所以它的上下左右四个方向上的值
;;; 可能会受到影响)
;;; 这中算法的优点在于从数量比较少的值为1的点开始像周围更新,然后在继续更新更新了
;;; 的点周围的点,继续迭代,直到更新完整个数组为止
;;; 犯过的错误:
;;; 1.update 的判断错了,导致会越界
;;; 2.max的值应该比182*182要大,开始使用的是255...
(defvar *array* (make-array '(182 182) :element-type '(unsigned-byte 16) :initial-element 0))
(defvar *max* #XFFFF)

(defstruct (queue (:type vector))
  head
  last)

(defstruct (node (:type vector))
  data
  next)

(defun queue-push (queue data)
  (let ((new (make-node :data data :next nil)))
    (cond
      ((queue-head queue)
       (let ((last-node (queue-last queue)))
         (setf (node-next last-node) new)
         (setf (queue-last queue) new)))
      (t
        (setf (queue-head queue) new)
        (setf (queue-last queue) new)))))

(defun queue-pop (queue)
  (let ((head (queue-head queue)))
    (when head
      (setf (queue-head queue) (node-next head)))
    head))

(defmacro update (expr x y)
  `(when (and ,expr
              (or (= (aref *array* ,x ,y) *max*)
                  (> (aref *array* ,x ,y) rank)))
     (setf (aref *array* ,x ,y) rank)
     (queue-push queue (cons ,x ,y))))

(defun bfs (queue m n)
  (let ((hd (queue-pop queue)))
    (when hd
      (let* ((data (node-data hd))
             (i (car data))
             (j (cdr data))
             (rank (1+ (aref *array* i j))))
        (update (> i 0) (1- i) j)
        (update (< i (1- m)) (1+ i) j)
        (update (> j 0) i (1- j))
        (update (< j (1- n)) i (1+ j)))
      (bfs queue m n))))

(defun main ()
  (loop repeat (read)
        do (let* ((m (read))
                  (n (read))
                  (queue (make-queue :head nil :last nil)))
             ;;; 读取数组
             (loop for i from 0 below m
                   do (let ((str (read-line)))
                        (loop for j from 0 below n
                              do (let ((v (aref str j)))
                                   (cond 
                                     ((char= v #\0)
                                      (setf (aref *array* i j) *max*))
                                     (t 
                                       (setf (aref *array* i j) 0)
                                       (queue-push queue (cons i j) )))))))

             (bfs queue m n)
             (loop for i from 0 below m 
                   do (loop for j from 0 below n
                            do(format t "~A " (aref *array* i j)))
                   do (format t "~%")))))

(main)


