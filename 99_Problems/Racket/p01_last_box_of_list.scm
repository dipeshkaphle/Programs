#lang racket
(define last-box
  (
   lambda (lst)
   (
	match lst
	[(cons x '()) x]
	[_ (last-box (cdr lst))]
	)
   ))

(printf "last: ~a\n" (last-box '(1 2 3 4 5)))
