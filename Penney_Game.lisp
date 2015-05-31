;;;这道题可以使用hash、rttree,最快的应该是后缀树
(defvar hash (make-hash-table :test 'equal))

(defun count-str(str)
  (mapcar #'(lambda(e) (setf (gethash e hash) 0))
          '("TTT" "TTH" "THT" "THH" "HTT" "HTH" "HHT" "HHH"))
  (loop for x from 0 to (- (length str) 3)
        do (incf (gethash (subseq str x (+ x 3)) hash)))
  (loop for x being the hash-value in hash
        do(format t "~A " x))
  (format t "~%"))

(dotimes (x (read))
  (format t "~A " (read))
  (count-str (read-line)))

