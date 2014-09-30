
<h3 style="padding: 0px; margin: 24px 0px 8px; font-size: 24px; line-height: 24px; border-bottom-width: 1px; border-bottom-style: solid; border-bottom-color: rgb(170, 170, 170); font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; background-color: rgb(241, 242, 243);">Homework 1: Warm Up</h3>
<span class="assignment_due" style="margin: -32px 0px 0px; line-height: 24px; font-size: 16px; float: right; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; background-color: rgb(241, 242, 243);">due on&nbsp;<time class="due_time" datetime="2014-09-21T23:59:59+08:00" style="font-weight: bold;">2014-09-21 23:59 UTC+8</time></span><a class="assignment_ref" href="http://tcloud.sjtu.edu.cn/course/se106/2014/assignments/homework1/homework1.zip" style="color: rgb(0, 0, 0); font-weight: bold; text-decoration: none; outline-style: none; display: block; float: right; padding: 8px 16px; line-height: 20px; font-size: 18px; margin: 8px; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; background: rgb(204, 204, 204);">Download Starter Files</a><br style="font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);">
<div class="in" style="margin: 0px 0px 0px 16px; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);">
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Introduction</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">For all labs and homework, we will use Stanford C++ Libraries. You can get online and offline documentation from our site.</p>
<p style="margin: 8px 0px;">If you have any questions about this course or homework, feel free to post them on our&nbsp;<a href="http://tcloud.sjtu.edu.cn/course/se106/2014/qa/" style="color: rgb(34, 102, 187); font-weight: bold; text-decoration: none; outline-style: none;">Q&amp;A forum</a>. You are also encouraged to share your knowledge and help others in the Q&amp;A forum. And your can check your assignment grade on our&nbsp;<a href="http://tcloud.sjtu.edu.cn/course/se106/2014/grade/" style="color: rgb(34, 102, 187); font-weight: bold; text-decoration: none; outline-style: none;">Grade System</a></p>
<p style="margin: 8px 0px;">In homework1, you will implement three methods using the API provided by the library. With the help of the library, you only need to write a few lines to complete the following tasks.</p>
<p style="margin: 8px 0px;">Note: You only need to modify&nbsp;<code>TryTokenScanner.h</code>&nbsp;and&nbsp;<code>TryTokenScanner.cpp</code>.</p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Part I: allTokens</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;"><code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">Vector&lt;string&gt; TryTokenScanner::allTokens(string text);</code></p>
<p style="margin: 8px 0px;">Implement allTokens method. This method should accepts a string and return its token list. You can get tokens by calling<code>TokenScanner::nextToken()</code>&nbsp;repeatedly until it reaches the end of the string.</p>
<p style="margin: 8px 0px;">For example, input&nbsp;<code>"Hello world!"</code>; It should return&nbsp;<code>{"Hello", " ", "world", "!"}</code>.</p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Part II: noWhiteSpaces</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;"><code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">Vector&lt;string&gt; TryTokenScanner::noWhitespaces(string text);</code></p>
<p style="margin: 8px 0px;">Implement TryTokenScanner method. This method should accepts a string and return its token list. This time, whitespaces are not taken as tokens and thus should be ignored. You may remove whitespace tokens from the token list returned by&nbsp;<code>allTokens()</code>&nbsp;you implemented, or find an API from&nbsp;<code>TokenScanner</code>&nbsp;to let the scanner ignore whitespaces during its parsing. Be care that whitespaces include space, tab and newline if you choose to remove whitespaces from the token list by yourself.</p>
<p style="margin: 8px 0px;">For example, input&nbsp;<code>"Hello !\nWorld!"</code>; It should return&nbsp;<code>{"Hello", "!", "World", "!"}</code>.</p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Part III: noComments</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;"><code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">Vector&lt;string&gt; TryTokenScanner::noComments(string text);</code></p>
<p style="margin: 8px 0px;">This method should accepts a string and return its token list. C style comments (and the content commented out) are not taken as tokens and thus should be ignored. You should use an API from TokenScanner to let the scanner ignore comments during its parsing.</p>
<p style="margin: 8px 0px;">For example, input&nbsp;<code>"Hello/* World */!"</code>, it should return&nbsp;<code>{"Hello", "!"}</code>.</p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Score</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">Final score according to ./Warmup<br>full score is 3, delay commit will lose score.</p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Hand in</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">You only need to turn in your&nbsp;<code>TryTokenScanner.cpp</code>&nbsp;and&nbsp;<code>Tokenscanner.h</code>&nbsp;file in a package. Do NOT turn in other files or folders. For this assignment, you should turn in via:</p>
<p style="margin: 8px 0px;"><code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">ftp://public.sjtu.edu.cn/upload/homework1/<br>Username: azard5, Password: public<br>example filename: 5130379001_homework1.zip</code></p>
<p style="margin: 8px 0px;">You should always submit&nbsp;<code>TryTokenScanner.h</code>, even if you didn't modify it.</p>
<p style="margin: 8px 0px;">If you have any question or problem about this assignment or your grade, contact with&nbsp;<a href="mailto:azardf4yy@gmail.com" style="color: rgb(34, 102, 187); font-weight: bold; text-decoration: none; outline-style: none;">azardf4yy@gmail.com</a></p>
</div>
</div>
