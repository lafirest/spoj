;;;这边的想法是排序,然后从大往小开始扣血量
;;;然后看是否都能活下来
(defun insert (item lst acc)
  (if (endp lst)
    (reverse (cons item acc))
    (let ((head (car lst)))
      (if (>= item head)
        (append (reverse acc) (cons item lst))
        (insert item (cdr lst) (cons head acc))))))


(defun calc (heros tower damage) 
  (if (zerop tower)
    t
    (let ((hp (car heros)))
      (if (<= hp damage)
        nil
        (calc (insert (- hp damage) (cdr heros) nil) (1- tower) damage)))))

(calc '(800 800 801 200 200 200) 5 400)
