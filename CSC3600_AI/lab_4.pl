%ground fact for arc/2

% light green line
arc(hang_tuah_light_green, imbi).
arc(imbi,bukit_bintang_light_green).
arc(bukit_bintang_light_green,raja_chulan).


% dark green line
arc(merdeka,bukit_bintang_dark_green).
arc(bukit_bintang_dark_green,trx_dark_green).
arc(trx_dark_green,cochrane).
arc(cochrane,maluri_dark_green).
arc(maluri_dark_green,aman_pertama).
arc(aman_pertama,taman_midah).
arc(taman_midah,taman_mutiara).

% yellow line
arc(trx_yellow,chan_sow_lin_yellow).

% orange line
arc(plaza_rakyat_orange,hang_tuah_orange).
arc(hang_tuah_orange,pudu_orange).
arc(pudu_orange,chan_sow_lin_orange).
arc(chan_sow_lin_orange,miharja).
arc(miharja,maluri_orange).

% maroon line
arc(plaza_rakyat_maroon,hang_tuah_maroon).
arc(hang_tuah_maroon,pudu_maroon).
arc(pudu_maroon,chan_sow_lin_maroon).
arc(chan_sow_lin_maroon,cheras).

% rule for connected/2
connected(A,B):-
( arc(A,B);arc(B,A) ),A\=B.

% rule for reachable/2
reachable(A,B):-
arc(A,B).

reachable(A,C):-
arc(A,B),reachable(B,C).
