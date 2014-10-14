
<h3 style="padding: 0px; margin: 24px 0px 8px; font-size: 24px; line-height: 24px; border-bottom-width: 1px; border-bottom-style: solid; border-bottom-color: rgb(170, 170, 170); font-family: 'Heiti SC', ºÚÌå-¼ò, 'MS Yahei', Î¢ÈíÑÅºÚ, STXihei, »ªÎÄÏ¸ºÚ, 'WenQuanYi ZenHei', ÎÄÈªæäÕýºÚÌå, Sans-sarif; background-color: rgb(241, 242, 243);">Homework 4: K Queens</h3>
<span class="assignment_due" style="margin: -32px 0px 0px; line-height: 24px; font-size: 16px; float: right; font-family: 'Heiti SC', ºÚÌå-¼ò, 'MS Yahei', Î¢ÈíÑÅºÚ, STXihei, »ªÎÄÏ¸ºÚ, 'WenQuanYi ZenHei', ÎÄÈªæäÕýºÚÌå, Sans-sarif; background-color: rgb(241, 242, 243);">due on&nbsp;<time class="due_time" datetime="2014-10-15T23:59:59+08:00" style="font-weight: bold;">2014-10-15 23:59 UTC+8</time></span><a class="assignment_ref" href="http://tcloud.sjtu.edu.cn/course/se106/2014/assignments/homework4/HW4.zip" style="color: rgb(0, 0, 0); font-weight: bold; text-decoration: none; outline-style: none; display: block; float: right; padding: 8px 16px; line-height: 20px; font-size: 18px; margin: 8px; font-family: 'Heiti SC', ºÚÌå-¼ò, 'MS Yahei', Î¢ÈíÑÅºÚ, STXihei, »ªÎÄÏ¸ºÚ, 'WenQuanYi ZenHei', ÎÄÈªæäÕýºÚÌå, Sans-sarif; background: rgb(204, 204, 204);">Download Start File</a><a class="assignment_ref" href="http://tcloud.sjtu.edu.cn/course/se106/2014/assignments/homework4/TestData.tar.gz" style="color: rgb(0, 0, 0); font-weight: bold; text-decoration: none; outline-style: none; display: block; float: right; padding: 8px 16px; line-height: 20px; font-size: 18px; margin: 8px; font-family: 'Heiti SC', ºÚÌå-¼ò, 'MS Yahei', Î¢ÈíÑÅºÚ, STXihei, »ªÎÄÏ¸ºÚ, 'WenQuanYi ZenHei', ÎÄÈªæäÕýºÚÌå, Sans-sarif; background: rgb(204, 204, 204);">Download test data</a>
<div class="in" style="margin: 0px 0px 0px 16px; font-family: 'Heiti SC', ºÚÌå-¼ò, 'MS Yahei', Î¢ÈíÑÅºÚ, STXihei, »ªÎÄÏ¸ºÚ, 'WenQuanYi ZenHei', ÎÄÈªæäÕýºÚÌå, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);">
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Introduction</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">The K-queens problem is the problem of positioning K Queens on an M x N chess board such that no queen attacks another (i.e. they do not share the same row, column, or diagonal).</p>
<p style="margin: 8px 0px;">In this problem, you will be given a M x N chess board, and you should figure out the Maximum value K that satisfy "K-Queens" problem.</p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Requirement</h4>
<p style="margin: 8px 0px;">Your task is to write a function "KQueens" that accept 1 argument (i.e. Chessboard) and return the maximum K, where we have M,N &gt;= 1</p>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">int KQueens(Chessboard *c);</p>
</div>
<p style="margin: 8px 0px;">Your function should also modify the chessboard information to the status where K queens are all placed safely.</p>
<p style="margin: 8px 0px;">Example:</p>
<p style="margin: 8px 0px;">If input chessboard is 4 * 6, than the function returns 4, and the chessboard may look like this(there may be other placement solutions):</p>
<p style="margin: 8px 0px;">.Q....</p>
<p style="margin: 8px 0px;">...Q..</p>
<p style="margin: 8px 0px;">Q.....</p>
<p style="margin: 8px 0px;">..Q...</p>
<p style="margin: 8px 0px;">You should use recursive function in your program.</p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px; font-family: 'Heiti SC', ºÚÌå-¼ò, 'MS Yahei', Î¢ÈíÑÅºÚ, STXihei, »ªÎÄÏ¸ºÚ, 'WenQuanYi ZenHei', ÎÄÈªæäÕýºÚÌå, Sans-sarif; background-color: rgb(241, 242, 243);">Hand in</h4>
<div class="in" style="margin: 0px 0px 0px 16px; font-family: 'Heiti SC', ºÚÌå-¼ò, 'MS Yahei', Î¢ÈíÑÅºÚ, STXihei, »ªÎÄÏ¸ºÚ, 'WenQuanYi ZenHei', ÎÄÈªæäÕýºÚÌå, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);">
<p style="margin: 8px 0px;">You should only commit&nbsp;<code>KQueens.cpp</code>, rename&nbsp;<code>[student_number]_KQueens.cpp</code></p>
<p style="margin: 8px 0px;"><code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">ftp://public.sjtu.edu.cn/upload/homework4/<br>Username: azard5, Password: public<br>Filename: 5130379001_KQueens.cpp&nbsp;<em style="color: gray;">...</em></code></p>
</div>
<time class="assigned_time" datetime="2013-10-13T20:00:00+08:00" style="text-align: right; display: block; font-family: 'Heiti SC', ºÚÌå-¼ò, 'MS Yahei', Î¢ÈíÑÅºÚ, STXihei, »ªÎÄÏ¸ºÚ, 'WenQuanYi ZenHei', ÎÄÈªæäÕýºÚÌå, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);">2015-10-09</time>

