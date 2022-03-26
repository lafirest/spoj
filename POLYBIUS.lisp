(defvar m (make-array 26 :initial-contents '(11 12 13 14 15 21 22 23 24 24 25 31 32 33 34 35 41 42 43 44 45 51 52 53 54 55)))
(loop repeat (read) for x = (read-line) do(loop for i across x unless (char-equal i #\ ) collect (aref m (- (char-code i) 65)) into y finally (format t "~{~A~^ ~}~%" y)))
