
<h3 style="padding: 0px; margin: 24px 0px 8px; font-size: 24px; line-height: 24px; border-bottom-width: 1px; border-bottom-style: solid; border-bottom-color: rgb(170, 170, 170); font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; background-color: rgb(241, 242, 243);">Homework 6: Hash</h3>
<span class="assignment_due" style="margin: -32px 0px 0px; line-height: 24px; font-size: 16px; float: right; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; background-color: rgb(241, 242, 243);">due on&nbsp;<time class="due_time" datetime="2014-10-29T23:59:59+08:00" style="font-weight: bold;">2014-10-29 23:59 UTC+8</time></span><br style="font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);">
<div class="in" style="margin: 0px 0px 0px 16px; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);">
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Introduction</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">In homework 6, you are expected to finish a small test with your own hash table</p>
<p style="margin: 8px 0px; color: red;"><strong>Using STL function is not allowed in this homework</strong></p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Specification</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">There is a string contains some ASCII characters</p>
<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">abs!ab12~</code>
<p style="margin: 8px 0px;">Your job is to find the first character that occurs exactly once and output the character. You can output "None" if there is no such character in the string.</p>
<p style="margin: 8px 0px;"></p>
<p style="margin: 8px 0px;">For instance, your program should output the character<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">s</code>for the string showed above<br><br></p>
<p style="margin: 8px 0px;">In this homework, you are asked to read test cases from a file named "hash.in" and output the result to a file named "hash.out"</p>
<p style="margin: 8px 0px;">The first line of "hash.in" is a number representing the number of test cases. Every line follwing is a test case</p>
<p style="margin: 8px 0px;">For example</p>
<p style="margin: 8px 0px;"><strong>Input</strong></p>
<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">4<br>g21094t2abag!<br>as!!24sbalkjlj<br>aabbccdd<br>012345<br></code>
<p style="margin: 8px 0px;"><strong>Output</strong></p>
<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">1<br>2<br>None<br>0<br></code></div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Hints</h4>
<div class="in" a="" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">1. You&nbsp;<strong>don't</strong>&nbsp;have to implement a general hash table using template. A naive one for ASCII characters is enough.</p>
<p style="margin: 8px 0px;">2. The time complexity for each test case should be O(n)(n is the length of the string)</p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Test</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">You have to construct your own input and test by yourself.</p>
<p style="margin: 8px 0px;">The input of string will only contains ASCII character.</p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Socre</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">You will get full credit if you implement your own hash table and pass our test cases</p>
<p style="margin: 8px 0px;">Late committing will be punished</p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Hand in</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">You only need to turn in your source file.</p>
<p style="margin: 8px 0px;">Submit your file to</p>
<p style="margin: 8px 0px;"><code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">ftp://public.sjtu.edu.cn/upload/homework6/<br>Username: azard5, Password: public<br>Filename: 5130379001_hash.cpp</code></p>
<p style="margin: 8px 0px;">If you have any question, please contact&nbsp;<a href="mailto:frankfzw@sjtu.edu.cn" style="color: rgb(34, 102, 187); font-weight: bold; text-decoration: none; outline-style: none;">frankfzw@sjtu.edu.cn</a></p>
</div>
<time class="assigned_time" datetime="2014-09-23T23:59:59+08:00" style="text-align: right; display: block;">2014-09-23</time></div>
