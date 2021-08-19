#lang racket

(define last-but-one
  (
   lambda (lst)
   (
	match lst
	[(cons x (cons y '())) (cons x y)]
	[_ (last-but-one (cdr lst))]
	)
   ))

(printf "~a\n" (last-but-one '(1 2 3 4 5)))
