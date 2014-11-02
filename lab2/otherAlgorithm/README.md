Dynamic programming based on connectivity compressed state.
==

city_7_ctdp.cpp
--



Compressed state:

> 0 represents 1
<br>1 represents 2 not link 1 
<br>2 represents 2 link 1
<br>3 represents 3 link 1 but not link 2
<br>4 represents 3 link 2 but not link 1
<br>5 represents 3 neither link 1 nor 2
<br>6 represents 3 link both 1 and 2



Save the state int 7-ary

Use the space about 7^n*n

If n = 8 the 7^8*8=46 118 408

And n=9 the  7^9*9 = 363 182 463

So this program can just caculate the city size bellow 8*m (m can be any positive integer less than 0x7fffffff)



time=k*max{m,n}+b

k is proportional to (7^min{m,n}*min{m,n})



------------------------------------------------------------------------------------------------



city_6_ctdp_nopath.cpp
--

Recently I found another way to save the state

> 0 represents 1
<br>1 represents 2 who's back isn't 1 
<br>2 represents 2 who's back is 1
<br>3 represents 3 who's back is 1
<br>4 represents 3 who's back is 2
<br>5 represents 3 who's back is neither 1 nor 2



In this way the space will be 6^n*n (6^9*9 = 90 699 264),while 10*m is still not available(6^10*10 = 604 661 760)

The program can be more faster and use less space theoretically, but my program actually running speed seems that the 7 ^ n * n efficiency program use less time than the 6 ^ n * n the efficiency program. I guess it might because of treating different state transition caused.

And I found that my computer does not have enough space to run 6 ^ 9 * 9 * m of magnitude program with the path saved.It's no problem to run without path saving.





------------------------------------------------------------------------------------------------

I haven't write any pruning code in these code but I think it will have some way to pruning , which can't improved code efficiency.



> Time=k*max{m,n}+b (k is proportional to (6^min{m,n}*min{m,n}))
<br>Time(min{m,n}=7)=0.07*max{m,n}-0.15 (s)
<br>Time(min{m,n}=8)=0.5*max{m,n}-1.5 (s)
<br>Time(min{m,n}=9)=3*max{m,n}-8 (s)



---



city_combine.cpp
--

A combination of pruning enumeration and dynamic programming algorithm.

While min{m,n}<=8 use dynamic programming algorithm

else use pruning enumeration. Then I set Initial expectations=2.25*m*n that 10*10 can run out in 0.9s.

Still using 2.3 to prune [The right value should be 2.4 but it is too slow.]



---



Reference:

["Dynamic programming problems based on connectivity compressed statewrite"——write  by Chen Danqi](http://wenku.baidu.com/view/4fe4ac659b6648d7c1c74633.html)



> Written with [StackEdit](https://stackedit.io/).



