%start with small letter - constant; start with capital letter - variable
father(X,Y) :-
parent(X,Y),
male(X).

mother(X,Y) :-
parent(X,Y),
female(X).

son(X,Y) :- 
parent(Y,X),
male(X).

daughter(X,Y) :- 
parent(Y,X),
female(X).

sibling(X,Y) :- 
 parent(Z,X),
parent(Z,Y).

grandfather(X,Y) :- 
male(X),
parent(X,Z),
parent(Z,Y).

grandmother(X,Y) :- 
female(X),
parent(X,Z),
parent(Z,Y).

great-grandfather(X, Y):- 
male(X), 
father(X, A), 
father(A, B), 
parent(B, Y).

great-great-grandfather(X, Y):-
 male(X), 
father(X, A), 
father(A, B), 
father(B, C), 
parent(C, Y).


parent(f_ggpa, f_grandpa).
parent(f_ggmom, f_grandpa).
parent(f_gggpa, f_ggpa).
parent(f_gggmom, f_ggpa).
parent(m_ggpa, m_grandpa).
parent(m_ggmom, m_grandpa).
parent(m_gggpa, m_ggpa).
parent(m_gggmom, m_ggpa).
parent(f_grandpa, chew_mc).
parent(f_grandmom, chew_mc).
parent(m_grandpa, lim_sc).
parent(m_grandmom, lim_sc).
parent(chew_mc, chew_sl).
parent(chew_mc, chew_jh).
parent(chew_mc, chew_jl).
parent(chew_mc, me).
parent(lim_sc, chew_sl).
parent(lim_sc, chew_jh).
parent(lim_sc, chew_jl).
parent(lim_sc, me).

male(chew_mc).
male(chew_jh).
male(chew_jl).
male(f_grandpa).
male(m_grandpa).
male(f_ggpa).
male(f_gggpa).
male(m_ggpa).
male(m_gggpa).

female(f_ggmom).
female(f_gggmom).
female(m_ggmom).
female(m_gggmom).
female(lim_sc).
female(chew_sl).
female(me).
female(f_grandmom).
female(m_grandmom).


% Q5
element(X,[X|Y]).
element(X,[_|Y]):-element(X,Y).

ancestor(Y, X, [Y|L]) :- 
    parent(Y, X), 
    ancestor(Y, X, L).
ancestor(Y, X, [Y]) :- 
    parent(Y, X).
ancestor(Y, X, L) :- 
    parent(Z, X), 
    ancestor(Y, Z, L), 
    Y \= Z.