https://cdn.intra.42.fr/pdf/pdf/19989/en.subject.pdf

## Implemented algorithm

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

## NEW
IDEAL POSITION: Relative to following or following value depending on longest sorted chain.

Each time wanting to use ra, rra or sa check if rr or rrr or ss could be used instead to sort b at same time

0. If all ordered -> shortest path to correct place (ra || rra)
1. Top b value can be inserted in ideal position -> pa else if a ordered goto ideal pos for b
2. If no longest chain exists -> sa if ideal else pb
3. If inside longest chain:
* goto fastest exit of longest chain
4. If outside longest chain 
* sa if ideal pos next to longest chain
* else pb
