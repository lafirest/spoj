-module(prog).
-export([main/0]).
main()->{ok,[N]}=io:fread("","~d"),l(N).
l(0)->ok;l(N)->{ok,[X]}=io:fread("","~d"),<<Y:14,M:4,D:5>>= <<(X):23>>,io:format("~p ~s ~p~n",[D,element(M,{"January","February","March","April","May","June","July","August","September","October","November","December"}),Y]),l(N-1).
