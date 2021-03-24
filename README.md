https://cdn.intra.42.fr/pdf/pdf/19989/en.subject.pdf

## First algorithm

IDEAL POSITION: Relative to following value depending on longest sorted chain.

0. If all ordered -> shortest path to correct place (ra || rra)
1. Top b value can be inserted in ideal position -> pa else goto ideal pos
2. top < top - 1 
- If outside longest chain -> opposite direction longest sorted chain (ra || rra)
- If inside longest chain -> direction closest longest chain exit
- If all ordered -> set ideal value for top b
3. top > top - 1
- sa if it orders all
- pb if following value is not ideal one
- else rra

## Second algorithm
IDEAL POSITION: Relative to following or following value depending on longest sorted chain.

Each time wanting to use ra, rra or sa check if rr or rrr or ss could be used instead to sort b at same time
-> if topb < topb - 1 -> ss (because b gets inserted inversely into a must ideally be inversed)
-> if b is ordered but not ideally rr or rrr until ideal position

0. If all ordered -> shortest path to correct place (ra || rra)
1. Top b value can be inserted in ideal position -> pa else if a ordered goto ideal pos for b
2. If no longest chain exists -> sa if ideal else pb
3. If inside longest chain:
* goto fastest exit of longest chain
4. If outside longest chain 
* sa if ideal pos next to longest chain
* else pb

## Third algorithm
IDEAL POSITION: Relative to following or following value depending on longest sorted chain.
ORDERED: All values in correct position relative to each other but not relative to stack itself

Each time wanting to use rb, rrb or sb check if rr or rrr or ss could be used instead to sort b at same time
-> if a top > top -1 -> ss
-> if next smallest value is in direction ra and rb is used -> rr
-> if next smallest value is in direction rra and rrb is used -> rrr

0. Check if goal is completed (goal is pb smallest value after potentially having pb second smallest values)-> if it is perform operations related to resorting b
1. If a ordered and b empty -> shortest path to correct place (ra || rra)
2. if a ordered b no empty -> goto ideal pa position
3. If sa created ordered stack -> sa
4. Fill stack b
* If b == 0 fill it with smallest value
* If top a is ideal for b -> pb
* If top a is second smallest value in stack a -> pb
* Else goto ideal position in a for next b

## Final algorithm
Base algorithm for small stack size:

* If a is ordered ra/rra until ideally sorted.
* If b is ordered rb/rrb until ideally sorted.
* If s creates ideal order in a or b -> sa/sb

Quicksort algorithm:

1. Makes median of upper partition (intially whole stack a == partition 0). Moves values under median to stack b. Continues doing the median algorithm until 2 values are left or values left are sorted, each time the median algorithm is reused values are pushed to a higher partition in b.
1. B takes median upper partition and moves values above or equal to median to stack a. Continues doing this until b is empty, if two values are left it will sort them if necessary with s.
3. A does the same thing pushing back to B who will push back to A, until A is all sorted.


