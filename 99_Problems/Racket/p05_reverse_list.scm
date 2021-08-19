#lang racket

(define rev-list
  (
   lambda (lst)
   (
	match lst
	['()  '()]
	[(cons x y)  (append (rev-list y) (cons x '()))]
	)
   ))
(printf "~a" (rev-list '(1 2 3 4 5 )))
