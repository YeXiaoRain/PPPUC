
<h3 style="padding: 0px; margin: 24px 0px 8px; font-size: 24px; line-height: 24px; border-bottom-width: 1px; border-bottom-style: solid; border-bottom-color: rgb(170, 170, 170); font-family: 'Heiti SC', ºÚÌå-¼ò, 'MS Yahei', Î¢ÈíÑÅºÚ, STXihei, »ªÎÄÏ¸ºÚ, 'WenQuanYi ZenHei', ÎÄÈªæäÕýºÚÌå, Sans-sarif; background-color: rgb(241, 242, 243);">Homework 7: RPN</h3>
<span class="assignment_due" style="margin: -32px 0px 0px; line-height: 24px; font-size: 16px; float: right; font-family: 'Heiti SC', ºÚÌå-¼ò, 'MS Yahei', Î¢ÈíÑÅºÚ, STXihei, »ªÎÄÏ¸ºÚ, 'WenQuanYi ZenHei', ÎÄÈªæäÕýºÚÌå, Sans-sarif; background-color: rgb(241, 242, 243);">due on&nbsp;<time class="due_time" datetime="2014-11-5T23:59:59+08:00" style="font-weight: bold;">2014-11-5 23:59 UTC+8</time></span><a class="assignment_ref" href="http://tcloud.sjtu.edu.cn/course/se106/2014/assignments/homework7/homework7.zip" style="color: rgb(0, 0, 0); font-weight: bold; text-decoration: none; outline-style: none; display: block; float: right; padding: 8px 16px; line-height: 20px; font-size: 18px; margin: 8px; font-family: 'Heiti SC', ºÚÌå-¼ò, 'MS Yahei', Î¢ÈíÑÅºÚ, STXihei, »ªÎÄÏ¸ºÚ, 'WenQuanYi ZenHei', ÎÄÈªæäÕýºÚÌå, Sans-sarif; background: rgb(204, 204, 204);">Download Starter Files</a><br style="font-family: 'Heiti SC', ºÚÌå-¼ò, 'MS Yahei', Î¢ÈíÑÅºÚ, STXihei, »ªÎÄÏ¸ºÚ, 'WenQuanYi ZenHei', ÎÄÈªæäÕýºÚÌå, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);">
<p style="margin: 8px 0px; font-family: 'Heiti SC', ºÚÌå-¼ò, 'MS Yahei', Î¢ÈíÑÅºÚ, STXihei, »ªÎÄÏ¸ºÚ, 'WenQuanYi ZenHei', ÎÄÈªæäÕýºÚÌå, Sans-sarif; font-size: 16px; line-height: normal; color: red; background-color: rgb(241, 242, 243);"><strong>2014/10/28 16:30: score.sh in Starter Files update</strong></p>
<div class="in" style="margin: 0px 0px 0px 16px; font-family: 'Heiti SC', ºÚÌå-¼ò, 'MS Yahei', Î¢ÈíÑÅºÚ, STXihei, »ªÎÄÏ¸ºÚ, 'WenQuanYi ZenHei', ÎÄÈªæäÕýºÚÌå, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);">
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Introduction</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">In homework 7, you need write a program that reads expressions from the user in their standard mathematical from and then writes out those same expressions using&nbsp;<strong>Reverse Polish Notation</strong>.<br>This homework is same as&nbsp;<strong>PAC Chapter 7 Exercise 7 in page759</strong>, you can download this book from&nbsp;<i>Info</i>&nbsp;at our course website.
<p style="margin: 8px 0px; color: red;"><strong>Use Expression Trees to Solve This Homework</strong></p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Specification</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">For example, if user input<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">1 + 2 + 3</code>your program should return<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">1 2 + 3 +</code>
<p style="margin: 8px 0px; color: red;"><strong>Be careful aboout white-space between every number and symbol.</strong></p>
Our test input have white-space, and your output also need white-space.<br>Another example input is<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">( 2 * x + 3 * y ) / 10</code>And output is<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">2 x * 3 y * + 10 /</code>When input<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">quit</code>program should exit.<br><strong>Hint:&nbsp;</strong>bracket is a hard problem, be careful about it.</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Test</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">Enter to console:<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">./score.sh</code>to show your score, and this test is our final test.<br>There are three test files and each is 10 point, so total point is 30.</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Socre</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">You will get full credit if you pass&nbsp;<i>score.sh</i>&nbsp;and use expression trees.</p>
<p style="margin: 8px 0px;"><strong>TA will view your code.</strong></p>
<p style="margin: 8px 0px;">Late committing will be punished</p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Hand in</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">If you add other source code file, remember to modify Makefile</p>
<p style="margin: 8px 0px;">Enter:</p>
<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">make handin</code>ensure your computer install zip, maybe you need use:<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">sudo apt-get install zip</code>And modify generated&nbsp;<strong>.zip</strong>&nbsp;file's name to your own student number.<br>That means you only need to submit source code and Makefile file, exclude test file.
<p style="margin: 8px 0px;">Submit your to</p>
<p style="margin: 8px 0px;"><code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">ftp://public.sjtu.edu.cn/upload/homework7/<br>Username: azard5, Password: public<br>Filename: 5130379001_homework7.zip</code></p>
<p style="margin: 8px 0px;">If you have any question or find some bugs, please ask on QA or contact&nbsp;<a href="mailto:azardf4yy@gmail.com" style="color: rgb(34, 102, 187); font-weight: bold; text-decoration: none; outline-style: none;">azardf4yy@gmail.com</a></p>
</div>
<time class="assigned_time" datetime="2014-10-27T23:59:59+08:00" style="text-align: right; display: block;">2014-10-27</time></div>

