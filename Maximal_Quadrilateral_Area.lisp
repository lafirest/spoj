;;;由于四边形都有不稳定性,所以对于任意的四边形,把它变成圆内接四边形,这样会得到最大面积 
;;;圆内接四边形的面积公式可以利用海伦公式的推广形式:
;;;Area＝sqrt((p-a)*(p-b)*(p-c)*(p-d)),(p=(a+b+c+d)/2)
;;;需要注意精度必须是double,否则不能AC
(setf *read-default-float-format* 'long-float)
(dotimes (_ (read))
  (let* ((a (read))
         (b (read))
         (c (read))
         (d (read))
         (p (/ (+ a b c d) 2))
         (s (sqrt (* (- p a) (- p b) (- p c) (- p d)))))
    (format t "~,2F~%" s)))

